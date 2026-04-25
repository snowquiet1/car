#include "bt_uart.h"

// 实际存储手机发来数据的数组
char bt_rx_buffer[BT_RX_MAX_LEN];
// 记录当前存到了第几个字节
volatile uint8_t bt_rx_index = 0;
// 接收完成标志位。为 true 时代表收到了一句完整的指令
volatile bool bt_rx_flag = false;

// ---------------------------------------------------------
// 蓝牙发送函数：将一串字符发给手机
// ---------------------------------------------------------
void BT_SendString(char *str) {
    // 只要当前字符不是字符串的结尾标志 '\0'，就一直发
    while (*str != '\0') {
        // 调用底层库，阻塞式发送 1 个字节。UART_BT_INST 是 SysConfig 自动生成的宏
        DL_UART_Main_transmitDataBlocking(UART_BT_INST, *str);
        // 指针后移，准备发下一个字符
        str++;
    }
}

// ---------------------------------------------------------
// 蓝牙接收中断服务函数：系统自动跳转运行
// 注意：函数名 UART_BT_INST_IRQHandler 是 SysConfig 严格规定好的
// ---------------------------------------------------------
void UART_BT_INST_IRQHandler(void) {
    // 获取当前是哪个中断源触发的这个函数
    switch (DL_UART_Main_getPendingInterrupt(UART_BT_INST)) {
        
        // 判断是不是接收 (RX) 中断
        case DL_UART_MAIN_IIDX_RX:
            
            // 从硬件寄存器里把刚收到的 1 个字节读出来
            char ch = DL_UART_Main_receiveData(UART_BT_INST);
            
            // 判断这个字节是不是换行符 '\n' 或者回车符 '\r' (代表手机发完了一句话)
            if (ch == '\n' || ch == '\r' || ch == '@') {
                // 如果之前已经接收到有效字符了
                if (bt_rx_index > 0) {
                    // 在数组最后手动补上一个字符串结尾标志，方便后续进行比对
                    bt_rx_buffer[bt_rx_index] = '\0';
                    // 置位标志位，通知主程序“指令收好了”
                    bt_rx_flag = true;
                    // 清零索引，下一句话重新从数组头部开始存
                    bt_rx_index = 0;
                }
            } 
            // 如果收到的不是换行符，说明是正常的数据内容
            else {
                // 防止手机发来的数据太长导致数组越界引发死机
                if (bt_rx_index < (BT_RX_MAX_LEN - 1)) {
                    // 把字符存进数组，并把索引加 1
                    bt_rx_buffer[bt_rx_index] = ch;
                    bt_rx_index++;
                }
            }
            break;
            
        default:
            break;
    }
}