// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ //
// ^^^^^^^^^^^^^^ MOHAMED KHAELD ^^^^^^^^^^^^ //
// ^^^^^^^^^^^^^^    C2         ^^^^^^^^^^^^ //
// ^^^^^^^^^^^^^^   20/11/2021     ^^^^^^^^^^^^ //
// ^^^^^^^^^^^^^^    RCC         ^^^^^^^^^^^  //
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ //

#include <BIT_MATH.h>
#include <stm32f103C8.h>
#include <STD_TYPES.h>
#include "RCC_config.h"
#include "RCC_interface.h"
#include "RCC_private.h"

RCC_ErrorStatus RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31) // Checks if Peripheral is in the valid range
    {
        switch (Copy_u8BusId)
        {
        case RCC_AHB:
            SET_BIT(RCC->AHBENR, Copy_u8PerId);
            break; // Enables the clock of the required peripheral on AHB
        case RCC_APB1:
            SET_BIT(RCC->APB1ENR, Copy_u8PerId);
            break; // Enables the clock of the required peripheral on APB1
        case RCC_APB2:
            SET_BIT(RCC->APB2ENR, Copy_u8PerId);
            break; // Enables the clock of the required peripheral on APB2
        default:
            return RCC_NOK;
            break;
        }
        return RCC_OK;
    }
    else
    {
        return RCC_NOK;
    }
}

RCC_ErrorStatus RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
        case RCC_AHB:
            CLR_BIT(RCC->AHBENR, Copy_u8PerId);
            break;
        case RCC_APB1:
            CLR_BIT(RCC->APB1ENR, Copy_u8PerId);
            break;
        case RCC_APB2:
            CLR_BIT(RCC->APB2ENR, Copy_u8PerId);
            return RCC_OK;
        }
    }
    else
    {
        return RCC_NOK;
    }
}

void RCC_voidInitSysClock(void)
{
#if Sys_Clock_Source == SW_HSI

    SET_BIT(RCC->CR, 0);    // Sets Bit 0 of RCC_CR (Clock control register) to enable HSI(Internal high-speed clock).
    RCC->CFGR = 0x00000000; // Resets RCC_CFGR (Clock configuration register).
    RCC->CFGR |= SW_HSI;    // Sets value of Bits 0 : 1 of RCC_CFGR to select the system clock.
#elif Sys_Clock_Source == SW_HSE
    SET_BIT(RCC->CR, 16);   // Sets Bit 16 of RCC_CR to enable HSE(External high-speed clock).
    RCC->CFGR = 0x00000000; // Resets RCC_CFGR.
    RCC->CFGR |= SW_HSE;    // Sets value of Bits 0 : 1 of RCC_CFGR to select the system clock.
    switch (CSSON_VAL)
    {
    case CSSON:
        SET_BIT(RCC->CR, 19);
        break; // Sets value of bit 19 of RCC_CR to enable Clock security system
    case CSSOFF:
        CLR_BIT(RCC->CR, 19);
        break; // Clears value of bit 19 of RCC_CR to disable Clock security system
    }

    switch (HSEBYP_VAL)
    {
    case HSEBYP_ON:
        SET_BIT(RCC->CR, 18);
        break; // Sets value of bit 18 of RCC_CR to enable HSE bypass
    case HSEBYP_OFF:
        CLR_BIT(RCC->CR, 18);
        break; // Clears value of bit 18 of RCC_CR to disable HSE bypass
    }

#elif Sys_Clock_Source == SW_PLL
    RCC->CFGR |= (((u32)(PLLMUL_VAL)) << 18); // Sets value of Bits 18 : 21 of RCC_CFGR to set PLL multiplication factor
    SET_BIT(RCC->CR, 24);                     // Sets Bit 24 of RCC_CR to enable PLL(Phase-locked loop).
    RCC->CFGR = 0x00000000;                   // Resets RCC_CFGR.
    RCC->CFGR |= SW_PLL;                      // Sets value of Bits 0 : 1 of RCC_CFGR to select the system clock.
    switch (PLLSRC_VAL)
    {
    case PLLSRC_HSE:
        SET_BIT(RCC->CFGR, 16); // Sets value of Bit 16 of RCC_CFGR to select HSE as PLL input.
        break;

    case PLLSRC_HSI:
        CLR_BIT(RCC->CFGR, 16); // Resets value of Bit 16 of RCC_CFGR to select HSI as PLL input.
        break;
    }

    switch (PLLXTPRE_VAL)
    {
    case PLLXTPRE_ON:
        SET_BIT(RCC->CFGR, 17); // Sets value of Bit 17 of RCC_CFGR to enable HSE divider for PLL entry.
        break;

    case PLLXTPRE_OFF:
        CLR_BIT(RCC->CFGR, 17); // Clears value of Bit 17 of RCC_CFGR to dissable HSE divider for PLL entry.
        break;
    }
#endif
    /* CLOCKS PRESCALARs */
    RCC->CFGR |= ((RCC_AHB_PRESCALAR_DIV << 4) | (RCC_APB1_PRESCALAR_DIV << 8) | (RCC_APB2_PRESCALAR_DIV << 11));
    /*********************/
}
