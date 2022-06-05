#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "hall.h"
#include "hall_private.h"
#include "hall_config.h"
#include "GPT.h"
u32 oldCounter = 0x0;
void HALL_GetSpeed(SpeedData *ptr_SpeedData)
{
    u32 snapshot = Gpt_u16GetCounter();
    // TODO: need #define for each case 1) car moving 2) car stoped 3)Exception
    if (snapshot == 0)
    {
        ptr_SpeedData->statusCode = CAR_NOT_MOVING;
    }
    else if (snapshot > 0)
    {
        ptr_SpeedData->statusCode = CAR_MOVING;
    }
    else
    {
        ptr_SpeedData->statusCode = CAR_SPEED_EXCEPTION;
    }
    ptr_SpeedData->RPM = snapshot * 60;
    ptr_SpeedData->speedPerKm = (ptr_SpeedData->RPM * 3.14 * wheelRaduis * 3) / (u32)25;
}

void HALL_Init()
{
    Gpt_SetMode(External_Clock_MODE);
}
