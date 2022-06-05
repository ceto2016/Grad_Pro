
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPT_register.h"

#include "GPT.h"
#include "stm32f10x.h"


TIM_TypeDef * const TimAddr[] =
{
		((TIM_TypeDef *)TIM2_BASE),
		((TIM_TypeDef *)TIM3_BASE),
		((TIM_TypeDef *)TIM4_BASE),
		((TIM_TypeDef *)TIM5_BASE),
};

typedef struct
{


	const Gpt_ConfigType *config;


	u32 configured;

	// Maps the a channel id to a configured channel id
	u8 channelMap[GPT_CHANNEL_CNT];

} Gpt_GlobalType;

typedef enum
{
	GPT_STATE_STOPPED = 0,
	GPT_STATE_STARTED,
} Gpt_StateType;


typedef struct
{
	Gpt_StateType state;
} Gpt_UnitType;

Gpt_UnitType Gpt_Unit[GPT_CHANNEL_CNT];

// Global config
Gpt_GlobalType Gpt_Global;




void Gpt_Init(const Gpt_ConfigType *config)
{
	u32 GPT_CHANNEL_ILL;
	u32 i=0;
	const Gpt_ConfigType *cfg;

	Gpt_ChannelType ch;

	for (i=0; i<GPT_CHANNEL_CNT; i++)
	{
		Gpt_Global.channelMap[i] = GPT_CHANNEL_ILL;
	}

	i = 0;
	cfg = config;
	while (cfg->GptChannelId != GPT_CHANNEL_ILL)
	{
		ch = cfg->GptChannelId;

		// Assign the configuration channel used later..
		Gpt_Global.channelMap[cfg->GptChannelId] = i;
		Gpt_Global.configured |= (1<<ch);

		cfg++;
		i++;
	}

	Gpt_Global.config = config;

}




Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType channel)
{
	u32	timer;
	if (channel <= GPT_CHANNEL_CNT)
	{
		u32 *tlval = (u32 *)&(TimAddr[channel]->ARR);
		u32 *tval = (u32 *)&(TimAddr[channel]->CNT);
		timer = *tlval - *tval;
	}

	return (timer);
}





Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType channel ){

	Gpt_ValueType remaining;

	if (channel <= GPT_CHANNEL_CNT)
	{
		u32 *tval = (u32 *)&(TimAddr[channel]->CNT);
		// Time remaining is the time until it hits 0, so just return the current timer value
		remaining = *tval;
	}

	return remaining;
}






void Gpt_StartTimer(Gpt_ChannelType channel, Gpt_ValueType value)
{
	int confCh;

	confCh = Gpt_Global.channelMap[channel];

	if (channel <= GPT_CHANNEL_CNT)
	{
		u32 *tlval = (u32 *)&(TimAddr[channel]->ARR);
		u32 *tval = (u32 *)&(TimAddr[channel]->CNT);

		*tlval = value;
		*tval = value;

		// always select interrupt
		//TimAddr[channel]->DIER |= TIM_DIER_UIE;

		// Make sure that no interrupt is pending.
		TimAddr[channel]->SR &= ~TIM_SR_UIF;

		// Set prescaler.
		TimAddr[channel]->PSC = Gpt_Global.config[confCh].GptChannelPrescale;

		// Enable timer
		TimAddr[channel]->CR1 |= (TIM_CR1_CEN | TIM_CR1_URS | TIM_CR1_DIR);
		TimAddr[channel]->CR1 &= ~TIM_CR1_UDIS;
	}



}


void Gpt_StopTimer(Gpt_ChannelType channel)
{

	if (channel <= GPT_CHANNEL_CNT)
	{
		// Disable timer
		TimAddr[channel]->CR1 &= ~TIM_CR1_CEN;
	}



}

void Gpt_EnableNotification( Gpt_ChannelType channel)
{


	if (channel <= GPT_CHANNEL_CNT)
	{
		// enable interrupts
		TimAddr[channel]->DIER |= TIM_DIER_UIE;
	}


}

void Gpt_DisableNotification( Gpt_ChannelType channel)
{

	if (channel <= GPT_CHANNEL_CNT)
	{
		TimAddr[channel]->DIER &= ~TIM_DIER_UIE;
	}

	return;
}





void Gpt_SetMode( Gpt_ModeType mode )

{

	u8 i;


	switch (mode)
	{
	case GPT_MODE_NORMAL :  ;break;

	case GPT_MODE_SLEEP :for (i= 0; i <= GPT_CHANNEL_CNT; i++)
	{
		Gpt_StopTimer(i);
	}; break;


	case External_Clock_MODE : 	TIM2->SMCR = 0x4056 ;    /* 1- No Filter
			                           2-Prescale disapled
			                           3- enable the external clock mode 2
			                           4-Configure the timer in trigger mode

	 */



	TIM2->CCMR1 = 0x0001;         /* 1-no filter
			                                 2-Prescale does not need to be configured.
			                                 3-select only the input capture source
	 */


	TIM2->CCER =0 ;
	TIM2->CNT = 0 ;
	break;
	}

}
u16 Gpt_u16GetCounter(){
	return TIM2->CNT ;
}




void Gpt_SetPWMMode( u8 select ){

	u8 i;

	for (i= 0; i <= GPT_CHANNEL_CNT; i++){

		TIM4->CCMR2 =0x6800;
		TIM4->EGR =0x0001;
		switch(select)
		{
		case PWM_edge_aligned_mode_UP :TIM4->CR1 =0x0080; break;

		case PWM_edge_aligned_mode_DOWN : TIM4->CR1 =0x0090; break;

		case PWM_center_aligned_mode1 :SET_BIT(TIM4->CR1,7);
		SET_BIT(TIM4->CR1,5); break;

		case PWM_center_aligned_mode2: SET_BIT(TIM4->CR1,7);
		SET_BIT(TIM4->CR1,6); break;

		case PWM_center_aligned_mode3 :	SET_BIT(TIM4->CR1,7);
		SET_BIT(TIM4->CR1,6);
		SET_BIT(TIM4->CR1,5);
		break;


		}

	}

}










