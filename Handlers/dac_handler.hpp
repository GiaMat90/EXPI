/*
 * dac.hpp
 *
 *  Created on: Dec 30, 2023
 *      Author: giaco
 */

#ifndef DAC_HANDLER_HPP_
#define DAC_HANDLER_HPP_

#include "handlers.hpp"

namespace Handlers
{
	class DAC_Handler : public Handler
	{
	public:
		DAC_Handler();
		~DAC_Handler();
		virtual void init() = 0;
		virtual void start() = 0;
		virtual void setValue(const uint32_t value) = 0;
	};
}

#endif
