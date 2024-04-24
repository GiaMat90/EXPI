/*
 * i2c_handle.hpp
 *
 *  Created on: Jan 20, 2024
 *      Author: giaco
 */

#ifndef I2C_HANDLER_HPP_
#define I2C_HANDLER_HPP_

#include "handlers.hpp"
#include <main.h>

namespace Handlers
{
	class I2C_Handler : public Handler
	{
	public:
		enum class I2C_STATUS : uint8_t
		{
			NONE,
			I2C_OK,
			I2C_BUSY,
			I2C_TIMEOUT,
			I2C_ERROR
		};

		enum class I2C_ERROR : uint32_t
		{
			NONE,
			BERR,
			ARLO,
			ACKF,
			OVR,
			DMA,
			TIMEOUT,
			SIZE,
			DMA_PARAM,
			INVALID_CALLBACK,
			INVALID_PARAM,
			NOT_SETTED
		};
		I2C_Handler();
		I2C_Handler(const I2C_HandleTypeDef *hi2c, const uint32_t address);
		I2C_Handler(const I2C_Handler& other);
		~I2C_Handler();
		void init(const uint32_t trials, const uint32_t timeout);
		void send(uint8_t *packet, uint16_t size_packet, uint32_t timeout);
		I2C_STATUS getStatus() const;
		I2C_ERROR getError() const;
	private:
		void setStatus(const HAL_StatusTypeDef status);
		void setError(const uint32_t error);
	private:
		I2C_HandleTypeDef* m_hi2c = nullptr;
		uint32_t m_address = 0x0;
		I2C_STATUS m_status = I2C_STATUS::NONE;
		I2C_ERROR m_error = I2C_ERROR::NOT_SETTED;
	};

}



#endif /* I2C_HANDLER_HPP_ */
