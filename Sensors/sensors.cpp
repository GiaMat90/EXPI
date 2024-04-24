/*
 * sensors.cpp
 *
 *  Created on: Mar 16, 2024
 *      Author: giaco
 */

#include "sensors.hpp"
#include <string.h>

namespace Sensors
{
	void Sensor::resetErrors()
	{
		m_status = SENSOR_STATUS::SENSOR_NONE;
		m_error = SENSOR_ERROR::NONE;
		memset(m_errorDescription, 0, sizeof(m_errorDescription));
	}
}
