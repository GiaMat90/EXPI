/*
 * pwm_handler.cpp
 *
 *  Created on: Dec 30, 2023
 *      Author: giaco
 */
#include "pwm_handler.hpp"

namespace Handlers
{
	PWM_Handler::PWM_Handler(TIM_HandleTypeDef *hTim, const uint32_t channel) :
			Handler(), m_hTim(hTim), m_channel(channel)
	{
	}

	PWM_Handler::~PWM_Handler()
	{

	}

	void PWM_Handler::start() const
	{
		HAL_TIM_PWM_Start(m_hTim, m_channel);
	}

	void PWM_Handler::set_duty_cycle(const uint8_t dc)
	{
		m_hTim->Instance->CCR1 = (m_hTim->Init.Period * dc) / 100;
	}
}


