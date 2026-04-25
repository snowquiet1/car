/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G351X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G351X
#define CONFIG_MSPM0G3519

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_Motor */
#define PWM_Motor_INST                                                     TIMA0
#define PWM_Motor_INST_IRQHandler                               TIMA0_IRQHandler
#define PWM_Motor_INST_INT_IRQN                                 (TIMA0_INT_IRQn)
#define PWM_Motor_INST_CLK_FREQ                                          4000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_Motor_C0_PORT                                             GPIOA
#define GPIO_PWM_Motor_C0_PIN                                     DL_GPIO_PIN_21
#define GPIO_PWM_Motor_C0_IOMUX                                  (IOMUX_PINCM46)
#define GPIO_PWM_Motor_C0_IOMUX_FUNC                 IOMUX_PINCM46_PF_TIMA0_CCP0
#define GPIO_PWM_Motor_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_Motor_C1_PORT                                             GPIOA
#define GPIO_PWM_Motor_C1_PIN                                     DL_GPIO_PIN_22
#define GPIO_PWM_Motor_C1_IOMUX                                  (IOMUX_PINCM47)
#define GPIO_PWM_Motor_C1_IOMUX_FUNC                 IOMUX_PINCM47_PF_TIMA0_CCP1
#define GPIO_PWM_Motor_C1_IDX                                DL_TIMER_CC_1_INDEX
/* GPIO defines for channel 2 */
#define GPIO_PWM_Motor_C2_PORT                                             GPIOA
#define GPIO_PWM_Motor_C2_PIN                                     DL_GPIO_PIN_10
#define GPIO_PWM_Motor_C2_IOMUX                                  (IOMUX_PINCM21)
#define GPIO_PWM_Motor_C2_IOMUX_FUNC                 IOMUX_PINCM21_PF_TIMA0_CCP2
#define GPIO_PWM_Motor_C2_IDX                                DL_TIMER_CC_2_INDEX
/* GPIO defines for channel 3 */
#define GPIO_PWM_Motor_C3_PORT                                             GPIOA
#define GPIO_PWM_Motor_C3_PIN                                     DL_GPIO_PIN_12
#define GPIO_PWM_Motor_C3_IOMUX                                  (IOMUX_PINCM34)
#define GPIO_PWM_Motor_C3_IOMUX_FUNC                 IOMUX_PINCM34_PF_TIMA0_CCP3
#define GPIO_PWM_Motor_C3_IDX                                DL_TIMER_CC_3_INDEX




/* Defines for QEI_left */
#define QEI_left_INST                                                      TIMG9
#define QEI_left_INST_IRQHandler                                TIMG9_IRQHandler
#define QEI_left_INST_INT_IRQN                                  (TIMG9_INT_IRQn)
/* Pin configuration defines for QEI_left PHA Pin */
#define GPIO_QEI_left_PHA_PORT                                             GPIOA
#define GPIO_QEI_left_PHA_PIN                                      DL_GPIO_PIN_3
#define GPIO_QEI_left_PHA_IOMUX                                   (IOMUX_PINCM8)
#define GPIO_QEI_left_PHA_IOMUX_FUNC                  IOMUX_PINCM8_PF_TIMG9_CCP0
/* Pin configuration defines for QEI_left PHB Pin */
#define GPIO_QEI_left_PHB_PORT                                             GPIOA
#define GPIO_QEI_left_PHB_PIN                                      DL_GPIO_PIN_2
#define GPIO_QEI_left_PHB_IOMUX                                   (IOMUX_PINCM7)
#define GPIO_QEI_left_PHB_IOMUX_FUNC                  IOMUX_PINCM7_PF_TIMG9_CCP1

/* Defines for QEI_right */
#define QEI_right_INST                                                     TIMG8
#define QEI_right_INST_IRQHandler                               TIMG8_IRQHandler
#define QEI_right_INST_INT_IRQN                                 (TIMG8_INT_IRQn)
/* Pin configuration defines for QEI_right PHA Pin */
#define GPIO_QEI_right_PHA_PORT                                            GPIOA
#define GPIO_QEI_right_PHA_PIN                                     DL_GPIO_PIN_1
#define GPIO_QEI_right_PHA_IOMUX                                  (IOMUX_PINCM2)
#define GPIO_QEI_right_PHA_IOMUX_FUNC                 IOMUX_PINCM2_PF_TIMG8_CCP0
/* Pin configuration defines for QEI_right PHB Pin */
#define GPIO_QEI_right_PHB_PORT                                            GPIOA
#define GPIO_QEI_right_PHB_PIN                                    DL_GPIO_PIN_18
#define GPIO_QEI_right_PHB_IOMUX                                 (IOMUX_PINCM40)
#define GPIO_QEI_right_PHB_IOMUX_FUNC                IOMUX_PINCM40_PF_TIMG8_CCP1


/* Defines for Timer_Sound */
#define Timer_Sound_INST                                                 (TIMA1)
#define Timer_Sound_INST_IRQHandler                             TIMA1_IRQHandler
#define Timer_Sound_INST_INT_IRQN                               (TIMA1_INT_IRQn)
#define Timer_Sound_INST_LOAD_VALUE                                     (65499U)




/* Defines for I2C_2 */
#define I2C_2_INST                                                          I2C2
#define I2C_2_INST_IRQHandler                                    I2C2_IRQHandler
#define I2C_2_INST_INT_IRQN                                        I2C2_INT_IRQn
#define I2C_2_BUS_SPEED_HZ                                                100000
#define GPIO_I2C_2_SDA_PORT                                                GPIOB
#define GPIO_I2C_2_SDA_PIN                                         DL_GPIO_PIN_9
#define GPIO_I2C_2_IOMUX_SDA                                     (IOMUX_PINCM26)
#define GPIO_I2C_2_IOMUX_SDA_FUNC                      IOMUX_PINCM26_PF_I2C2_SDA
#define GPIO_I2C_2_SCL_PORT                                                GPIOB
#define GPIO_I2C_2_SCL_PIN                                         DL_GPIO_PIN_8
#define GPIO_I2C_2_IOMUX_SCL                                     (IOMUX_PINCM25)
#define GPIO_I2C_2_IOMUX_SCL_FUNC                      IOMUX_PINCM25_PF_I2C2_SCL



/* Port definition for Pin Group GPIO_GraySensor */
#define GPIO_GraySensor_PORT                                             (GPIOA)

/* Defines for PIN_Left1: GPIOA.0 with pinCMx 1 on package pin 1 */
#define GPIO_GraySensor_PIN_Left1_PIN                            (DL_GPIO_PIN_0)
#define GPIO_GraySensor_PIN_Left1_IOMUX                           (IOMUX_PINCM1)
/* Defines for PIN_Left2: GPIOA.6 with pinCMx 11 on package pin 19 */
#define GPIO_GraySensor_PIN_Left2_PIN                            (DL_GPIO_PIN_6)
#define GPIO_GraySensor_PIN_Left2_IOMUX                          (IOMUX_PINCM11)
/* Defines for PIN_Left3: GPIOA.5 with pinCMx 10 on package pin 18 */
#define GPIO_GraySensor_PIN_Left3_PIN                            (DL_GPIO_PIN_5)
#define GPIO_GraySensor_PIN_Left3_IOMUX                          (IOMUX_PINCM10)
/* Defines for PIN_Left4: GPIOA.4 with pinCMx 9 on package pin 17 */
#define GPIO_GraySensor_PIN_Left4_PIN                            (DL_GPIO_PIN_4)
#define GPIO_GraySensor_PIN_Left4_IOMUX                           (IOMUX_PINCM9)
/* Defines for PIN_Left5: GPIOA.31 with pinCMx 6 on package pin 7 */
#define GPIO_GraySensor_PIN_Left5_PIN                           (DL_GPIO_PIN_31)
#define GPIO_GraySensor_PIN_Left5_IOMUX                           (IOMUX_PINCM6)
/* Defines for PIN_Left6: GPIOA.30 with pinCMx 5 on package pin 5 */
#define GPIO_GraySensor_PIN_Left6_PIN                           (DL_GPIO_PIN_30)
#define GPIO_GraySensor_PIN_Left6_IOMUX                           (IOMUX_PINCM5)
/* Defines for PIN_Left7: GPIOA.29 with pinCMx 4 on package pin 4 */
#define GPIO_GraySensor_PIN_Left7_PIN                           (DL_GPIO_PIN_29)
#define GPIO_GraySensor_PIN_Left7_IOMUX                           (IOMUX_PINCM4)
/* Port definition for Pin Group GPIO_Soundsensor */
#define GPIO_Soundsensor_PORT                                            (GPIOA)

/* Defines for Pin_Trig: GPIOA.9 with pinCMx 20 on package pin 28 */
#define GPIO_Soundsensor_Pin_Trig_PIN                            (DL_GPIO_PIN_9)
#define GPIO_Soundsensor_Pin_Trig_IOMUX                          (IOMUX_PINCM20)
/* Defines for PIN_Echo: GPIOA.28 with pinCMx 3 on package pin 3 */
// pins affected by this interrupt request:["PIN_Echo"]
#define GPIO_Soundsensor_INT_IRQN                               (GPIOA_INT_IRQn)
#define GPIO_Soundsensor_INT_IIDX               (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_Soundsensor_PIN_Echo_IIDX                      (DL_GPIO_IIDX_DIO28)
#define GPIO_Soundsensor_PIN_Echo_PIN                           (DL_GPIO_PIN_28)
#define GPIO_Soundsensor_PIN_Echo_IOMUX                           (IOMUX_PINCM3)


/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_Motor_init(void);
void SYSCFG_DL_QEI_left_init(void);
void SYSCFG_DL_QEI_right_init(void);
void SYSCFG_DL_Timer_Sound_init(void);
void SYSCFG_DL_I2C_2_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
