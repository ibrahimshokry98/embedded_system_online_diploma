


#ifndef EXT_INT2_INTERFACE_H_
#define EXT_INT2_INTERFACE_H_


void EXT_INT2_Enable(void);
void EXT_INT2_Disable(void);
void EXT_INT2_CallBack (void (*PF)(void));
void EXT_INT2_SenseControl (uint8 INT_Trigger);


#define FallingEdge		0
#define	RisingEdge		1
#define	Onchange		2
#define	LowLevel		3




#endif /* EXT_INT2_INTERFACE_H_ */