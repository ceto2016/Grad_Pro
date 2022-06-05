// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ //
// ^^^^^^^^^^^^^^ MOHAMED KHAELD ^^^^^^^^^^^^ //
// ^^^^^^^^^^^^^^    C2        ^^^^^^^^^^^^ //
// ^^^^^^^^^^^^^^   20/11/2021     ^^^^^^^^^^^^ //
// ^^^^^^^^^^^^^^    RCC         ^^^^^^^^^^^  //
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ //
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

typedef enum
{
    RCC_NOK,
    RCC_OK
} RCC_ErrorStatus;

/**************************************************          Macros          ************************************************************/

/* Bus Id */
#define RCC_AHB  0  // AHB Id.
#define RCC_APB1 1  // APB1 Id.
#define RCC_APB2 2  // APB2 Id.


/*************************************************          Functions          **********************************************************/

void RCC_voidInitSysClock(void);

RCC_ErrorStatus RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

RCC_ErrorStatus RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

#endif
