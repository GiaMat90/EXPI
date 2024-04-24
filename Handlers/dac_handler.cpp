/*
 * dac_handler.cpp
 *
 *  Created on: Dec 30, 2023
 *      Author: giaco
 */

#include "dac_handler.hpp"

namespace Handlers
{
	DAC_Handler::DAC_Handler(DAC_HandleTypeDef* hDac, const uint32_t channel) :
			Handler(), m_dacHandle(hDac), m_channel(channel)
	{
	}

	DAC_Handler::~DAC_Handler()
	{
	}

	void DAC_Handler::init()
	{
		HAL_DAC_Init(m_dacHandle);
	}

	void DAC_Handler::start()
	{
		HAL_DAC_Start(m_dacHandle, m_channel);
	}

	void DAC_Handler::setValue(const uint32_t value)
	{
		HAL_StatusTypeDef status = HAL_DAC_SetValue(m_dacHandle, m_channel, DAC_ALIGN_12B_R, value);
		if(HAL_OK != status)
		{
			asm("NOP");
		}
	}
}



