/*
 * timer_port_stm32.cpp
 *
 *  Created on: Feb 23, 2024
 *      Author: giaco
 */

#include "stm32_dac_handler.hpp"

namespace Handlers
{
	namespace STM32
	{
		DAConverter::DAConverter(DAC_HandleTypeDef* hDac, const uint32_t channel) :
				DAC_Handler(), m_dacHandle(hDac), m_channel(channel)
		{
		}

		DAConverter::~DAConverter()
		{

		}

		void DAConverter::init()
		{
			HAL_DAC_Init(m_dacHandle);
		}

		void DAConverter::start()
		{
			HAL_DAC_Start(m_dacHandle, m_channel);
		}

		void DAConverter::setValue(const uint32_t value)
		{
			HAL_StatusTypeDef status = HAL_DAC_SetValue(m_dacHandle, m_channel, DAC_ALIGN_12B_R, value);
			if(HAL_OK != status)
			{
				asm("NOP");
			}
		}
	}
}
