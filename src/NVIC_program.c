

#include <BIT_MATH.h>
#include <stm32f103C8.h>
#include <STD_TYPES.h>
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

#define SCB_u32_AIRCR_REG *((volatile u32 *)(0xE000ED00 + 0x0C))

u8 NVIC_u8EnableInterrupt(u8 Copy_u8IRQN)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8RegIndex, Local_u8BitNb;
	if (Copy_u8IRQN < 240)
	{
		Local_u8RegIndex = Copy_u8IRQN / 32;
		Local_u8BitNb = Copy_u8IRQN % 32;

		/* Enable Peripheral Interrupt */
		NVIC->ISER[Local_u8RegIndex] = (1 << Local_u8BitNb);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
u8 NVIC_u8DisableInterrupt(u8 Copy_u8IRQN)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8RegIndex, Local_u8BitNb;
	if (Copy_u8IRQN < 240)
	{
		Local_u8RegIndex = Copy_u8IRQN / 32;
		Local_u8BitNb = Copy_u8IRQN % 32;

		/* Enable Peripheral Interrupt */
		NVIC->ICER[Local_u8RegIndex] = (1 << Local_u8BitNb);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 NVIC_u8SetPendingFlag(u8 Copy_u8IRQN)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8RegIndex, Local_u8BitNb;
	if (Copy_u8IRQN < 240)
	{
		Local_u8RegIndex = Copy_u8IRQN / 32;
		Local_u8BitNb = Copy_u8IRQN % 32;

		/* Enable Peripheral Interrupt */
		NVIC->ISPR[Local_u8RegIndex] = (1 << Local_u8BitNb);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
u8 NVIC_u8ClearPendingFlag(u8 Copy_u8IRQN)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8RegIndex, Local_u8BitNb;
	if (Copy_u8IRQN < 240)
	{
		Local_u8RegIndex = Copy_u8IRQN / 32;
		Local_u8BitNb = Copy_u8IRQN % 32;

		/* Enable Peripheral Interrupt */
		NVIC->ICPR[Local_u8RegIndex] = (1 << Local_u8BitNb);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 NVIC_u8GetActiveFlag(u8 Copy_u8IRQN, u8 *Copy_pu8ActiveFlagState)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8RegIndex, Local_u8BitNb;
	if ((Copy_u8IRQN < 240) && (Copy_pu8ActiveFlagState != NULL))
	{
		Local_u8RegIndex = Copy_u8IRQN / 32;
		Local_u8BitNb = Copy_u8IRQN % 32;

		*Copy_pu8ActiveFlagState = GET_BIT(NVIC->IABR[Local_u8RegIndex], Local_u8BitNb);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 NVIC_u8SetPriority(u8 Copy_u8IRQN, u8 Copy_u8GrpPri, u8 Copy_u8SubPri)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u8IRQN < 240)
	{
		NVIC->IPR[Copy_u8IRQN] = ((Copy_u8GrpPri << 6) | (Copy_u8SubPri << 4));
		//		NVIC->IPR[Copy_u8IRQN] = (((Copy_u8GrpPri << 2)| Copy_u8SubPri) << 4);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 NVIC_u8InitPriorityField(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* 2 Bits for Group Pri, 2 Bits for Sub Pri */
	SCB_u32_AIRCR_REG = 0x05FA0500;
	return Local_u8ErrorState;
}
