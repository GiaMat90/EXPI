/*
 * gpio_port_esp32.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: giaco
 */

#include "../../gpio_handler.hpp"

#include "driver/gpio.h"

namespace Handlers
{
	void GPIO_Handler::setType(const GPIO_Handler::GPIO_TYPE mode)
	{		
		switch(mode)
		{
		case(GPIO_TYPE::INPUT):
		{
			gpio_set_direction(static_cast<gpio_num_t>(m_pin), GPIO_MODE_INPUT);
			/*
			GPIO_InitTypeDef GPIO_InitStruct = {0};
			GPIO_InitStruct.Pin = m_pin;
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
			GPIO_InitStruct.Pull = GPIO_PULLUP;
			HAL_GPIO_Init((GPIO_TypeDef *)m_port, &GPIO_InitStruct);
			*/
			m_type = GPIO_TYPE::INPUT;
			break;
		}
		case(GPIO_TYPE::OUTPUT):
		{
			gpio_set_direction(static_cast<gpio_num_t>(m_pin), GPIO_MODE_OUTPUT);
			/*
			GPIO_InitTypeDef GPIO_InitStruct = {0};
			GPIO_InitStruct.Pin = m_pin;
			GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
			HAL_GPIO_Init((GPIO_TypeDef *)m_port, &GPIO_InitStruct);
			*/
			m_type = GPIO_TYPE::OUTPUT;
			break;
		}
		default:
			m_type = GPIO_TYPE::NONE;
			break;
		}
	}

	void GPIO_Handler::setHigh()
	{
		gpio_set_level(static_cast<gpio_num_t>(m_pin), 1);
	}

	void GPIO_Handler::setLow()
	{
		gpio_set_level(static_cast<gpio_num_t>(m_pin), 0);
	}

	void GPIO_Handler::toggle()
	{
		if(gpio_get_level(static_cast<gpio_num_t>(m_pin)))
		{
			gpio_set_level(static_cast<gpio_num_t>(m_port), 0);
		}
		else
		{
			gpio_set_level(static_cast<gpio_num_t>(m_port), 1);
		}
	}


	GPIO_Handler::GPIO_STATUS GPIO_Handler::getStatus()
	{
		GPIO_STATUS retVal = GPIO_STATUS::LOW;
		if(gpio_get_level(static_cast<gpio_num_t>(m_pin)))
		{
			retVal = GPIO_STATUS::HIGH;
		}
		return retVal;
	}

	bool GPIO_Handler::waitUntil(const GPIO_Handler::GPIO_STATUS status, const uint32_t threshold)
	{
		/*	ToDo yet
		if(GPIO_Handler::GPIO_STATUS::HIGH == status || GPIO_Handler::GPIO_STATUS::LOW == status)
		{
			if(threshold > 0)
			{
				uint32_t ticks; // = HAL_GetTick();
				while(status != this->getStatus() && ((ticks + threshold) > HAL_GetTick()));
			}
			else
			{
				while(status != this->getStatus());
			}
		}
		else
		{
			// asm("NOP");
		}
		return this->getStatus() == status;
		*/
		return false;
	}
}
