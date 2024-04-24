/*
 * uart_handler.hpp
 *
 *  Created on: Dec 30, 2023
 *      Author: giaco
 */

#ifndef UART_HANDLER_HPP_
#define UART_HANDLER_HPP_

#include "handlers.hpp"
#include <main.h>
#include <string>

namespace Handlers
{

	class UART_Handler : public Handler
	{
	public:
		enum class UART_MODE
		{
			NONE,
			POLLING,
			INTERRUPT,
			DMA
		};

		enum class UART_STATUS
		{
			NONE,
			OK,
			ERROR
		};

		UART_Handler(UART_HandleTypeDef* huart = nullptr, UART_MODE mode = UART_MODE::NONE);
		~UART_Handler();
		UART_STATUS receive(uint8_t* buffer);
		UART_STATUS receive(uint8_t* buffer, const UART_MODE mode, const uint32_t delay = 0u);
		UART_STATUS send(uint8_t* buffer, size_t size = 0u);
		UART_STATUS send(const std::string& msg);
	private:
		UART_HandleTypeDef* m_huart = nullptr;
		UART_MODE m_mode = UART_MODE::NONE;
		UART_STATUS m_status = UART_STATUS::NONE;
	};
}

#endif /* UART_HANDLER_HPP_ */
