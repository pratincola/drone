/*
 * mpu9150.h
 *
 *  Created on: Aug 8, 2016
 *      Author: pratik1
 */

#ifndef MPU9150_H_
#define MPU9150_H_

#include <stdarg.h>

// Define MPU9150 I2C Address.
#define MPU9150_I2C_ADDRESS     0x68
// Global counter to control and slow down the rate of data to the terminal.
#define PRINT_SKIP_COUNT        10

extern void MPU9150AppCallback(void *pvCallbackData, uint_fast8_t ui8Status);
extern void IntGPIOb(void);
extern void MPU9150I2CIntHandler(void);
extern void MPU9150AppErrorHandler(char *pcFilename, uint_fast32_t ui32Line);
extern void MPU9150AppI2CWait(char *pcFilename, uint_fast32_t ui32Line);
extern void ConfigureUART(void);

#endif /* MPU9150_H_ */
