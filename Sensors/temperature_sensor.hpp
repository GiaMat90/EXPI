/*
 * temperature_sensor.hpp
 *
 *  Created on: Feb 4, 2024
 *      Author: giaco
 */

#ifndef TEMPERATURE_SENSOR_HPP_
#define TEMPERATURE_SENSOR_HPP_

#include "sensors.hpp"
#include "../Handlers/gpio_Handler.hpp"
#include "../Handlers/timer_handler.hpp"

using Handlers::Timer_Handler;
using Handlers::GPIO_Handler;

#include <limits>

namespace Sensors
{
	class Temperature_Sensor : public Sensor
	{
	public:
		enum class UNITY_MEASURE : uint8_t
		{
			CELSIUS,
			FARENEITH
		};
		enum class TYPE : uint8_t
		{
			DHT11,
			DHT22,
			NONE = std::numeric_limits<uint8_t>::max()
		};
		Temperature_Sensor();
		Temperature_Sensor(Timer_Handler* timeHandler, GPIO_Handler* gpioHandler, const TYPE t = TYPE::DHT11);
		~Temperature_Sensor();
		void read();
		float getTemperature(const UNITY_MEASURE = UNITY_MEASURE::CELSIUS);
		float getHumidity();
	private:	// DHT11 methods
		void startDHT11();
		void checkResponseDHT11();
		void readDHT11();
		void sampleDHT11(uint8_t* data);
	private:	// DHT22 methods
		void startDHT22();
		void checkResponseDHT22();
		void readDHT22();
		void sampleDHT22(uint8_t* data);
	private:	// common methods
		uint8_t readByte(uint8_t* value);
		void parse();
	private:
		Timer_Handler* m_timer = nullptr;
		GPIO_Handler* m_gpio = nullptr;
		TYPE m_type = TYPE::NONE;
		float m_temperature = 0u;
		float m_humidity = 0u;
	};
}




#endif /* TEMPERATURE_SENSOR_HPP_ */
