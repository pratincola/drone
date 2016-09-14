/*
 * pid.c
 *
 *  Created on: Aug 6, 2016
 *      Author: pratik1
 */
#include <stdint.h>
#include "pid.h"

//volatile PID g_sPidState;

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
	void __error__(char *pcFilename, uint32_t ui32Line){}
#endif


void PID_Init(PID *g_sPidState){
	g_sPidState->ui32Error = 0;
	g_sPidState->ui32PrevError = 0;
	g_sPidState->ui32SumError = 0;
	g_sPidState->ui32DefError = 0;
	g_sPidState->ui32Control = 0;
}

void PID_some(void){
/*
 *  Ziegler–Nichols method
 *  Control			Kp		Ti		Td
	P				0.50Ku	-		-
	PI				0.45Ku	Tu/1.2	-
	PD				0.8Ku	-		Tu/8
	classic PID[2]	0.60Ku	Tu/2		Tu/8
	Pessen Integral	0.7Ku	Tu/2.5	-
	some overshoot	0.33Ku 	Tu/2 	Tu/3
	no overshoot[2]	0.2Ku	Tu/2		Tu/3
*/
}


void PID_Update(PID *g_sPidState, uint32_t new_position){

	g_sPidState->ui32Error = new_position - g_sPidState->ui32Position;


	g_sPidState->ui32SumError += g_sPidState->ui32Error;
	// TODO: check for overflow on ui32SumError

	g_sPidState->ui32DefError = g_sPidState->ui32Error - g_sPidState->ui32PrevError;
	// TODO: check for underflow on ui32DefError?

	// Control output
	g_sPidState->ui32Control = g_sPidState->ui32ProportionalGain * g_sPidState->ui32Error +
			g_sPidState->ui32IntegrationGain * g_sPidState->ui32SumError +
			g_sPidState->ui32DerivativeGain * g_sPidState->ui32DefError;

	g_sPidState->ui32PrevError = g_sPidState->ui32Error;
	g_sPidState->ui32Position = new_position;
}

void PID_Update2(PID *g_sPidState, uint32_t new_position, uint32_t dt){

	g_sPidState->ui32Error = new_position - g_sPidState->ui32Position;

	uint32_t p =  g_sPidState->ui32ProportionalGain * g_sPidState->ui32Error;

	g_sPidState->ui32SumError = g_sPidState->ui32SumError + g_sPidState->ui32IntegrationGain * g_sPidState->ui32Error *dt;


	g_sPidState->ui32DefError = g_sPidState->ui32Error - g_sPidState->ui32PrevError;
	uint32_t d =  (g_sPidState->ui32DerivativeGain * g_sPidState->ui32DefError )/dt;


	// Control output
	g_sPidState->ui32Control = p + g_sPidState->ui32SumError + d;

	g_sPidState->ui32PrevError = g_sPidState->ui32Error;
	g_sPidState->ui32Position = new_position;
}

void PID_Update3(PID *g_sPidState, uint32_t new_position, uint32_t dt) {
	uint32_t diff;
	uint32_t p_term;
	uint32_t i_term;
	uint32_t d_term;

	g_sPidState->ui32Error = new_position - g_sPidState->ui32Position;
	// integration with windup guarding
	g_sPidState->ui32SumError += (g_sPidState->ui32Error * dt);
	if (g_sPidState->ui32SumError < -(g_sPidState->ui32WindupGuard)){
			g_sPidState->ui32SumError = -(g_sPidState->ui32WindupGuard);
	}
	else if (g_sPidState->ui32SumError > g_sPidState->ui32WindupGuard){
			g_sPidState->ui32SumError = g_sPidState->ui32WindupGuard;
	}

	// differentiation
	g_sPidState->ui32DefError = ((g_sPidState->ui32Error - g_sPidState->ui32PrevError) / dt);

	// scaling
	p_term = (g_sPidState->ui32ProportionalGain * g_sPidState->ui32Error);
	i_term = (g_sPidState->ui32IntegrationGain  * g_sPidState->ui32SumError);
	d_term = (g_sPidState->ui32DerivativeGain   * g_sPidState->ui32DefError);

	// summation of terms
	g_sPidState->ui32Control = p_term + i_term + d_term;

	// save current error as previous error for next iteration
	g_sPidState->ui32PrevError = g_sPidState->ui32Error;
	g_sPidState->ui32Position = new_position;

}






