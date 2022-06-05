
#include <BIT_MATH.h>
#include <get_distance.h>
#include <hall.h>
#include <sonar.h>

#include <STD_TYPES.h>

//* macros for PWM channels
#define MOTOR 1
#define BRAKE 2

//* User input
#define UserSpeed 80
//* from user speed
u8 userSpeedSafeDistance = 0;
//''
u8 motorStatus = 1;
u8 brakeStatus = 0;
u8 currentDistance = 0;
u8 currentSafeSpeed = 0;

//* Sensors data
SpeedData currentSpeedData;
u16 LOC_u16SonarDistance[4] = {0, 0, 0, 0};
// LOC function
void stopAcu(u8 PinNumber);
void brake(u8 currentSafeSpeed);
void getRequiredDistance(u8 speedKM, u8 *distance);
void getRequiredSpeed(u8 distance, u8 *currentSafeSpeed);
void accelerate(u8 currentSafeSpeed);
void ACC();
int main()
{
    return 0;
}
void ACC()
{
    // Mode 1 maintain user speed
    getRequiredDistance(UserSpeed, &userSpeedSafeDistance);
    printf("Safe Distance for user speed %d \n", userSpeedSafeDistance);
    getRequiredSpeed(currentDistance, &currentSafeSpeed);
    printf("current Safe Speed  %d \n", currentSafeSpeed);
    //* init data
    //! get car data
    GetDistance_u16GetForwardDistance(LOC_u16SonarDistance);
    currentDistance = LOC_u16SonarDistance[(LOC_u16SonarDistance[1] > LOC_u16SonarDistance[0])] /* condtion return 1 if true and 0 if false */;
    HALL_GetSpeed(&currentSpeedData);
    printf("current Distance  %d \n", LOC_u16SonarDistance[0]);
    printf("current Speed  %d \n", currentSpeedData.speedPerKm);

    //! Safe distance and speed for user

    //* currentSpeedData.speedPerKm > UserSpeed we must speed down
    if (currentSpeedData.speedPerKm > UserSpeed)
    {
        printf("if currentSpeedData.speedPerKm > UserSpeed \n");
        brake(UserSpeed);
        //! sim for speed down
        // LOC_u16SonarDistance[0] = LOC_u16SonarDistance[0] + 10;
        // LOC_u16SonarDistance[1] = LOC_u16SonarDistance[1] + 10;
        // getRequiredSpeed(LOC_u16SonarDistance[LOC_u16SonarDistance[1] > LOC_u16SonarDistance[0]], &currentSafeSpeed);
        // printf("current Safe Speed  %d \n", currentSafeSpeed);
        // printf("end if \n");
    }

    // //! case 1 userSpeedSafeDistance > currentDistance
    if (userSpeedSafeDistance > currentDistance)
    {
        printf("user Speed Safe Distance bigger currentDistance \n");
        brake(currentSafeSpeed);
        accelerate(currentSafeSpeed);
    }
    //! case 2 userSpeedSafeDistance < currentDistance
    else if (userSpeedSafeDistance <= currentDistance)
    {
        printf("Safe Distance lower current Distance \n");
        accelerate(UserSpeed);
    }
}

//* tested
void getRequiredDistance(u8 speedKM, u8 *distance)
{
    u8 disArr[8] = {2, 4, 6, 14, 24, 38, 55, 75};
    *distance = disArr[speedKM / 16 + (((speedKM % 16) / (float)16) >= .5)];
}

//* tested
void getRequiredSpeed(u8 distance, u8 *currentSafeSpeed)
{
    u8 SpeedArr[8] = {0, 16, 32, 48, 64, 80, 96, 112};
    u8 disArr[8] = {2, 4, 6, 14, 24, 38, 55, 75};
    u8 i;
    if (distance > disArr[7])
    {
        *currentSafeSpeed = SpeedArr[7];
    }
    else if (distance == 0)
    {
        *currentSafeSpeed = SpeedArr[0];
    }
    else
    {
        for (i = 0; i < 0b1000; i++)
        {
            if (distance < disArr[i])
            {
                i--;
                break;
            }
        }
        *currentSafeSpeed = SpeedArr[i];
    }
}

void brake(u8 currentSafeSpeed)
{
    stopAcu(MOTOR);
    while (currentSpeedData.speedPerKm > currentSafeSpeed)
    {
        // TODO: PWM_channel2(currentSafeSpeed);
        HALL_GetSpeed(&currentSpeedData);
    };
    printf("brake current safe speed = %d \n", currentSafeSpeed);
    printf("speedPerKm = %d \n", currentSpeedData.speedPerKm);
    stopAcu(BRAKE);
}

void stopAcu(u8 PinNumber)
{
    switch (PinNumber)
    {
    case MOTOR:
        motorStatus = 0;
        printf("Motor Status  %d \n", motorStatus);
        break;
    case BRAKE:
        brakeStatus = 0;
        printf("Brake Status  %d \n", motorStatus);
        break;
    }
}
void accelerate(u8 currentSafeSpeed)
{
    currentSpeedData.speedPerKm = currentSafeSpeed;
    printf("motor  Speed %d \n", currentSpeedData.speedPerKm);
}
