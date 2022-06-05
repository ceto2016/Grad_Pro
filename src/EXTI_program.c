#include <BIT_MATH.h>
#include <stm32f103C8.h>
#include <STD_TYPES.h>
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*EXTI_APF[16])(void) = {NULL};

u8 EXTI_u8PinInit(const EXTI_PinConfig_t *Copy_pstrPinInit)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8RegIndex, Local_u8ShiftValue;
	if (Copy_pstrPinInit != NULL)
	{
		/* Select EXTI Number */
		Local_u8RegIndex = Copy_pstrPinInit->PinNb / 4;
		Local_u8ShiftValue = Copy_pstrPinInit->PinNb % 4;

		/* Clear 4 bits to select the source of EXTI */
		AF->EXTICR[Local_u8RegIndex] &= ~((0b1111) << (Local_u8ShiftValue * 4));
		AF->EXTICR[Local_u8RegIndex] |= (Copy_pstrPinInit->PortNb << (Local_u8ShiftValue * 4));

		/* Select Edge Source (Falling edge or Raising or Any Edge) */
		switch (Copy_pstrPinInit->TriggerLevel)
		{
		case EXTI_u8_FALLING_EDGE:
			CLR_BIT(EXTI->RTSR, Copy_pstrPinInit->PinNb);
			SET_BIT(EXTI->FTSR, Copy_pstrPinInit->PinNb);
			break;
		case EXTI_u8_RAISING_EDGE:
			CLR_BIT(EXTI->FTSR, Copy_pstrPinInit->PinNb);
			SET_BIT(EXTI->RTSR, Copy_pstrPinInit->PinNb);
			break;
		case EXTI_u8_ANY_LOGICAL_CHANGE:
			SET_BIT(EXTI->RTSR, Copy_pstrPinInit->PinNb);
			SET_BIT(EXTI->FTSR, Copy_pstrPinInit->PinNb);
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;
		}

		/* Init Global Pointer to function used be ISR */
		EXTI_APF[Copy_pstrPinInit->PinNb] = Copy_pstrPinInit->pfunc;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(const EXTI_PinConfig_t *Copy_pstrPinInit)
{
	u8 Local_u8Errorstate = STD_TYPES_OK;
	if (Copy_pstrPinInit != NULL)
	{
		/* Enable the wanted EXTI */
		SET_BIT(EXTI->IMR, Copy_pstrPinInit->PinNb);
	}
	else
	{
		Local_u8Errorstate = STD_TYPES_NOK;
	}
	return Local_u8Errorstate;
}

u8 EXTI_u8IntDisable(const EXTI_PinConfig_t *Copy_pstrPinInit)
{
	u8 Local_u8Errorstate = STD_TYPES_OK;
	if (Copy_pstrPinInit != NULL)
	{
		/* Enable the wanted EXTI */
		CLR_BIT(EXTI->IMR, Copy_pstrPinInit->PinNb);
	}
	else
	{
		Local_u8Errorstate = STD_TYPES_NOK;
	}
	return Local_u8Errorstate;
}

/* ISR Imp */
void EXTI0_IRQHandler(void)
{
	if (EXTI_APF[0] != NULL)
	{
		EXTI_APF[0]();
	}
	/* Clear Pending Flag */
	SET_BIT(EXTI->PR, 0);
}

void EXTI1_IRQHandler(void)
{
	if (EXTI_APF[1] != NULL)
	{
		EXTI_APF[1]();
	}
	/* Clear Pending Flag */
	SET_BIT(EXTI->PR, 1);
}
