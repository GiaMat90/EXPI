/*
 * timer_port_stm32.cpp
 *
 *  Created on: Feb 23, 2024
 *      Author: giaco
 */

#include "stm32_uart_handler.hpp"

namespace Handlers
{
	namespace STM32
	{
		UART::UART(UART_HandleTypeDef* huart, UART_MODE mode) :
				UART_Handler(mode), m_huart(huart)
		{
		}

		UART::~UART()
		{

		}

		UART::UART_STATUS UART::receive(uint8_t* buffer)
		{
			HAL_StatusTypeDef rxStatus = HAL_UART_Receive_IT(m_huart, buffer, sizeof(buffer));
			if(HAL_OK != rxStatus)
			{
				m_status = UART_STATUS::ERROR;
			}
			else
			{
				m_status = UART_STATUS::OK;
			}

			return m_status;
		}

		UART::UART_STATUS UART::send(uint8_t* buffer, size_t size)
		{
			if(size == 0u)
			{
				size = sizeof(buffer);
			}
			HAL_StatusTypeDef txStatus = HAL_UART_Transmit_IT(m_huart, buffer, size);
			if(HAL_OK != txStatus)
			{
				m_status = UART_STATUS::ERROR;
			}
			else
			{
				m_status = UART_STATUS::OK;
			}
		}
	}
}
