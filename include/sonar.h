
/*Header File Guard*/
#ifndef SONAR_H
#define SONAR_H
#include "STD_TYPES.h"
#define SONAR_BASE_ADDRESS (0b1110000)
#define SONAR_F1_ADDRESS (0b00000001)
#define SONAR_F2_ADDRESS (0b00000011)
#define SONAR_B1_ADDRESS (0b00000111)
#define SONAR_B2_ADDRESS (0b00001111)
#define TAKE_RANGE_CMD (81)
#define CHANGE_SEQUENCE_1 (170)
#define CHANGE_SEQUENCE_2 (165)


#define NULL ((void *)0)

/************************************Functions' Prototypes************************************/

/*this function is to tell the sonar to save readings*/

/*this function is to save readings and request them of one sonar*/
u16 HAL_u16SonarReportLastReading(u8 Copy_u8Address);

/*this function is to send commands*/
void HAL_u16SonarChangeAddress(u8 Copy_u8Address, u8 Copy_u8NewAddress);

#endif
