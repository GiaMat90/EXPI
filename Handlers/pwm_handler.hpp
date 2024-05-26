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
		PWM_Handler();
		~PWM_Handler();
		virtual void start() const = 0;
		virtual void set_duty_cycle(const uint8_t dc) = 0;
	};
}

#endif /* PWM_HANDLER_HPP_ */
