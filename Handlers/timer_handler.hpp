/*
 * time_handler.hpp
 *
 *  Created on: Jan 6, 2024
 *      Author: giaco
 */

#ifndef TIMER_HANDLER_HPP_
#define TIMER_HANDLER_HPP_

#include "handlers.hpp"
#include <main.h>

namespace Handlers
{
	class Timer_Handler : public Handler
	{
	public:
		Timer_Handler();
		Timer_Handler(const TIM_HandleTypeDef *hTim);
		Timer_Handler(const Timer_Handler& other);
		~Timer_Handler();
		void resetCounter();
		void waitFor(const uint32_t time);
		uint32_t getTimeCounter();
	private:
		TIM_HandleTypeDef* m_tim = nullptr;
	};

}



#endif /* TIMER_HANDLER_HPP_ */
