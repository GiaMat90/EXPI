/*
 * distance_sensor.hpp
 *
 *  Created on: Feb 4, 2024
 *      Author: giaco
 */

#ifndef DISTANCE_SENSOR_HPP_
#define DISTANCE_SENSOR_HPP_

#include "sensors.hpp"
#include "../Handlers/gpio_handler.hpp"
#include "../Handlers/timer_handler.hpp"

using Handlers::Timer_Handler;
using Handlers::GPIO_Handler;

namespace Sensors
{
	class Distance_Sensor : public Sensor
	{
	public:
		enum class UNITY_MEASURE : uint8_t
		{
			MILLIMETERS,
			CENTIMETERS,
			METERS
		};
		Distance_Sensor();
		Distance_Sensor(Timer_Handler* timeHandler, GPIO_Handler* gpioEcho, GPIO_Handler* gpioTrigger);
		~Distance_Sensor();
		uint16_t getDistance(const UNITY_MEASURE& um = UNITY_MEASURE::CENTIMETERS);
	private:
		Timer_Handler* m_time = nullptr;
		GPIO_Handler* m_gpioEcho = nullptr;
		GPIO_Handler* m_gpioTrigger = nullptr;
	};

}



#endif /* DISTANCE_SENSOR_HPP_ */
