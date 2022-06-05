#ifndef HALL_H
#define HALL_H

#include "STD_TYPES.h"

#define wheelRaduis 1
#define CAR_MOVING 1
#define CAR_NOT_MOVING 2
#define CAR_SPEED_EXCEPTION 3

typedef struct
{
    u8 statusCode;
    u8 speedPerKm;
    u32 RPM;
} SpeedData;

void HALL_GetSpeed(SpeedData *ptr_SpeedData);
void HALL_Init();

#endif
