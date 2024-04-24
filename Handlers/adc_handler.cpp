/*
 * adc_handler.cpp
 *
 *  Created on: Dec 30, 2023
 *      Author: giaco
 */

#include "adc_handler.hpp"

namespace Handlers
{
	ADC_Handler::ADC_Handler(ADC_HandleTypeDef* hadc) :
			Handler(), m_hadc(hadc)
	{

	}

	ADC_Handler::~ADC_Handler()
	{

	}

	void ADC_Handler::startPolling(const uint32_t delay)
	{
		HAL_ADC_Start(m_hadc);
		HAL_ADC_PollForConversion(m_hadc, delay);
	}

	uint32_t ADC_Handler::getValue() const
	{
		return HAL_ADC_GetValue(m_hadc);
	}
}


