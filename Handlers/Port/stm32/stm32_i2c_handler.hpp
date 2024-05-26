/*
 * i2c_handle.hpp
 *
 *  Created on: Jan 20, 2024
 *      Author: giaco
 */

#ifndef STM32_I2C_HANDLER_HPP_
#define STM32_I2C_HANDLER_HPP_

#include "../../i2c_handler.hpp"
#include <main.h>

namespace Handlers
{
	namespace STM32
	{
		class I2C : public I2C_Handler
		{
		public:
			I2C();
			I2C(const I2C_HandleTypeDef *hi2c, const uint32_t address);
			I2C(const I2C& other);
			~I2C();
			void init(const uint32_t trials, const uint32_t timeout) override;
			void send(uint8_t *packet, uint16_t size_packet, uint32_t timeout) override;
			I2C_Handler::I2C_STATUS getStatus() const;
			I2C_Handler::I2C_ERROR getError() const;
		private:
			void setStatus(const HAL_StatusTypeDef status);
			void setError(const uint32_t error);
		private:
			I2C_HandleTypeDef* m_hi2c = nullptr;
			uint32_t m_address = 0x0;
			I2C_Handler::I2C_STATUS m_status = I2C_STATUS::NONE;
			I2C_Handler::I2C_ERROR m_error = I2C_ERROR::NOT_SETTED;
		};
	}
}



#endif /* I2C_HANDLER_HPP_ */
