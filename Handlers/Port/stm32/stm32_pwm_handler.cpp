/*
 * stm32_pwm_handler.cpp
 *
 */

#include "stm32_pwm_handler.hpp"
#include <main.h>

namespace Handlers
{
	namespace STM32
	{
		PWM::PWM(TIM_HandleTypeDef *hTim, const uint32_t channel) :
				PWM_Handler(), m_hTim(hTim), m_channel(channel)
		{
		}

		PWM::~PWM()
		{

		}

		void PWM::start() const
		{
			HAL_TIM_PWM_Start(m_hTim, m_channel);
		}

		void PWM::set_duty_cycle(const uint8_t dc)
		{
			m_hTim->Instance->CCR1 = (m_hTim->Init.Period * dc) / 100;
		}
	}
}
