/**
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *      @File  			app.h
 *      @date			18/6/2023	2:26 PM
 *  	@brief			interface file for application
 *		@author			Ahmad Hesham
 *      @email			ahmedhesham606@icloud.com
 */



#include "app.h"
#include "../../HAL/led/led_interface.h"
#include "../../HAL/button/button_interface.h"
/**----------------------------------------------------------
 *  STATIC FUNCTION PROTOTYPES
 *----------------------------------------------------------*/
static void button_task(void);

typedef enum
{
	FIRST_PRESS,
	SECOND_PRESS,
	THIRD_PRESS,
	FOURTH_PRESS,
	FIFTH_PRESS
}enu_app_pressing_state_t_;

/**----------------------------------------------------------
 *  GLOBAL FUNCTION IMPLEMENTAIONS
 *----------------------------------------------------------*/
/**
 *	@brief			This function is used to initialize drivers used
 *	@param [in]		none
 *	@param [out]	none
 *	@return			none
 */
void app_init(void)
{
	button_init(button_task);
	led_init();
}

/**----------------------------------------------------------
 *  STATIC FUNCTION IMPLEMENTATION
 *----------------------------------------------------------*/
/**
 *	@brief			This function is the called back when button pressed
 *	@param [in]		none
 *	@param [out]	none
 *	@return			none
 */
static void button_task(void)
{
	static enu_app_pressing_state_t_ enu_pressing_state = FIRST_PRESS;
	uint8_t_ uint8_button_state;
	switch (enu_pressing_state)
	{
	case FIRST_PRESS:
		led_on(RED_LED);
		led_off(GREEN_LED);
		led_off(BLUE_LED);
		enu_pressing_state = SECOND_PRESS;
		break;

	case SECOND_PRESS:
		led_on(GREEN_LED);
		led_off(RED_LED);
		led_off(BLUE_LED);
		enu_pressing_state = THIRD_PRESS;
		break;

	case THIRD_PRESS:
		led_on(BLUE_LED);
		led_off(GREEN_LED);
		led_off(RED_LED);
		enu_pressing_state = FOURTH_PRESS;
		break;

	case FOURTH_PRESS:
		led_on(RED_LED);
		led_on(GREEN_LED);
		led_on(BLUE_LED);
		enu_pressing_state = FIFTH_PRESS;
		break;

	case FIFTH_PRESS:
		led_off(RED_LED);
		led_off(GREEN_LED);
		led_off(BLUE_LED);
		enu_pressing_state = FIRST_PRESS;
		break;



	default:
		break;
	}
	
	button_get_state(SW_1, &uint8_button_state);
	while(BUTTON_PRESSED == uint8_button_state)
	{
		button_get_state(SW_1, &uint8_button_state);
	}
}
/**********************************************************************************************************************
 *  END OF FILE: app.c
 *********************************************************************************************************************/
