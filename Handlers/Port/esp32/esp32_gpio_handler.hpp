#ifndef STM32_GPIO_HANDLER_HPP_
#define STM32_GPIO_HANDLER_HPP_

#include "../../gpio_handler.hpp"

namespace Handlers
{
	namespace STM32
	{
		class GPIO : public GPIO_Handler
		{
		public:
			GPIO();
			GPIO(const uint32_t port, const uint32_t pin);
			~GPIO();
			// override methods
			void setType(const GPIO_TYPE mode) override;
			void setHigh() override;
			void setLow() override;
			void toggle() override;
			GPIO_STATUS getStatus() override;
			bool waitUntil(const GPIO_STATUS status, const uint32_t threshold = 100u) override;
			bool waitUntilFor(const GPIO_STATUS status, Handlers::Timer_Handler* timer, const uint32_t wait_time) override;
			uint32_t durationState(const GPIO_STATUS status, Handlers::Timer_Handler* timer) override;
			// setters
			void setPort(const uint32_t port);
			void setPin(const uint32_t pin);
		private:
			uint32_t m_port = 0u;
			uint32_t m_pin = 0u;
		};
	}
}

#endif
