/*
 * sensors.hpp
 *
 *  Created on: Feb 4, 2024
 *      Author: giaco
 */

#ifndef SENSORS_HPP_
#define SENSORS_HPP_

#include <cstdint>
#include <limits>

#define ERROR_DESCRIPTION_SIZE 100u

namespace Sensors
{
	class Sensor
	{
	public:
		enum class SENSOR_STATUS : uint8_t
		{
			SENSOR_OK,
			SENSOR_ERROR,
			SENSOR_NONE = std::numeric_limits<uint8_t>::max(),
		};
		enum class SENSOR_ERROR
		{
			NONE,
			ERROR_CONFIG,
			ERROR_START,
			ERROR_READING
		};
		Sensor(){};
		virtual ~Sensor(){};
	protected:
		void resetErrors();
	protected:
		SENSOR_STATUS m_status = SENSOR_STATUS::SENSOR_NONE;
		SENSOR_ERROR m_error = SENSOR_ERROR::NONE;
		char m_errorDescription[ERROR_DESCRIPTION_SIZE] = {0};
	};
}




#endif /* SENSORS_HPP_ */
