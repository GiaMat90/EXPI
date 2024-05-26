/*
 * timer_port_stm32.cpp
 *
 *  Created on: Feb 23, 2024
 *      Author: giaco
 */

#ifndef STM32_DAC_HANDLER_HPP_
#define STM32_DAC_HANDLER_HPP_

#include "../../dac_handler.hpp"
#include <main.h>

namespace Handlers
{
	namespace STM32
	{
		class DAConverter : public DAC_Handler
		{
		public:
			DAConverter(DAC_HandleTypeDef* hDac = nullptr, const uint32_t channel = 0u);
			~DAConverter();
			void init() override;
			void start() override;
			void setValue(const uint32_t value) override;
		private:
			DAC_HandleTypeDef* m_dacHandle = nullptr;
			uint32_t m_channel = 0u;
		};
	}
}

#endif
