#include "platforms_type.h"

#define RCC_Base 		0x40021000
#define GPIOPA_Base 	0x40010800

#define RCC_APB2ENR  	*(vuint32_t*) (RCC_Base+0x18)
#define CRH_R  	 		*(vuint32_t*) (GPIOPA_Base+0x04)


typedef union {
				vuint32_t allfield;
				struct {
							vuint32_t reserved:13 ;
							vuint32_t pin_13:1 ;
						} pins;
			} ODR_R_t ;


volatile ODR_R_t* ODR_R  = (ODR_R_t*) (GPIOPA_Base + 0x0c) ;


int main (void)
{
	RCC_APB2ENR |= 1<<2 ;

	CRH_R &= 0xff0fffff ;

	CRH_R |= 0x00200000 ;

	while (1)
	{
		ODR_R -> pins.pin_13 = 1 ;
		for (int i =0 ; i<200000 ; i++);
		ODR_R -> pins.pin_13 = 0 ;
		for (int i =0 ; i<200000 ; i++);

	}

}