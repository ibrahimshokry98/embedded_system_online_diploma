/*
 * main.c
 *
 * Created: 6/29/2023 11:44:41 AM
 *  Author: Shokry
 */ 


#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_Types.h"
#include "BITMATH.h"
#include "DIO_int.h"
#include "GP_INT_interface.h"
#include "EXT_INT0_interface.h"
#include "EXT_INT1_interface.h"
#include "EXT_INT2_interface.h"

void FUNC0(void);
void FUNC1(void);
void FUNC2(void);

int main(void)
{
	Set_Pin_Direction(PORTD,PIN2,INPUT);
	Set_Pin_Direction(PORTD,PIN3,INPUT);
	Set_Pin_Direction(PORTB,PIN2,INPUT);
	Set_Pin_Direction(PORTD,PIN5,OUTPUT);
	Set_Pin_Direction(PORTD,PIN6,OUTPUT);
	Set_Pin_Direction(PORTD,PIN7,OUTPUT);
	EXT_INT0_CallBack(FUNC0);
	EXT_INT1_CallBack(FUNC1);
	EXT_INT2_CallBack(FUNC2);
	EXT_INT0_SenseControl(Onchange);
	EXT_INT1_SenseControl(FallingEdge);
	EXT_INT2_SenseControl(RisingEdge);
	EXT_INT0_Enable();
	EXT_INT1_Enable();
	EXT_INT2_Enable();
	GP_INT_Enable();
    while(1)
    {
        Set_Pin_Val(PORTD,PIN5,LOW);
		Set_Pin_Val(PORTD,PIN6,LOW);
		Set_Pin_Val(PORTD,PIN7,LOW);
    }
}

void FUNC0(void)
{
	Set_Pin_Val(PORTD,PIN5,HIGH);
	_delay_ms(1000);
}

void FUNC1(void)
{
	Set_Pin_Val(PORTD,PIN6,HIGH);
	_delay_ms(1000);
}

void FUNC2(void)
{
	Set_Pin_Val(PORTD,PIN7,HIGH);
	_delay_ms(1000);
}