/*
 * adc_handler.hpp
 *
 *  Created on: Dec 30, 2023
 *      Author: giaco
 */

#ifndef ADC_HANDLER_HPP_
#define ADC_HANDLER_HPP_

#include "handlers.hpp"
#include <main.h>

namespace Handlers
{
	class ADC_Handler : public Handler
	{
	public:
		ADC_Handler(ADC_HandleTypeDef* hadc = nullptr);
		~ADC_Handler();
		void startPolling(const uint32_t delay);
		uint32_t getValue() const;
	private:
		ADC_HandleTypeDef* m_hadc = nullptr;
	};
}

#endif /* ADC_HANDLER_HPP_ */
