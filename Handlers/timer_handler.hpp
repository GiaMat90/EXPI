/*
 * time_handler.hpp
 *
 *  Created on: Jan 6, 2024
 *      Author: giaco
 */

#ifndef TIMER_HANDLER_HPP_
#define TIMER_HANDLER_HPP_

#include "handlers.hpp"
#include <stdint.h>	// uint32_t

namespace Handlers
{
	class Timer_Handler : public Handler
	{
	public:
		Timer_Handler();
		Timer_Handler(const Timer_Handler& other);
		~Timer_Handler();
		virtual void resetCounter() = 0;
		virtual void waitFor(const uint32_t time) = 0;
		virtual uint32_t getTimeCounter() = 0;
	};

}



#endif /* TIMER_HANDLER_HPP_ */
