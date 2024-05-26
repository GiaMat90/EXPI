/*
 * timer_port_stm32.cpp
 *
 *  Created on: Feb 23, 2024
 *      Author: giaco
 */

#include "../../pwm_handler.hpp"

#include <main.h>

namespace Handlers
{
	namespace STM32
	{
		class PWM : public PWM_Handler
		{
		public:
			PWM(TIM_HandleTypeDef *hTim, const uint32_t channel);
			~PWM();
			void start() const override;
			void set_duty_cycle(const uint8_t dc) override;
		private:
			TIM_HandleTypeDef* m_hTim = nullptr;
			uint32_t m_channel = 0u;
		};
	}
}
