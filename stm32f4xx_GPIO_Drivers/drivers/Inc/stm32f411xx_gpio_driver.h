/*
 * stm32f411xx_gpio_driver.h
 *
 *  Created on: 27-Jan-2020
 *      Author: goverdhan
 */

#ifndef INC_STM32F411XX_GPIO_DRIVER_H_
#define INC_STM32F411XX_GPIO_DRIVER_H_



#endif /* INC_STM32F411XX_GPIO_DRIVER_H_ */


#include <stm32f411xx.h>


/*
 * This is a Configuration structure for GPIO pin
 */

typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;				/*!< Possible Value from @GPIO_PIN_MODES >*/
	uint8_t GPIO_PinSpeed;				/*!< Possible Value from @GPIO_PIN_SPEED >*/
	uint8_t GPIO_PinPuPdControl;		/*!< Possible Value from @GPIO_PIN_CONFIG>*/
	uint8_t GPIO_PinOPType;				/*!< Possible Value from @GPIO_PIN_OUTPUT_TYPE >*/
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*
 * This is a Handle Structure for a GPIO pin
 */
typedef struct{

	//pointer to hold the base address of the GPIO peripherals
	GPIO_RegDef_t *pGPIOx;  /*This holds the base address of the GPIO port to which the pin belongs */
	GPIO_PinConfig_t GPIO_PinConfig;	/* This holds GPIO pin configuration settings */


}GPIO_Handle_t;

/*@GPIO_PIN_NUMBERS
 * GPIO PIN Numbers
 */

#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15

/*@GPIO_PIN_MODES
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_IT_FT		4                   //Interrupt Falling Edge
#define	GPIO_MODE_IT_RT		5					//Interrupt Rising Edge
#define	GPIO_MODE_IT_RFT	6					//Raising and Falling Trigger

/*@GPIO_PIN_OUTPUT_TYPE
 * GPIO Output type
 */
#define GPIO_OP_TYPE_PP		0					//Push Pull Configuration
#define GPIO_OP_TYPE_OD		1					//Open Drain

/*@GPIO_PIN_SPEED
 * GPIO Possible Output speed
 */
#define GPIO_SPEED_LOW		0
#define	GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define	GPIO_SPEED_HIGH		3

/*@GPIO_PIN_CONFIG
 * GPIO pin pull up and Pull down Configuration Macros
 */
#define GPIO_NO_PUPD		0					//No Pull or Pull down
#define GPIO_PIN_PU			1					//Pull Up
#define	GPIO_PIN_PD			2					//Pull Down

/******************************************************************************************************************************
 ********************************************* API Supported by this Driver****************************************************
 *****************************************************************************************************************************/


/*
 * GPIO Clock Configuration
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);


/*
 * GPIO Init and Deint
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data Read and Write
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration and ISR Handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);


