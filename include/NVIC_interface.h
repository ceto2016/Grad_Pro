
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

u8 NVIC_u8EnableInterrupt    (u8 Copy_u8IRQN);
u8 NVIC_u8DisableInterrupt   (u8 Copy_u8IRQN);

u8 NVIC_u8SetPendingFlag     (u8 Copy_u8IRQN);
u8 NVIC_u8ClearPendingFlag   (u8 Copy_u8IRQN);

u8 NVIC_u8GetActiveFlag      (u8 Copy_u8IRQN,u8 * Copy_pu8ActiveFlagState);

u8 NVIC_u8SetPriority        (u8 Copy_u8IRQN,u8 Copy_u8GrpPri,u8 Copy_u8SubPri);

u8 NVIC_u8InitPriorityField  (void);
#endif