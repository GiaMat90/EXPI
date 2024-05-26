/*
 * timer_port_stm32.cpp
 *
 *  Created on: Feb 23, 2024
 *      Author: giaco
 */

#include "stm32_adc_handler.hpp"
#include <main.h>

namespace Handlers
{
	namespace STM32
	{
		ADC::ADC(ADC_HandleTypeDef* hadc) : m_hadc(hadc)
		{

		}

		ADC::~ADC()
		{

		}

		void ADC::startPolling(const uint32_t delay)
		{
			HAL_ADC_Start(m_hadc);
			HAL_ADC_PollForConversion(m_hadc, delay);
		}

		uint32_t ADC::getValue() const
		{
			return HAL_ADC_GetValue(m_hadc);
		}
	}
}
