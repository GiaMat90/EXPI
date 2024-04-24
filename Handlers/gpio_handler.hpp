/*
 * gpio_handler.hpp
 *
 *  Created on: Jan 4, 2024
 *      Author: giaco
 */

#ifndef GPIO_HANDLER_HPP_
#define GPIO_HANDLER_HPP_

#include "handlers.hpp"
#include "timer_handler.hpp"
#include <limits>

namespace Handlers
{
	class GPIO_Handler : public Handler
	{
	public:
		enum class GPIO_STATUS : uint8_t
		{
			LOW = 0,
			HIGH = 1,
			NONE = std::numeric_limits<uint8_t>::max()
		};
		enum class GPIO_TYPE : uint8_t
		{
			INPUT = 0,
			OUTPUT = 1,
			NONE = std::numeric_limits<uint8_t>::max()
		};
		GPIO_Handler();
		GPIO_Handler(const uint32_t port, const uint32_t pin);
		~GPIO_Handler();
		void setType(const GPIO_TYPE mode);
		void setStatus(const GPIO_STATUS status);
		void setHigh();
		void setLow();
		void toggle();
		void glitch();
		GPIO_STATUS getStatus();
		GPIO_TYPE getType();
		bool waitUntil(const GPIO_STATUS status, const uint32_t threshold = 100u);
		bool waitUntilFor(const GPIO_STATUS status, const Handlers::Timer_Handler* timer, const uint32_t wait_time);
		uint32_t durationState(const GPIO_STATUS status, const Handlers::Timer_Handler* timer);
	private:
		void portSetType(const GPIO_TYPE mode);
	private:
		GPIO_TYPE m_type = GPIO_TYPE::NONE;
		uint32_t m_port = 0u;
		uint32_t m_pin = 0u;

	};
}

#endif /* GPIO_HANDLER_HPP_ */
