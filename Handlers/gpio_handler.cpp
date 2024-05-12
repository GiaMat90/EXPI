/*
 * gpio_handler.cpp
 *
 *  Created on: Jan 4, 2024
 *      Author: giaco
 */
#include "gpio_handler.hpp"

#include "Port/stm32/stm32_gpio_handler.hpp"

namespace Handlers
{
	//*** GPIO_Handeler_Interface implementation ***//
	GPIO_Handler* GPIO_Handler::makeGPIO(const BOARD_TYPE board)
	{
		GPIO_Handler* retHandler = nullptr;
		switch(board)
		{
		case(Handler::BOARD_TYPE::STM8):
				// ToDo
				break;
		case(Handler::BOARD_TYPE::STM32):
				static Handlers::STM32::GPIO stm32_gpio;
				retHandler = &stm32_gpio;
				break;
		case(Handler::BOARD_TYPE::ESP32):
				// ToDo
				break;
		case(Handler::BOARD_TYPE::ESP8266):
				// ToDo
				break;
		case(Handler::BOARD_TYPE::TIVA):
				// ToDo
				break;
		case(Handler::BOARD_TYPE::ATMEL):
				// ToDo
				break;
		default:
			break;
		}
		return retHandler;
	}

	void GPIO_Handler::glitch()
	{
		setHigh();
		setLow();
	}

	void GPIO_Handler::setStatus(const GPIO_STATUS status)
	{
		if(GPIO_Handler::GPIO_STATUS::HIGH == status)
		{
			this->setHigh();
		}
		else
		{
			this->setLow();
		}
	}
}

