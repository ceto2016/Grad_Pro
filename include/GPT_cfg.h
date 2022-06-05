/**********************************************************************/
/*****************		Author:KARIM SILEEM 	***********************/
/*****************		Layer:	MCAL			***********************/
/*****************		SWC:	GPT				***********************/
/**********************************************************************/
/**********************************************************************/




#ifndef GPT_CONFIG_H_
#define GPT_CONFIG_H_


#define CHANNEL_NUM2   2

#define CHANNEL_NUM3   3

#define CHANNEL_NUM4   4

#define CHANNEL_NUM5   5



/** Channel id type */
typedef u8 Gpt_ChannelType;


/* Channel behavior */
typedef enum
{
	GPT_MODE_ONESHOT=0,
	GPT_MODE_CONTINUOUS
}Gpt_ChannelMode;



typedef struct  {
	u32 GptChannelClkSrc;
	 Gpt_ChannelType GptChannelId;
	Gpt_ChannelMode GptChannelMode;
	void (*GptNotification)();
	u8 GptNotificationPriority;
	u32 GptChannelPrescale;

} Gpt_ConfigType;







#endif 
