#include "uart.h"


uint8 String_Buffer [100]= "Learn-In-Depth : Ibrahim Shokry";
void main (void)
{
	Uart_Send_String (String_Buffer);
}