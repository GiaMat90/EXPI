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

	I2C_Handler::~I2C_Handler()
	{

	}

	I2C_Handler::I2C_STATUS I2C_Handler::getStatus() const
	{
		return m_status;
	}

	I2C_Handler::I2C_ERROR I2C_Handler::getError() const
	{
		return m_error;
	}
}
