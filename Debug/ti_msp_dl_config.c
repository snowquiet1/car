/*
 * Copyright (c) 2023, Texas Instruments Incorporated
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
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G351X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerA_backupConfig gPWM_MotorBackup;
DL_TimerG_backupConfig gQEI_rightBackup;
DL_TimerA_backupConfig gTimer_TrackBackup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_PWM_Motor_init();
    SYSCFG_DL_QEI_left_init();
    SYSCFG_DL_QEI_right_init();
    SYSCFG_DL_Timer_Sound_init();
    SYSCFG_DL_Timer_Track_init();
    SYSCFG_DL_I2C_2_init();
    /* Ensure backup structures have no valid state */
	gPWM_MotorBackup.backupRdy 	= false;
	gQEI_rightBackup.backupRdy 	= false;
	gTimer_TrackBackup.backupRdy 	= false;

}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_saveConfiguration(PWM_Motor_INST, &gPWM_MotorBackup);
	retStatus &= DL_TimerG_saveConfiguration(QEI_right_INST, &gQEI_rightBackup);
	retStatus &= DL_TimerA_saveConfiguration(Timer_Track_INST, &gTimer_TrackBackup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_restoreConfiguration(PWM_Motor_INST, &gPWM_MotorBackup, false);
	retStatus &= DL_TimerG_restoreConfiguration(QEI_right_INST, &gQEI_rightBackup, false);
	retStatus &= DL_TimerA_restoreConfiguration(Timer_Track_INST, &gTimer_TrackBackup, false);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_GPIO_reset(GPIOC);
    DL_TimerA_reset(PWM_Motor_INST);
    DL_TimerG_reset(QEI_left_INST);
    DL_TimerG_reset(QEI_right_INST);
    DL_TimerG_reset(Timer_Sound_INST);
    DL_TimerA_reset(Timer_Track_INST);
    DL_I2C_reset(I2C_2_INST);

    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_GPIO_enablePower(GPIOC);
    DL_TimerA_enablePower(PWM_Motor_INST);
    DL_TimerG_enablePower(QEI_left_INST);
    DL_TimerG_enablePower(QEI_right_INST);
    DL_TimerG_enablePower(Timer_Sound_INST);
    DL_TimerA_enablePower(Timer_Track_INST);
    DL_I2C_enablePower(I2C_2_INST);
    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_Motor_C0_IOMUX,GPIO_PWM_Motor_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_Motor_C0_PORT, GPIO_PWM_Motor_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_Motor_C1_IOMUX,GPIO_PWM_Motor_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_Motor_C1_PORT, GPIO_PWM_Motor_C1_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_Motor_C2_IOMUX,GPIO_PWM_Motor_C2_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_Motor_C2_PORT, GPIO_PWM_Motor_C2_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_Motor_C3_IOMUX,GPIO_PWM_Motor_C3_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_Motor_C3_PORT, GPIO_PWM_Motor_C3_PIN);

    DL_GPIO_initPeripheralInputFunction(GPIO_QEI_left_PHA_IOMUX,GPIO_QEI_left_PHA_IOMUX_FUNC);
    DL_GPIO_initPeripheralInputFunction(GPIO_QEI_left_PHB_IOMUX,GPIO_QEI_left_PHB_IOMUX_FUNC);
    DL_GPIO_initPeripheralInputFunction(GPIO_QEI_right_PHA_IOMUX,GPIO_QEI_right_PHA_IOMUX_FUNC);
    DL_GPIO_initPeripheralInputFunction(GPIO_QEI_right_PHB_IOMUX,GPIO_QEI_right_PHB_IOMUX_FUNC);

    
	DL_GPIO_initPeripheralInputFunctionFeatures(
		 GPIO_I2C_2_IOMUX_SDA, GPIO_I2C_2_IOMUX_SDA_FUNC,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
	DL_GPIO_initPeripheralInputFunctionFeatures(
		 GPIO_I2C_2_IOMUX_SCL, GPIO_I2C_2_IOMUX_SCL_FUNC,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_enableHiZ(GPIO_I2C_2_IOMUX_SDA);
    DL_GPIO_enableHiZ(GPIO_I2C_2_IOMUX_SCL);

    DL_GPIO_initDigitalInputFeatures(GPIO_GraySensor_PIN_Left1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_ENABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_GraySensor_PIN_Left2_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_GraySensor_PIN_Left3_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_GraySensor_PIN_Left4_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_GraySensor_PIN_Left5_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_GraySensor_PIN_Left6_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_GraySensor_PIN_Left7_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutputFeatures(GPIO_Soundsensor_Pin_Trig_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_DRIVE_STRENGTH_HIGH, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_Soundsensor_PIN_Echo_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_clearPins(GPIOA, GPIO_Soundsensor_Pin_Trig_PIN);
    DL_GPIO_enableOutput(GPIOA, GPIO_Soundsensor_Pin_Trig_PIN);
    DL_GPIO_setUpperPinsPolarity(GPIOA, DL_GPIO_PIN_28_EDGE_RISE_FALL);
    DL_GPIO_clearInterruptStatus(GPIOA, GPIO_Soundsensor_PIN_Echo_PIN);
    DL_GPIO_enableInterrupt(GPIOA, GPIO_Soundsensor_PIN_Echo_PIN);

}



SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);

    
	DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	/* Set default configuration */
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
    /* INT_GROUP1 Priority */
    NVIC_SetPriority(GPIOA_INT_IRQn, 1);

}


/*
 * Timer clock configuration to be sourced by  / 8 (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   4000000 Hz = 4000000 Hz / (8 * (0 + 1))
 */
static const DL_TimerA_ClockConfig gPWM_MotorClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale = 0U
};

static const DL_TimerA_PWMConfig gPWM_MotorConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN_UP,
    .period = 1000,
    .isTimerWithFourCC = true,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_PWM_Motor_init(void) {

    DL_TimerA_setClockConfig(
        PWM_Motor_INST, (DL_TimerA_ClockConfig *) &gPWM_MotorClockConfig);

    DL_TimerA_initPWMMode(
        PWM_Motor_INST, (DL_TimerA_PWMConfig *) &gPWM_MotorConfig);

    // Set Counter control to the smallest CC index being used
    DL_TimerA_setCounterControl(PWM_Motor_INST,DL_TIMER_CZC_CCCTL0_ZCOND,DL_TIMER_CAC_CCCTL0_ACOND,DL_TIMER_CLC_CCCTL0_LCOND);

    DL_TimerA_setCaptureCompareOutCtl(PWM_Motor_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_0_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_Motor_INST, DL_TIMER_CC_UPDATE_METHOD_COMP_DN_EVT, DL_TIMERA_CAPTURE_COMPARE_0_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_Motor_INST, 0, DL_TIMER_CC_0_INDEX);

    DL_TimerA_setCaptureCompareOutCtl(PWM_Motor_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_1_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_Motor_INST, DL_TIMER_CC_UPDATE_METHOD_COMP_DN_EVT, DL_TIMERA_CAPTURE_COMPARE_1_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_Motor_INST, 0, DL_TIMER_CC_1_INDEX);

    DL_TimerA_setCaptureCompareOutCtl(PWM_Motor_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_2_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_Motor_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_2_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_Motor_INST, 0, DL_TIMER_CC_2_INDEX);

    DL_TimerA_setCaptureCompareOutCtl(PWM_Motor_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_3_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_Motor_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_3_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_Motor_INST, 0, DL_TIMER_CC_3_INDEX);

    DL_TimerA_enableClock(PWM_Motor_INST);


    
    DL_TimerA_setCCPDirection(PWM_Motor_INST , DL_TIMER_CC0_OUTPUT | DL_TIMER_CC1_OUTPUT | DL_TIMER_CC2_OUTPUT | DL_TIMER_CC3_OUTPUT );


}


static const DL_TimerG_ClockConfig gQEI_leftClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale = 0U
};


SYSCONFIG_WEAK void SYSCFG_DL_QEI_left_init(void) {

    DL_TimerG_setClockConfig(
        QEI_left_INST, (DL_TimerG_ClockConfig *) &gQEI_leftClockConfig);

    DL_TimerG_configQEI(QEI_left_INST, DL_TIMER_QEI_MODE_2_INPUT,
        DL_TIMER_CC_INPUT_INV_NOINVERT, DL_TIMER_CC_0_INDEX);
    DL_TimerG_configQEI(QEI_left_INST, DL_TIMER_QEI_MODE_2_INPUT,
        DL_TIMER_CC_INPUT_INV_NOINVERT, DL_TIMER_CC_1_INDEX);
    DL_TimerG_setLoadValue(QEI_left_INST, 65535);
    DL_TimerG_enableClock(QEI_left_INST);
}
static const DL_TimerG_ClockConfig gQEI_rightClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale = 0U
};


SYSCONFIG_WEAK void SYSCFG_DL_QEI_right_init(void) {

    DL_TimerG_setClockConfig(
        QEI_right_INST, (DL_TimerG_ClockConfig *) &gQEI_rightClockConfig);

    DL_TimerG_configQEI(QEI_right_INST, DL_TIMER_QEI_MODE_2_INPUT,
        DL_TIMER_CC_INPUT_INV_NOINVERT, DL_TIMER_CC_0_INDEX);
    DL_TimerG_configQEI(QEI_right_INST, DL_TIMER_QEI_MODE_2_INPUT,
        DL_TIMER_CC_INPUT_INV_NOINVERT, DL_TIMER_CC_1_INDEX);
    DL_TimerG_setLoadValue(QEI_right_INST, 65535);
    DL_TimerG_enableClock(QEI_right_INST);
}



/*
 * Timer clock configuration to be sourced by BUSCLK /  (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   1000000 Hz = 4000000 Hz / (8 * (3 + 1))
 */
static const DL_TimerG_ClockConfig gTimer_SoundClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 3U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * Timer_Sound_INST_LOAD_VALUE = (65.50 ms * 1000000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTimer_SoundTimerConfig = {
    .period     = Timer_Sound_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_ONE_SHOT_UP,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_Timer_Sound_init(void) {

    DL_TimerG_setClockConfig(Timer_Sound_INST,
        (DL_TimerG_ClockConfig *) &gTimer_SoundClockConfig);

    DL_TimerG_initTimerMode(Timer_Sound_INST,
        (DL_TimerG_TimerConfig *) &gTimer_SoundTimerConfig);
    DL_TimerG_enableClock(Timer_Sound_INST);





}

/*
 * Timer clock configuration to be sourced by BUSCLK /  (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   40000 Hz = 4000000 Hz / (8 * (99 + 1))
 */
static const DL_TimerA_ClockConfig gTimer_TrackClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 99U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * Timer_Track_INST_LOAD_VALUE = (10 ms * 40000 Hz) - 1
 */
static const DL_TimerA_TimerConfig gTimer_TrackTimerConfig = {
    .period     = Timer_Track_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC_UP,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_Timer_Track_init(void) {

    DL_TimerA_setClockConfig(Timer_Track_INST,
        (DL_TimerA_ClockConfig *) &gTimer_TrackClockConfig);

    DL_TimerA_initTimerMode(Timer_Track_INST,
        (DL_TimerA_TimerConfig *) &gTimer_TrackTimerConfig);
    DL_TimerA_enableClock(Timer_Track_INST);





}


static const DL_I2C_ClockConfig gI2C_2ClockConfig = {
    .clockSel = DL_I2C_CLOCK_BUSCLK,
    .divideRatio = DL_I2C_CLOCK_DIVIDE_1,
};

SYSCONFIG_WEAK void SYSCFG_DL_I2C_2_init(void) {

    DL_I2C_setClockConfig(I2C_2_INST,
        (DL_I2C_ClockConfig *) &gI2C_2ClockConfig);
    DL_I2C_setAnalogGlitchFilterPulseWidth(I2C_2_INST,
        DL_I2C_ANALOG_GLITCH_FILTER_WIDTH_50NS);
    DL_I2C_enableAnalogGlitchFilter(I2C_2_INST);

    /* Configure Controller Mode */
    DL_I2C_resetControllerTransfer(I2C_2_INST);
    /* Set frequency to 100000 Hz*/
    DL_I2C_setTimerPeriod(I2C_2_INST, 31);
    DL_I2C_setControllerTXFIFOThreshold(I2C_2_INST, DL_I2C_TX_FIFO_LEVEL_EMPTY);
    DL_I2C_setControllerRXFIFOThreshold(I2C_2_INST, DL_I2C_RX_FIFO_LEVEL_BYTES_1);
    DL_I2C_enableControllerClockStretching(I2C_2_INST);


    /* Enable module */
    DL_I2C_enableController(I2C_2_INST);


}

