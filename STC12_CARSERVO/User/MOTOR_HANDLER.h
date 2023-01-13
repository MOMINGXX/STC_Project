#ifndef	__MOTOR_HANDLER_H__
#define __MOTOR_HANDLER_H__

#include "UART.h"
#include "MOTOR.h"
#include <stdio.h>
#include <string.h>
#include "ULTRASONIC.h"

sbit Key=P3^2;

typedef enum Mode
{
    Ultrasonic_Mode,        //0
    Blue_Mode
}Mode_Init;

#define ULTRASONIC_MODE     ("UTCMODE")
#define BLUE_MODE           ("BLUEMODE")

void Auto_Hand_Mode();
void MOTOR_Blue_Mode();
void Motor_Ultrasonic_Mode();

#endif	/*__MOTOR_HANDLER_H__*/