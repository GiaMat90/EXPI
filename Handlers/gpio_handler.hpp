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
		GPIO_Handler() : Handler(), m_type(GPIO_TYPE::NONE) {};
		virtual ~GPIO_Handler(){};
		// factory method
		static GPIO_Handler* makeGPIO(const BOARD_TYPE board = BOARD_TYPE::UNDEFINED);
		// overloaded methods
		virtual void setType(const GPIO_TYPE mode) = 0;
		virtual void setHigh() = 0;
		virtual void setLow() = 0;
		virtual void toggle() = 0;
		virtual GPIO_STATUS getStatus() = 0;
		virtual bool waitUntil(const GPIO_STATUS status, const uint32_t threshold = 100u) = 0;
		virtual bool waitUntilFor(const GPIO_STATUS status, Handlers::Timer_Handler* timer, const uint32_t wait_time) = 0;
		virtual uint32_t durationState(const GPIO_STATUS status, Handlers::Timer_Handler* timer) = 0;
		// class methods
		virtual void glitch();
		void setStatus(const GPIO_STATUS status);
		// inline methods
		inline GPIO_TYPE getType() { return m_type; };
	protected:
		GPIO_TYPE m_type = GPIO_TYPE::NONE;
	};
}

#endif /* GPIO_HANDLER_HPP_ */
