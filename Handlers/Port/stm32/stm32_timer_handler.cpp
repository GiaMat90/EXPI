/*
 * timer_port_stm32.cpp
 *
 *  Created on: Feb 23, 2024
 *      Author: giaco
 */

#include "stm32_timer_handler.hpp"

namespace Handlers
{
	namespace STM32
	{
		Timer::Timer()
		{

		}

		Timer::Timer(const TIM_HandleTypeDef *hTim) : Timer_Handler(), m_tim(hTim)
		{
			HAL_TIM_Base_Start(static_cast<TIM_HandleTypeDef*>(m_tim));
		}

		Timer::Timer(const Timer& other) : Timer_Handler()
		{
			m_tim = other.m_tim;
		}

		Timer::~Timer()
		{

		}

		void Timer::resetCounter()
		{
			__HAL_TIM_SET_COUNTER(static_cast<TIM_HandleTypeDef*>(m_tim), 0);
		}

		uint32_t Timer::getTimeCounter()
		{
			return __HAL_TIM_GET_COUNTER(static_cast<TIM_HandleTypeDef*>(m_tim));
		}

		void Timer::waitFor(const uint32_t time)
		{
			__HAL_TIM_SET_COUNTER(static_cast<TIM_HandleTypeDef*>(m_tim), 0);
			while( __HAL_TIM_GET_COUNTER(static_cast<TIM_HandleTypeDef*>(m_tim)) < time);
		}

	}
}
