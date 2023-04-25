/* statrtup.c
Eng.Ibrahim
*/
#include "platforms_types.h"

extern int main(void);
void Reset_Handler () ;
void Default_Handler ()
{
	Reset_Handler();
}
void NMI_Handler () __attribute__((weak, alias ("Default_Handler")));
void H_Fault_Handler () __attribute__((weak, alias ("Default_Handler")));

static uint32 Stack_Top[256] ;
void (* const g_p_fn_vectors[])() __attribute__((section(".vectors"))) =
{
		(void (*)())  ((uint32)Stack_Top+sizeof(Stack_Top)),
		&Reset_Handler,
		&NMI_Handler,
		&H_Fault_Handler
};




extern uint32 _E_text;
extern uint32 _S_data;
extern uint32 _E_data;
extern uint32 _S_bss;
extern uint32 _E_bss;

void Reset_Handler ()
{
	// copy data section from flash to sram
	uint32 DATA_size= (uint8*) &_E_data - (uint8*) &_S_data ;
	uint8* p_src = (uint8*) &_E_text ;
	uint8* p_dst = (uint8*) &_S_data ;
	for ( int i =0;i<DATA_size;i++)
	{
		*((uint8*)p_dst++) = *((uint8*)p_src++) ;
	}

		// copy data section from flash to sram

	uint32 bss_size = (uint8*) &_E_bss - (uint8*) &_S_bss ;
	p_dst = (uint8*) &_S_bss ;
	for ( int i =0;i<DATA_size;i++)
		{
			*((uint8*)p_dst++) = (uint8) 0 ;
		}

		// jump to main

	main();
}

