

/************************************Includes************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "sonar.h"
#include "STK_interface.h"
#include "I2C_interface.h"

/************************************Functions' Definition************************************/
void LOC_voidSonarSaveRangeReading(u8 Copy_u8Address);

void LOC_voidSonarSaveRangeReading(u8 Copy_u8Address)
{
	/*local variable to save the data to be sent*/
	u8 LOC_u8Temp = TAKE_RANGE_CMD;

	/*this function is to send data from the buffer as a master through I2C */
	I2C_voidMasterSendData(I2C1, &LOC_u8Temp, 1, Copy_u8Address, I2C_NO_REPEAT_S);
}

u16 HAL_u16SonarReportLastReading(u8 Copy_u8Address)
{
	/*Local array to save readings byte by byte */
	u8 Loc_u8ReceivedArr[2];

	/*local variable to save readings in order*/
	u16 Loc_u16Result;

	LOC_voidSonarSaveRangeReading(Copy_u8Address);

	/*delay with 100 ms between readings*/
	MSTK_voidSetBusyWait(100, MSTK_MILLIS);

	/*reading data from the sonar*/
	I2C_voidMasterReceiveData(I2C1, Loc_u8ReceivedArr, 2, Copy_u8Address);

	/*swap array result index 0 with index 1*/
	Loc_u16Result = (Loc_u8ReceivedArr[0] << 8) | Loc_u8ReceivedArr[1];

	/*return from this function */
	return Loc_u16Result;
}

void HAL_u16SonarChangeAddress(u8 Copy_u8Address, u8 Copy_u8NewAddress)
{
	/*local array to store commands and address*/
	u8 Loc_u8Arr[3] = {CHANGE_SEQUENCE_1, CHANGE_SEQUENCE_2, Copy_u8NewAddress};

	/*sending new address*/
	I2C_voidMasterSendData(I2C1, Loc_u8Arr, 3, Copy_u8Address, I2C_NO_REPEAT_S);
}
