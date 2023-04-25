#include "platforms_types.h"

#define SYSCTL_RCGC_R 		*(vuint32_t*) (0x400FE108)
#define GPIO_PORTF_DIR_R 	*(vuint32_t*) (0x40025400)
#define GPIO_PORTF_DEN_R 	*(vuint32_t*) (0x4002551C)
#define GPIO_PORTF_DATA_R 	*(vuint32_t*) (0x400253FC)



int main()
{
	vuint32_t delay_count ;
	SYSCTL_RCGC_R = 0x20 ;
	// delay to make sure GPIOF is up and runnning
	for (delay_count=0;delay_count<200;delay_count++) ;

	GPIO_PORTF_DIR_R |= 1<<3 ; // DIR is out for pin 3 in PORTF
	GPIO_PORTF_DEN_R |= 1<<3 ;

	while (1)
	{
		GPIO_PORTF_DATA_R |= 1<<3 ;
		for (delay_count=0;delay_count<200000;delay_count++) ;
		GPIO_PORTF_DATA_R &= ~(1<<3) ;
		for (delay_count=0;delay_count<200000;delay_count++) ;
	}
	



	return 0;
}

