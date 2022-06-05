/**********************************************************************/
/*****************		Author:KARIM SILEEM 	***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	GPT				***********************/
/**********************************************************************/
/**********************************************************************/


#ifndef GPT_REGISTER_H_
#define GPT_REGISTER_H_



typedef struct{

	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;	
	volatile u32 ARR;
	volatile u32 reserved;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 DCR;
	volatile u32 DMAR;
}TIM_t;




#define TIM2  ((volatile TIM_t*)0x40000000)

#define TIM3  ((volatile TIM_t*)0x40000400)

#define TIM4  ((volatile TIM_t*)0x40000800)

#define TIM5  ((volatile TIM_t*)0x40000C00)






#endif
