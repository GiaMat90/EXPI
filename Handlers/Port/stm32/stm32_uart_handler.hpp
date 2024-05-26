/*
 * timer_port_stm32.cpp
 *
 *  Created on: Feb 23, 2024
 *      Author: giaco
 */

#ifndef STM32_UART_HANDLER_HPP_
#define STM32_UART_HANDLER_HPP_

#include "../../uart_handler.hpp"

#include <main.h>

namespace Handlers
{
	namespace STM32
	{
		class UART : public UART_Handler
		{
		public:
			UART(UART_HandleTypeDef* huart = nullptr, UART_MODE mode = UART_MODE::NONE);
			~UART();
			UART_STATUS receive(uint8_t* buffer) override;
			UART_STATUS send(uint8_t* buffer, size_t size = 0u) override;
		private:
			UART_HandleTypeDef* m_huart = nullptr;
		};
	}
}

#endif
