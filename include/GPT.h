/**********************************************************************/
/*****************		Author:KARIM SILEEM 	***********************/

/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	GPT				***********************/
/**********************************************************************/
/**********************************************************************/


#ifndef GPT_H_
#define GPT_H_

#include "GPT_cfg.h"



/*name Error Codes */

#define GPT_E_UNINIT                        0x0A
#define GPT_E_BUSY 				            0x0B
#define GPT_E_NOT_STARTED 	                0x0C
#define GPT_E_ALREADY_INITIALIZED           0x0D
#define GPT_E_PARAM_CHANNEL                 0x14
#define GPT_E_PARAM_VALUE 	                0x15
#define GPT_E_PARAM_MODE    	            0x1F
#define GPT_E_PARAM_CONFIG                  0x0E 


/*name Service id */

#define GPT_INIT_SERVICE_ID                 0x01
#define GPT_DEINIT_SERVICE_ID               0x02
#define GPT_GETTIMEELAPSED_SERVICE_ID       0x03
#define GPT_GETTIMEREMAINING_SERVICE_ID     0x04
#define GPT_STARTTIMER_SERVICE_ID           0x05
#define GPT_STOPTIMER_SERVICE_ID            0x06
#define GPT_ENABLENOTIFICATION_SERVICE_ID   0x07
#define GPT_DISABLENOTIFICATION_SERVICE_ID  0x08
#define GPT_SETMODE_SERVIVCE_ID             0x09
#define GPT_DISABLEWAKEUP_SERVICE_ID        0x0a
#define GPT_ENABLEWAKEUP_SERVICE_ID         0x0b

//@}

/** Channel time value type */
typedef u32 Gpt_ValueType;



typedef enum
{
	GPT_MODE_NORMAL=0,
	GPT_MODE_SLEEP,
	GPT_MODE_PWM,
	External_Clock_MODE
} Gpt_ModeType;






#define     GPT_CHANNEL_CNT        5

#define     PWM_edge_aligned_mode_UP      1
#define     PWM_edge_aligned_mode_DOWN    2
#define     PWM_center_aligned_mode1      3
#define     PWM_center_aligned_mode2      4
#define     PWM_center_aligned_mode3      5

void Gpt_Init(const Gpt_ConfigType *config);

void Gpt_DeInit( void );

Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType channel);

Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType channel );

void Gpt_StartTimer(Gpt_ChannelType channel, Gpt_ValueType value);

void Gpt_StopTimer(Gpt_ChannelType channel);

void Gpt_EnableNotification( Gpt_ChannelType channel);

void Gpt_DisableNotification( Gpt_ChannelType channel);

void Gpt_SetMode( Gpt_ModeType mode );

void Gpt_SetPWMMode( u8 select );

void Gpt_DisableWakeup( Gpt_ChannelType channel );

void Gpt_EnableWakeup( Gpt_ChannelType channel );

u16 Gpt_u16GetCounter();

#endif /*GPT_H_*/
