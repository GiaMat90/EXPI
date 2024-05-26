/*
 * timer_port_stm32.cpp
 *
 *  Created on: Feb 23, 2024
 *      Author: giaco
 */

#ifndef STM32_ADC_HANDLER_HPP_
#define STM32_ADC_HANDLER_HPP_

#include "../../adc_handler.hpp"

#include <main.h>

namespace Handlers
{
	namespace STM32
	{
		class ADC : public ADC_Handler
		{
		public:
			ADC(ADC_HandleTypeDef* hadc = nullptr);
			~ADC();
			void startPolling(const uint32_t delay) override;
			uint32_t getValue() const override;
		private:
			ADC_HandleTypeDef* m_hadc = nullptr;
		};
	}
}

#endif
