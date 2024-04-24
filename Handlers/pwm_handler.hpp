/*
 * pwm_handler.hpp
 *
 *  Created on: Dec 30, 2023
 *      Author: giaco
 */

#ifndef PWM_HANDLER_HPP_
#define PWM_HANDLER_HPP_

#include "handlers.hpp"
#include "main.h"

namespace Handlers
{
	class PWM_Handler : public Handler
	{
	public:
		PWM_Handler(TIM_HandleTypeDef *hTim, const uint32_t channel);
		~PWM_Handler();
		void start() const;
		void set_duty_cycle(const uint8_t dc);
	private:
		TIM_HandleTypeDef* m_hTim = nullptr;
		uint32_t m_channel = 0u;
	};
}

#endif /* PWM_HANDLER_HPP_ */
