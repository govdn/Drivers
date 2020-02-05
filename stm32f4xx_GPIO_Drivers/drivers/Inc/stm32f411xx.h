/*
 * stm32f411xx.h
 *
 *  Created on: Jan 17, 2020
 *      Author: goverdhan
 */

#ifndef INC_STM32F411XX_H_
#define INC_STM32F411XX_H_
#include <stdint.h>


#define __vo volatile

#define FLASH_BASEADDR			0x08000000U			/*Base address of Flash*/
#define SRAM1_BASEADDR			0x20000000U			/*Base address of SRAM*/
#define ROM_BASEADDR			0x1FFF0000U			/*Base address of ROM*/
#define SRAM 					SRAM1_BASEADDR

/* AHBx and APBx Peripheral Base Address */

#define PERIPH_BASEADDR			0x40000000U
#define APB1PERIPH_BASEADDR		PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR		0x40010000U
#define AHB1PERIPH_BASEADDR		0x40020000U
#define AHB2PERIPH_BASEADDR 	0x50000000U

/* Base Address of peripheral hanging to AHB1 Bus */

#define GPIOA_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOH_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1C00)
#define RCC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x3800)

/* Base Address of peripheral hanging to APB1 Bus */

#define I2C3_BASEADDR			(APB1PERIPH_BASEADDR + 0x5C00)
#define I2C2_BASEADDR			(APB1PERIPH_BASEADDR + 0x5800)
#define I2C1_BASEADDR			(APB1PERIPH_BASEADDR + 0x5400)
#define USART2_BASEADDR			(APB1PERIPH_BASEADDR + 0x4400)
#define SPI3_BASEADDR			(APB1PERIPH_BASEADDR + 0x3C00)
#define SPI2_BASEADDR			(APB1PERIPH_BASEADDR + 0x3800)

/* Base Address of peripheral hanging to APB2 Bus */

#define SPI5_BASEADDR			(APB2PERIPH_BASEADDR + 0x5000)
#define EXTI_BASEADDR			(APB2PERIPH_BASEADDR + 0x3C00)
#define SPI4_BASEADDR			(APB2PERIPH_BASEADDR + 0x3400)
#define SPI1_BASEADDR			(APB2PERIPH_BASEADDR + 0x3000)
#define SYSCFG_BASEADDR			(APB2PERIPH_BASEADDR + 0x3800)
#define USART6_BASEADDR			(APB2PERIPH_BASEADDR + 0x1400)
#define USART1_BASEADDR			(APB2PERIPH_BASEADDR + 0x1000)




/******************************peripheral register definition structure***********************************/
/*
*Note: Register are specific to the Controller family
*/

typedef struct
{
	__vo uint32_t MODER;              /*GPIO port mode register */
	__vo uint32_t OTYPER;			/*GPIO port output type register*/
	__vo uint32_t OSPEEDR;			/*GPIO port output speed register*/
	__vo uint32_t PUPDR;				/*GPIO port pull-up/pull-down register*/
	__vo uint32_t IDR;				/*GPIO port input data register*/
	__vo uint32_t ODR;				/*GPIO port output data register*/
	__vo uint32_t BSRR;				/*GPIO port bit set/reset register*/
	__vo uint32_t LCKR;				/*GPIO port configuration lock register*/
	__vo uint32_t AFR[2];			/*AFR[0] GPIO alternate function low register, AFR[1] GPIO alternate function high register */
}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	uint32_t Reserved0[2];
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t Reserved1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	uint32_t Reserved2[2];
}RCC_RegDef_t;


/*
 * peripheral definition(peripheral address typecasted to XXX_RegDef_t)
 */

#define GPIOA		((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB		((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC		((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD		((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE		((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOH		((GPIO_RegDef_t*) GPIOH_BASEADDR)

#define RCC 		((RCC_RegDef_t*) RCC_BASEADDR)

/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()	(RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()	(RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()	(RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()	(RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()	(RCC->AHB1ENR |= (1<<4))
#define GPIOH_PCLK_EN()	(RCC->AHB1ENR |= (1<<7))


/*
 *  Clock Enable Macros for I2Cx enable
 */

#define I2C1_PCLK_EN()	(RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN()	(RCC->APB1ENR |= (1<<22))
#define I2C3_PCLK_EN()	(RCC->APB1ENR |= (1<<23))

/*
 *  Clock Enable Macros for SPIx enable
 */

#define SPI1_PCLK_EN()	(RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN()	(RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_EN()	(RCC->APB1ENR |= (1<<15))
#define SPI4_PCLK_EN()	(RCC->APB2ENR |= (1<<13))


/*
 * Clock Enable Macros for  USARTX enable
 */

#define USART1_PCLK_EN()	(RCC->APB2ENR |= (1<<4))
#define USART2_PCLK_EN()	(RCC->APB1ENR |= (1<<17))
#define USART6_PCLK_EN()	(RCC->APB2ENR |= (1<<5))

/*
 * Clock Enable Macros for SYSCFG enable
 */

#define SYSCFGEN_PLK_EN()	(RCC->APB2ENR |= (1<<14))

/*
 * Clock Disable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<4))
#define GPIOH_PCLK_DI()	(RCC->AHB1ENR &= ~(1<<7))


/*
 *  Clock Disable Macros for I2Cx Disable
 */

#define I2C1_PCLK_DI()	(RCC->APB1ENR &= ~(1<<21))
#define I2C2_PCLK_DI()	(RCC->APB1ENR &= ~(1<<22))
#define I2C3_PCLK_DI()	(RCC->APB1ENR &= ~(1<<23))

/*
 *  Clock Disable Macros for SPIx Disable
 */

#define SPI1_PCLK_DI()	(RCC->APB2ENR &= ~(1<<12))
#define SPI2_PCLK_DI()	(RCC->APB1ENR &= ~(1<<14))
#define SPI3_PCLK_DI()	(RCC->APB1ENR &= ~(1<<15))
#define SPI4_PCLK_DI()	(RCC->APB2ENR &= ~(1<<13))


/*
 * Clock Disable Macros for  USARTX Disable
 */

#define USART1_PCLK_DI()	(RCC->APB2ENR &= ~(1<<4))
#define USART2_PCLK_DI()	(RCC->APB1ENR &= ~(1<<17))
#define USART6_PCLK_DI()	(RCC->APB2ENR &= ~(1<<5))

/*
 * Clock Disable Macros for SYSCFG Disable
 */

#define SYSCFGEN_PLK_DI()	(RCC->APB2ENR &= ~(1<<14))

/*
 * Macros to Reset GPIOx Peripherals
 */

#define GPIOA_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<0));		(RCC->AHB1RSTR &= ~(1<<0)); }while(0)
#define GPIOB_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<1));		(RCC->AHB1RSTR &= ~(1<<1)); }while(0)
#define GPIOC_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<2));		(RCC->AHB1RSTR &= ~(1<<2)); }while(0)
#define GPIOD_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<3));		(RCC->AHB1RSTR &= ~(1<<3)); }while(0)
#define GPIOE_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<4));		(RCC->AHB1RSTR &= ~(1<<4)); }while(0)
#define GPIOH_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<7));		(RCC->AHB1RSTR &= ~(1<<7)); }while(0)

//some generic macros
#define ENABLE				1
#define DISABLE				0
#define SET					ENABLE
#define RESET 				DISABLE
#define GPIO_PIN_SET 		SET
#define GPIO_PIN_RESET 		RESET


#endif /* INC_STM32F411XX_H_ */
