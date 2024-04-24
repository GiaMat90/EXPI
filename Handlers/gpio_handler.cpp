/*
 * gpio_handler.cpp
 *
 *  Created on: Jan 4, 2024
 *      Author: giaco
 */
#include "gpio_handler.hpp"

namespace Handlers
{
	GPIO_Handler::GPIO_Handler() : Handler(), m_type(GPIO_TYPE::NONE), m_port(0u), m_pin(0u)
	{

	}

	GPIO_Handler::GPIO_Handler(const uint32_t port, const uint32_t pin) :
			Handler(), m_type(GPIO_TYPE::NONE), m_port(port), m_pin(pin)
	{

	}

	GPIO_Handler::~GPIO_Handler()
	{

	}

	void GPIO_Handler::setType(const GPIO_TYPE type)
	{
		portSetType(type);
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

	void GPIO_Handler::setHigh()
	{
		HAL_GPIO_WritePin(m_port, m_pin, GPIO_PIN_SET);
	}

	void GPIO_Handler::setLow()
	{
		HAL_GPIO_WritePin(m_port, m_pin, GPIO_PIN_RESET);
	}

	void GPIO_Handler::toggle()
	{
		if(GPIO_PinState::GPIO_PIN_RESET == HAL_GPIO_ReadPin(m_port, m_pin))
		{
			HAL_GPIO_WritePin(m_port, m_pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(m_port, m_pin, GPIO_PIN_RESET);
		}
	}

	void GPIO_Handler::glitch()
	{
		HAL_GPIO_WritePin(m_port, m_pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(m_port, m_pin, GPIO_PIN_RESET);
	}

	GPIO_Handler::GPIO_STATUS GPIO_Handler::getStatus()
	{
		GPIO_STATUS retVal = GPIO_STATUS::HIGH;
		if(GPIO_PIN_RESET == HAL_GPIO_ReadPin(m_port, m_pin))
		{
			retVal = GPIO_STATUS::LOW;
		}
		return retVal;
	}

	bool GPIO_Handler::waitUntil(const GPIO_Handler::GPIO_STATUS status, const uint32_t threshold)
	{
		if(GPIO_Handler::GPIO_STATUS::HIGH == status || GPIO_Handler::GPIO_STATUS::LOW == status)
		{
			if(threshold > 0)
			{
				uint32_t ticks = HAL_GetTick();
				while(status != this->getStatus() && ((ticks + threshold) > HAL_GetTick()));
			}
			else
			{
				while(status != this->getStatus());
			}
		}
		else
		{
			asm("NOP");
		}
		return this->getStatus() == status;
	}

	bool GPIO_Handler::waitUntilFor(const GPIO_STATUS status, const Handlers::Timer_Handler* timer, const uint32_t wait_time)
	{
		if(GPIO_Handler::GPIO_STATUS::HIGH == status || GPIO_Handler::GPIO_STATUS::LOW == status)
		{
			timer->resetCounter();
			while(status != this->getStatus() && (timer->getTimeCounter() < wait_time));
		}
		return this->getStatus() == status;
	}

	uint32_t GPIO_Handler::durationState(const GPIO_STATUS status, const Handlers::Timer_Handler* timer)
	{
		timer->resetCounter();
		while(status == this->getStatus());
		return timer->getTimeCounter();
	}
}

