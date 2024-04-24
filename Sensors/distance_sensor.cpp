/*
 * distance_sensor.cpp
 *
 *  Created on: Feb 4, 2024
 *      Author: giaco
 */
#include "distance_sensor.hpp"

namespace Sensors
{
	Distance_Sensor::Distance_Sensor() : Sensor()
	{

	};

	Distance_Sensor::Distance_Sensor(Timer_Handler* timeHandler, GPIO_Handler* gpioEcho, GPIO_Handler* gpioTrigger) :
			Sensor(), m_time(timeHandler), m_gpioEcho(gpioEcho), m_gpioTrigger(gpioTrigger)
	{

	}

	Distance_Sensor::~Distance_Sensor()
	{

	}

	uint16_t Distance_Sensor::getDistance(const UNITY_MEASURE& um)
	{
		// distance sensor routine
		m_gpioTrigger->setHigh();
		m_time->waitFor(10u);
		m_gpioTrigger->setLow();
		m_time->waitFor(10u);
		//
		m_gpioEcho->waitUntil(GPIO_Handler::GPIO_STATUS::HIGH);
		uint32_t start = m_time->getTimeCounter();
		m_gpioEcho->waitUntil(GPIO_Handler::GPIO_STATUS::LOW);
		uint32_t end = m_time->getTimeCounter();
		uint32_t elapsed = end - start;
		uint16_t distance = 0;
		float sound_speed = 0.0f;
		switch(um)
		{
		case(UNITY_MEASURE::MILLIMETERS):
				sound_speed = 1000.0f * 0.034f; // mm/us
				distance = elapsed*(sound_speed / 2.0f);
				break;
		case(UNITY_MEASURE::CENTIMETERS):
				sound_speed = 0.034f; // cm/us
				distance = elapsed*(sound_speed / 2.0f);
				break;
		case(UNITY_MEASURE::METERS):
				sound_speed = 0.034f / 100.0f; // cm/us
				distance = elapsed*(sound_speed / 2.0f);
				break;
		default:
			break;
		}
		return distance;
	}
}



