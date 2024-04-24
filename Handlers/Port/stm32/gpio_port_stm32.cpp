#include "../../gpio_handler.hpp"

namespace Handlers
{
	void GPIO_Handler::portSetType(const GPIO_Handler::GPIO_TYPE mode)
	{
		switch(mode)
		{
		case(GPIO_TYPE::INPUT):
		{
			GPIO_InitTypeDef GPIO_InitStruct = {0};
			GPIO_InitStruct.Pin = m_pin;
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
			GPIO_InitStruct.Pull = GPIO_PULLUP;
			HAL_GPIO_Init((GPIO_TypeDef *)m_port, &GPIO_InitStruct);
			m_type = GPIO_TYPE::INPUT;
			break;
		}
		case(GPIO_TYPE::OUTPUT):
		{
			GPIO_InitTypeDef GPIO_InitStruct = {0};
			GPIO_InitStruct.Pin = m_pin;
			GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
			HAL_GPIO_Init((GPIO_TypeDef *)m_port, &GPIO_InitStruct);
			m_type = GPIO_TYPE::OUTPUT;
			break;
		}
		default:
			m_type = GPIO_TYPE::NONE;
			break;
		}
	}
}
