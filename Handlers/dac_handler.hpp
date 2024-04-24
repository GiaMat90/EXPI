/*
 * dac.hpp
 *
 *  Created on: Dec 30, 2023
 *      Author: giaco
 */

#ifndef DAC_HANDLER_HPP_
#define DAC_HANDLER_HPP_

#include "handlers.hpp"
#include <main.h>

namespace Handlers
{
	class DAC_Handler : public Handler
	{
	public:
		DAC_Handler(DAC_HandleTypeDef* hDac = nullptr, const uint32_t channel = 0u);
		~DAC_Handler();
		void init();
		void start();
		void setValue(const uint32_t value);
	private:
		DAC_HandleTypeDef* m_dacHandle = nullptr;
		uint32_t m_channel = 0u;
	};
}

#endif
