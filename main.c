//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2012-2015 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
//
// This is part of revision 2.1.2.111 of the EK-TM4C123GXL Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <inc/hw_memmap.h>
#include <inc/hw_types.h>
#include "inc/hw_ints.h"
#include <driverlib/sysctl.h>
#include <driverlib/gpio.h>
#include <driverlib/debug.h>
#include <driverlib/pwm.h>
#include <driverlib/pin_map.h>
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include <inc/hw_gpio.h>
#include "mpu9150.h"
#include "pid.h"


#define PWM_FREQUENCY 300

void init_blinky(){
	    // Enable the GPIO port that is used for the on-board LED.
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	    // Check if the peripheral access is enabled.
	    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)){}

	    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
	    // enable the GPIO pin for digital function.
	    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);
	}

void run_blinky(){
    volatile uint32_t ui32Loop;
    // Loop forever.
    while(1){
        // Turn on the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 2000000; ui32Loop++){}
        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);
        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++){}
    }

}

void init_pwm(){

}

int main(void){
	volatile uint32_t ui32Load;
	volatile uint32_t ui32PWMClock;
	volatile uint32_t ui8Adjust;
	ui8Adjust = 83;

	// Run processesor at 40MHz
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
	// Initialize the UART.
	ConfigureUART();

	// Run PWM clock at 40/64 = 625KHz
	SysCtlPWMClockSet(SYSCTL_PWMDIV_64);
	// Enable PWM1 & GIOP Port D & F
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	// Enable PD0 to be PWM output pin
	GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0);
	GPIOPinConfigure(GPIO_PD0_M1PWM0); // 0x00030005); //GPIO_PD0_M1PWM0

	// Configuring PF0 & 4
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
	GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_DIR_MODE_IN);
	GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

	// 40/64 = 625KHz
	ui32PWMClock = SysCtlClockGet() / 64;
	// COnfigure PWM generator to be 625/55 -1 = 10.36
	ui32Load = (ui32PWMClock / PWM_FREQUENCY) - 1;
	PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);
	PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, ui32Load);

	// 10.36 * 83 to get pulse width of roughly 1.5mS
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);
	PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);
	PWMGenEnable(PWM1_BASE, PWM_GEN_0);

    // Print the welcome message to the terminal.
    UARTprintf("\033[2J Drone_v1\n");

	while(1){
		// altitude estimation/
		// get user input
		// stabalize algorithm

		if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4)==0x00){
			// add debounce
			ui8Adjust--;
			if (ui8Adjust < 430){
				ui8Adjust = 430;
			}
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);
		}
		if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0)==0x00){
			ui8Adjust++;
			if (ui8Adjust > 630){
				ui8Adjust = 630;
			}
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);
		}

		// Print the angular velocities in the table.
        UARTprintf("\033[9;17H%3d", ui8Adjust);

		SysCtlDelay(100000);
	}


}



