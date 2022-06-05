// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ //
// ^^^^^^^^^^^^^^ MOHAMED KHAELD ^^^^^^^^^^^^ //
// ^^^^^^^^^^^^^^    C2        ^^^^^^^^^^^^ //
// ^^^^^^^^^^^^^^   20/11/2021     ^^^^^^^^^^^^ //
// ^^^^^^^^^^^^^^    RCC         ^^^^^^^^^^^  //
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ //
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H
/* CLOCKS PRESCALAR MACROS */

/* AHB PRESCALAR */

#define RCC_AHB_PRESCALAR_DIV_NO 0x0
#define RCC_AHB_PRESCALAR_DIV_2 0x8
#define RCC_AHB_PRESCALAR_DIV_4 0x9
#define RCC_AHB_PRESCALAR_DIV_8 0xA
#define RCC_AHB_PRESCALAR_DIV_16 0xB
#define RCC_AHB_PRESCALAR_DIV_64 0xC
#define RCC_AHB_PRESCALAR_DIV_128 0xD
#define RCC_AHB_PRESCALAR_DIV_256 0xE
#define RCC_AHB_PRESCALAR_DIV_512 0xF

/*****************/

/* APB1 PRESCALAR */

#define RCC_APB1_PRESCALAR_DIV_NO 0x0
#define RCC_APB1_PRESCALAR_DIV_2 0x4
#define RCC_APB1_PRESCALAR_DIV_4 0x5
#define RCC_APB1_PRESCALAR_DIV_8 0x6
#define RCC_APB1_PRESCALAR_DIV_16 0x7

/*****************/

/* APB2 PRESCALAR */

#define RCC_APB2_PRESCALAR_DIV_NO 0x0
#define RCC_APB2_PRESCALAR_DIV_2 0x4
#define RCC_APB2_PRESCALAR_DIV_4 0x5
#define RCC_APB2_PRESCALAR_DIV_8 0x6
#define RCC_APB2_PRESCALAR_DIV_16 0x7

/*****************/

/**************************************************          Macros          ************************************************************/

/* System clock switch  */
#define SW_HSI 0 // HSI(Internal High-Speed clock).
#define SW_HSE 1 // HSE(External High-Speed clock).
#define SW_PLL 2 // PLL(Phase-locked loop).

/* Internal High-Speed clock */

#define HSITRIM_NOTRIM 0   // Internal high-speed clock no trimming.
#define HSITRIM_POSITIVE 1 // Internal high-speed clock trimming positive steps.
#define HSITRIM_NEGATIVE 2 // Internal high-speed clock trimming negative steps.

/*****************************/

/*External High-Speed clock */

/* Clock security system */
#define CSSON 1  // Clock security system enabled.
#define CSSOFF 0 // Clock security system disabled.

/* External high-speed clock bypass */
#define HSEBYP_ON 1  // External high-speed clock bypass enabled.
#define HSEBYP_OFF 0 // External high-speed clock bypass disabled.

/*****************************/

/* Phase-locked loop */

/* PLL entry clock source */
#define PLLSRC_HSE 1 // HSE oscillator clock selected as PLL input clock.
#define PLLSRC_HSI 0 // HSI oscillator clock / 2 selected as PLL input clock.

/* HSE divider for PLL entry */
#define PLLXTPRE_ON 1  // HSE clock divided by 2.
#define PLLXTPRE_OFF 0 // HSE clock not divided.

/* PLL multiplication factor */
#define PLLMUL_X2 0   // PLL input clock x 2.
#define PLLMUL_X3 1   // PLL input clock x 3.
#define PLLMUL_X4 2   // PLL input clock x 4.
#define PLLMUL_X5 3   // PLL input clock x 5.
#define PLLMUL_X6 4   // PLL input clock x 6.
#define PLLMUL_X7 5   // PLL input clock x 7.
#define PLLMUL_X8 6   // PLL input clock x 8.
#define PLLMUL_X9 7   // PLL input clock x 9.
#define PLLMUL_X10 8  // PLL input clock x 10.
#define PLLMUL_X11 9  // PLL input clock x 11.
#define PLLMUL_X12 10 // PLL input clock x 12.
#define PLLMUL_X13 11 // PLL input clock x 13.
#define PLLMUL_X14 12 // PLL input clock x 14.
#define PLLMUL_X15 13 // PLL input clock x 15.
#define PLLMUL_X16 14 // PLL input clock x 16.

/*********************/

/****************************************************************************************************************************************/

#endif
