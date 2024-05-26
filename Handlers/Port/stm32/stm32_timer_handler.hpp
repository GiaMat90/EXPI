/*
 * timer_port_stm32.cpp
 *
 *  Created on: Feb 23, 2024
 *      Author: giaco
 */

#include "../../timer_handler.hpp"

#include <main.h>

namespace Handlers
{
	namespace STM32
	{
		class Timer : public Timer_Handler
		{
		public:
			Timer();
			Timer(const TIM_HandleTypeDef *hTim);
			Timer(const Timer& other);
			~Timer();
			void resetCounter() override;
			uint32_t getTimeCounter() override;
			void waitFor(const uint32_t time) override;
		private:
			TIM_HandleTypeDef* m_tim;
		};
	}
}
