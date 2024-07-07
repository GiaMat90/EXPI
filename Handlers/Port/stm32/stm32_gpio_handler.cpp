#include "stm32_gpio_handler.hpp"

#include <main.h>

namespace Handlers
{
	namespace STM32
	{

		GPIO::GPIO() : GPIO_Handler(), m_port(0u), m_pin(0u)
		{
			m_board = BOARD_TYPE::STM32;
		}

		GPIO::GPIO(const uint32_t port, const uint32_t pin) : GPIO_Handler(), m_port(port), m_pin(pin)
		{
			m_board = BOARD_TYPE::STM32;
		}

		GPIO::~GPIO()
		{

		}

		void GPIO::setType(const GPIO_Handler::GPIO_TYPE mode)
		{
			switch(mode)
			{
			case(GPIO_TYPE::INPUT):
			{
				GPIO_InitTypeDef GPIO_InitStruct = {0};
				GPIO_InitStruct.Pin = m_pin;
				GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
				GPIO_InitStruct.Pull = GPIO_PULLUP;
				HAL_GPIO_Init((GPIO_TypeDef *)m_port, &GPIO_InitStruct);
				m_type = GPIO_TYPE::INPUT;
				break;
			}
			case(GPIO_TYPE::OUTPUT):
			{
				GPIO_InitTypeDef GPIO_InitStruct = {0};
				GPIO_InitStruct.Pin = m_pin;
				GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
				GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
				HAL_GPIO_Init((GPIO_TypeDef *)m_port, &GPIO_InitStruct);
				m_type = GPIO_TYPE::OUTPUT;
				break;
			}
			default:
				m_type = GPIO_TYPE::NONE;
				break;
			}
		}

		void GPIO::setHigh()
		{
			HAL_GPIO_WritePin((GPIO_TypeDef *)m_port, m_pin, GPIO_PIN_SET);
		}

		void GPIO::setLow()
		{
			HAL_GPIO_WritePin((GPIO_TypeDef *)m_port, m_pin, GPIO_PIN_RESET);
		}

		void GPIO::toggle()
		{
			if(GPIO_PinState::GPIO_PIN_RESET == HAL_GPIO_ReadPin((GPIO_TypeDef *)m_port, m_pin))
			{
				HAL_GPIO_WritePin((GPIO_TypeDef *)m_port, m_pin, GPIO_PIN_SET);
			}
			else
			{
				HAL_GPIO_WritePin((GPIO_TypeDef *)m_port, m_pin, GPIO_PIN_RESET);
			}
		}

		GPIO_Handler::GPIO_STATUS GPIO::getStatus()
		{
			GPIO_STATUS retVal = GPIO_STATUS::HIGH;
			if(GPIO_PIN_RESET == HAL_GPIO_ReadPin((GPIO_TypeDef *)m_port, m_pin))
			{
				retVal = GPIO_STATUS::LOW;
			}
			return retVal;
		}

		bool GPIO::waitUntil(const GPIO_Handler::GPIO_STATUS status, const uint32_t threshold)
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

		bool GPIO::waitUntilFor(const GPIO_STATUS status, Handlers::Timer_Handler* timer, const uint32_t wait_time)
		{
			if(GPIO_Handler::GPIO_STATUS::HIGH == status || GPIO_Handler::GPIO_STATUS::LOW == status)
			{
				timer->resetCounter();
				while(status != this->getStatus() && (timer->getTimeCounter() < wait_time));
			}
			return this->getStatus() == status;
		}

		uint32_t GPIO::durationState(const GPIO_STATUS status, Handlers::Timer_Handler* timer)
		{
			timer->resetCounter();
			while(status == this->getStatus());
			return timer->getTimeCounter();
		}

		// setters
		void GPIO::setPort(const uint32_t port)
		{
			m_port = port;
		}

		void GPIO::setPin(const uint32_t pin)
		{
			m_pin = pin;
		}
	}
}
