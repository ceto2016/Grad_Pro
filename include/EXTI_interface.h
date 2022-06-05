
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_u8_PORTA        0
#define EXTI_u8_PORTB        1
#define EXTI_u8_PORTC        2

#define EXTI_u8_FALLING_EDGE       0
#define EXTI_u8_RAISING_EDGE       1
#define EXTI_u8_ANY_LOGICAL_CHANGE 2

typedef struct
{
	u8 PortNb;
	u8 PinNb;
	u8 TriggerLevel;
	void (*pfunc)(void);
}EXTI_PinConfig_t;


u8 EXTI_u8PinInit   (const EXTI_PinConfig_t * Copy_pstrPinInit);

u8 EXTI_u8IntEnable (const EXTI_PinConfig_t * Copy_pstrPinInit);

u8 EXTI_u8IntDisable(const EXTI_PinConfig_t * Copy_pstrPinInit);

#endif
