#include "platforms_type.h"
extern uint32 _Stack_top ;
extern int main (void);

void Reset_Handler (void);

void Default_Handler(void)
{
	Reset_Handler();
}
void NMI_Handler (void) 			__attribute__ ((weak, alias("Default_Handler"))) ;
void H_FaultHandler (void) 			__attribute__ ((weak, alias("Default_Handler"))) ;
void MM_Fault_handler (void) 		__attribute__ ((weak, alias("Default_Handler"))) ;
void Bus_Handler (void) 			__attribute__ ((weak, alias("Default_Handler"))) ;
void Usage_Fault_Handler (void) 	__attribute__ ((weak, alias("Default_Handler"))) ;


uint32 vectors [] __attribute__((section(".vectors"))) =
{
		(uint32) &_Stack_top,
		(uint32) &Reset_Handler,
		(uint32) &NMI_Handler,
		(uint32) &H_FaultHandler,
		(uint32) &MM_Fault_handler,
		(uint32) &Bus_Handler,
		(uint32) &Usage_Fault_Handler
};

extern uint32 _E_TEXT ; 	// end of text section
extern uint32 _S_DATA ; 	// start of data section 
extern uint32 _E_DATA ;		// end of data section
extern uint32 _S_BSS ;		// start of bss section
extern uint32 _E_BSS ;		// end of bss section

void Reset_Handler (void)
{
	// copy data from flash to ram
	uint32 count = 0;
	uint32 data_size = (uint8*) &_E_DATA - (uint8*) &_S_DATA ;
	uint8* src_ptr = (uint8*) &_E_TEXT ;
	uint8* dst_ptr = (uint8*) &_S_DATA ;
	for (count=0;count<data_size;count++)
	{
		*(uint8*) dst_ptr++ = *(uint8*) src_ptr++ ;
	}
	// init the bss with zero in ram
	data_size = (uint8*) &_E_BSS - (uint8*) &_S_BSS ;
	dst_ptr = (uint8*) &_S_BSS ;
	for (count=0;count<data_size;count++)
	{
		*(uint8*) dst_ptr++ = (uint8) 0 ;
	}
	//jump to main
	main();
}




