
 
 /**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Button.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Button_Init
* Service ID[hex]: 0x00
* Sync/Async: Asynchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to initialize the connected channel using Port MCAL
*******************************************************************************/
void Button_Init(void)
{
	Port_Init(&Port_ConfigType);
}
 
/*******************************************************************************
* Service Name: Button_GetState
* Service ID[hex]: 0x01
* Sync/Async: Asynchronous
* Reentrancy: Reentrant
* Parameters (in): ButtonChannel - An identifier for the dedicated Button
* 				   ButtonAttach  - Identification for the connection type (PULL_UP or PULL_DOWN)
* Parameters (inout): None
* Parameters (out): None
* Return value: Button_State
* Description: Function to get the state of the Button using Dio MCAL
*******************************************************************************/
Button_State Button_GetState(Button_ButtonChannelType ButtonChannel, Button_ButtonAttachType ButtonAttach)
{
	Dio_LevelType testLevel = DIO_LEVEL_LOW;
	Button_State state= BUTTON_RELEASED;
	
	
	if (ButtonAttach == PULL_UP)
		testLevel = DIO_LEVEL_LOW;
	else if (ButtonAttach == PULL_DOWN)
		testLevel = DIO_LEVEL_HIGH;
	
	if (Dio_ReadChannel(ButtonChannel) == testLevel)
	{
      state=BUTTON_PRESSED;
		
		while (Dio_ReadChannel(ButtonChannel) == testLevel);
		
	}
		return state;
	
	}



 /**********************************************************************************************************************
 *  END OF FILE: Button.c
 *********************************************************************************************************************/