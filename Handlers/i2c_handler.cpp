/*
 * i2c_handler.cpp
 *
 *  Created on: Jan 20, 2024
 *      Author: giaco
 */
#include "i2c_handler.hpp"

namespace Handlers
{
	I2C_Handler::I2C_Handler() : Handler()
	{

	}

	I2C_Handler::I2C_Handler(const I2C_HandleTypeDef* hi2c, const uint32_t address) :
			Handler(), m_hi2c(hi2c), m_address(address), m_status(I2C_STATUS::NONE)
	{

	}

	I2C_Handler::I2C_Handler(const I2C_Handler& other) : Handler(), m_status(I2C_STATUS::NONE)
	{
		this->m_hi2c = other.m_hi2c;
		this->m_address = other.m_address;
	}

	I2C_Handler::~I2C_Handler()
	{

	}

	void I2C_Handler::init(const uint32_t trials, const uint32_t timeout)
	{
		if(nullptr != m_hi2c)
		{
			setStatus(HAL_I2C_IsDeviceReady(m_hi2c, m_address, trials, timeout));
		}
	}

	void I2C_Handler::send(uint8_t *packet, uint16_t size_packet, uint32_t timeout)
	{
		if(nullptr != m_hi2c)
		{
			setStatus(HAL_I2C_Master_Transmit(m_hi2c, m_address, packet, size_packet, timeout));
		}
	}

	I2C_Handler::I2C_STATUS I2C_Handler::getStatus() const
	{
		return m_status;
	}

	I2C_Handler::I2C_ERROR I2C_Handler::getError() const
	{
		return m_error;
	}

	// private methods
	void I2C_Handler::setStatus(const HAL_StatusTypeDef status)
	{
		switch(status)
		{
		case HAL_OK:
			m_status = I2C_STATUS::I2C_OK;
			break;
		case HAL_BUSY:
			m_status = I2C_STATUS::I2C_BUSY;
			break;
		case HAL_TIMEOUT:
			m_status = I2C_STATUS::I2C_TIMEOUT;
			break;
		case HAL_ERROR:
			m_status = I2C_STATUS::I2C_ERROR;
			setError(m_hi2c->ErrorCode);
			break;
		default:
			m_status = I2C_STATUS::NONE;
		}
	}

	void I2C_Handler::setError(const uint32_t error)
	{
		switch(error)
		{
		case HAL_I2C_ERROR_NONE:
			m_error = I2C_ERROR::NONE;
			break;
		case HAL_I2C_ERROR_BERR:
			m_error = I2C_ERROR::BERR;
			break;
		case HAL_I2C_ERROR_ARLO:
			m_error = I2C_ERROR::ARLO;
			break;
		case HAL_I2C_ERROR_AF:
			m_error = I2C_ERROR::ACKF;
			break;
		case HAL_I2C_ERROR_OVR:
			m_error = I2C_ERROR::OVR;
			break;
		case HAL_I2C_ERROR_DMA:
			m_error = I2C_ERROR::DMA;
			break;
		case HAL_I2C_ERROR_TIMEOUT:
			m_error = I2C_ERROR::TIMEOUT;
			break;
		case HAL_I2C_ERROR_SIZE:
			m_error = I2C_ERROR::SIZE;
			break;
		case HAL_I2C_ERROR_DMA_PARAM:
			m_error = I2C_ERROR::DMA_PARAM;
			break;
#ifdef HAL_I2C_ERROR_INVALID_CALLBACK
		case HAL_I2C_ERROR_INVALID_CALLBACK:
			m_error = I2C_ERROR::INVALID_CALLBACK;
			break;
#endif
		case HAL_I2C_ERROR_INVALID_PARAM:
			m_error = I2C_ERROR::INVALID_PARAM;
			break;
		default:
			m_error = I2C_ERROR::NOT_SETTED;
		}
	}
}
