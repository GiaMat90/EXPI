/*
 * time_handler.cpp
 *
 *  Created on: Jan 6, 2024
 *      Author: giaco
 */

#include "timer_handler.hpp"

namespace Handlers
{
Timer_Handler::Timer_Handler() : Handler(), m_tim(nullptr) {}


	Timer_Handler::Timer_Handler(const TIM_HandleTypeDef *hTim) : Handler(), m_tim(hTim)
	{
		HAL_TIM_Base_Start(m_tim);
	}

	Timer_Handler::Timer_Handler(const Timer_Handler& other) : Handler()
	{
		m_tim = other.m_tim;
	}

	Timer_Handler::~Timer_Handler()
	{

	}

	void Timer_Handler::resetCounter()
	{
		__HAL_TIM_SET_COUNTER(m_tim, 0);
	}

	uint32_t Timer_Handler::getTimeCounter()
	{
		return __HAL_TIM_GET_COUNTER(m_tim);
	}

	void Timer_Handler::waitFor(const uint32_t time)
	{
		__HAL_TIM_SET_COUNTER(m_tim, 0);
		while( __HAL_TIM_GET_COUNTER(m_tim) < time);
	}
}


