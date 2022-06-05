
#include <BIT_MATH.h>
#include <get_distance.h>

#include <STD_TYPES.h>

void GetDistance_u16GetForwardDistance(u16 *Copy_ptrForwardDistanceData);
void GetDistance_u16AllDistance(u16 *Copy_ptrAllDistanceData);
void LOC_u16GetDistance(u16 *Copy_ptrDistanceData, u8 Copy_u8Count);
u16 returnTestNum();

void GetDistance_u16GetForwardDistance(u16 *Copy_ptrForwardDistanceData)
{
    LOC_u16GetDistance(Copy_ptrForwardDistanceData, CountForward);
}
void GetDistance_u16AllDistance(u16 *Copy_ptrAllDistanceData)
{
    LOC_u16GetDistance(Copy_ptrAllDistanceData, CountAll);
}

void LOC_u16GetDistance(u16 *Copy_ptrDistanceData, u8 Copy_u8Count)
{
    //* frist 2 for forward sonars and last 2 for backward
    for (u8 i = 0; i < Copy_u8Count; i++)
    {
        *(Copy_ptrDistanceData + i) = returnTestNum(); // HAL_u16SonarReportLastReading(SONAR_ADDRESS[i]);
    }
    for (u8 i = 0; i < Copy_u8Count; i++)
    {
        printf("sonar %d = %d \n", i + 1, *(Copy_ptrDistanceData + i));
    }
}

u16 returnTestNum()
{
    return 40;
}