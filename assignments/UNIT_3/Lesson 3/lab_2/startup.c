#include "platforms_type.h"

extern int main(void);
extern uint32 _Stack_top;

void Reset_Handler (void);

void Default_Handler (void)
{
	Reset_Handler();
}

void NMI_Handler (void) __attribute__ ((weak, alias ("Default_Handler")));
void H_Fault_Handler (void) __attribute__ ((weak, alias ("Default_Handler")));
void MM_Fault_Handler (void) __attribute__ ((weak, alias ("Default_Handler")));
void Bus_Fault (void) __attribute__ ((weak, alias ("Default_Handler")));
void Usage_Fault_Handler (void) __attribute__ ((weak, alias ("Default_Handler")));


uint32 vectors [] __attribute__((section(".vectors"))) ={
	(uint32) &_Stack_top,
	(uint32) &Reset_Handler,
	(uint32) &NMI_Handler,
	(uint32) &H_Fault_Handler,
	(uint32) &MM_Fault_Handler,
	(uint32) &Bus_Fault,
	(uint32) &Usage_Fault_Handler
};

extern uint32 _S_data ;
extern uint32 _E_data ;
extern uint32 _S_bss ;
extern uint32 _E_bss ;
extern uint32 _E_text ;

void Reset_Handler (void)
{
	// copy data from flash to ram
	uint32 data_size = (uint8*) &_E_data - (uint8*) &_S_data ;
	uint8* ptr_src = (uint8*) _E_text ;
	uint8* ptr_dst = (uint8*) &_S_data ;
	for (int i = 0; i<data_size;i++)
	{
		*(uint8*) ptr_dst++ = *(uint8*) ptr_src++ ;
	}
	// init the bss with zero in ram
	uint32 bss_size = (uint8*) &_E_bss - (uint8*) &_S_bss ;
	ptr_dst = (uint8*) &_S_bss ;
	for (int i = 0; i<bss_size;i++)
	{
		*(uint8*) ptr_dst++ = *(uint8*) 0 ;
	}

	// jump to main
	main ();
}