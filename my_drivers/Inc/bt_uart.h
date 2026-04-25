#ifndef BT_UART_H
#define BT_UART_H

#include "ti_msp_dl_config.h"
#include <stdbool.h>

// 定义接收缓冲区的最大长度，64字节足够日常调参使用了
#define BT_RX_MAX_LEN 64

// 声明全局变量，供 main.c 读取
extern char bt_rx_buffer[BT_RX_MAX_LEN]; 
extern volatile bool bt_rx_flag;

// 声明对外提供的 API 函数
void BT_SendString(char *str);

#endif