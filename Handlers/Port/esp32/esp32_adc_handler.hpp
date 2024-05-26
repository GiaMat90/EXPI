/*
 * timer_port_stm32.cpp
 *
 *  Created on: Feb 23, 2024
 *      Author: giaco
 */

#include "../../timer_handler.hpp"
#include <main.h>

namespace Handlers
{

	Timer_Handler::Timer_Handler(const void *hTim) : Handler(), m_tim(hTim)
	{
		HAL_TIM_Base_Start(static_cast<TIM_HandleTypeDef*>(m_tim));
	}

	void Timer_Handler::resetCounter()
	{
		__HAL_TIM_SET_COUNTER(static_cast<TIM_HandleTypeDef*>(m_tim), 0);
	}

	uint32_t Timer_Handler::getTimeCounter()
	{
		return __HAL_TIM_GET_COUNTER(static_cast<TIM_HandleTypeDef*>(m_tim));
	}

	void Timer_Handler::waitFor(const uint32_t time)
	{
		__HAL_TIM_SET_COUNTER(static_cast<TIM_HandleTypeDef*>(m_tim), 0);
		while( __HAL_TIM_GET_COUNTER(static_cast<TIM_HandleTypeDef*>(m_tim)) < time);
	}
}
