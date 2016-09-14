/*
 * pid.h
 *
 *  Created on: Aug 6, 2016
 *      Author: pratik1
 */

#ifndef PID_H_
#define PID_H_

//*****************************************************************************
//
// Structure typedef to make storing pid state data between runs
//      ui32Error:				actual - set pt
//      ui32PrevError:			previous run's error
//      ui32SumError:			sum of errors so far in the run
//      ui32DefError:			error delta; change in error; difference of errors; error - prev error
//      ui32ProportionalGain:	Kp
//      ui32IntegrationGain:		Ki
//		ui32DerivativeGain:		Kd
//*****************************************************************************
typedef struct {
	uint32_t ui32Position;

	uint32_t ui32Error;
	uint32_t ui32PrevError;

	uint32_t ui32SumError;
	uint32_t ui32DefError;

	uint32_t ui32ProportionalGain;
	uint32_t ui32IntegrationGain;
	uint32_t ui32DerivativeGain;

	uint32_t ui32Control;
	uint32_t ui32WindupGuard;
} PID;


extern void PID_Init(PID *g_sPidState);
extern void PID_Update(PID *g_sPidState, uint32_t new_position);
extern void PID_Update2(PID *g_sPidState, uint32_t new_position, uint32_t dt);
extern void PID_Update3(PID *g_sPidState, uint32_t new_position, uint32_t dt);


#endif /* PID_H_ */
