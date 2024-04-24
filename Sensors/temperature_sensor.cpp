/*
 * temperature_sensor.cpp
 *
 *  Created on: 5 feb 2024
 *      Author: matzeg2
 */

#include "temperature_sensor.hpp"
#include <cstring>

namespace Sensors
{
	Temperature_Sensor::Temperature_Sensor() :
			Sensor(), m_timer(nullptr), m_gpio(nullptr), m_type(TYPE::NONE)
	{

	};

	Temperature_Sensor::Temperature_Sensor(Timer_Handler* timeHandler, GPIO_Handler* gpioHandler, const TYPE t) :
			Sensor(), m_timer(timeHandler), m_gpio(gpioHandler), m_type(t)
	{

	};

	Temperature_Sensor::~Temperature_Sensor()
	{

	}

	void Temperature_Sensor::read()
	{
		if(TYPE::DHT11 == m_type)
		{
			startDHT11();
			readDHT11();
		}
		else if(TYPE::DHT22 == m_type)
		{
			startDHT22();
			readDHT22();
		}
	}

	// Methods for DHT11
	void Temperature_Sensor::startDHT11()
	{
		resetErrors();
		m_gpio->setType(GPIO_Handler::GPIO_TYPE::OUTPUT);
		m_gpio->setLow();
		m_timer->waitFor(18000);
		m_gpio->setHigh();
		m_gpio->setType(GPIO_Handler::GPIO_TYPE::INPUT);
		checkResponseDHT11();
	}

	void Temperature_Sensor::checkResponseDHT11()
	{
		// wait the sensor pull down the gpio. It should last 40us of delay reading MCU signal
		if(m_gpio->waitUntilFor(GPIO_Handler::GPIO_STATUS::LOW, m_timer, 50u))
		{
			uint32_t time = m_gpio->durationState(GPIO_Handler::GPIO_STATUS::LOW, m_timer);
			if(time < 70u)	// should be 80
			{
				m_status = SENSOR_STATUS::SENSOR_ERROR;
				m_error = SENSOR_ERROR::ERROR_START;
				strcpy(m_errorDescription, "Failed wait gpio low for 80us");
			}
			else
			{
				time = m_gpio->durationState(GPIO_Handler::GPIO_STATUS::HIGH, m_timer);
				if(time < 70u)	// should be 80
				{
					m_status = SENSOR_STATUS::SENSOR_ERROR;
					m_error = SENSOR_ERROR::ERROR_START;
					strcpy(m_errorDescription, "Failed wait gpio high for 80us");
				}
				else
				{
					m_status = SENSOR_STATUS::SENSOR_OK;
				}
			}

		}
		else
		{
			m_status = SENSOR_STATUS::SENSOR_ERROR;
			m_error = SENSOR_ERROR::ERROR_START;
			strcpy(m_errorDescription, "Failed wait gpio low for 100us");
		}
	}

	void Temperature_Sensor::readDHT11()
	{
		uint8_t data[40u] = {0};
		sampleDHT11(data);
		if(SENSOR_STATUS::SENSOR_OK == m_status)
		{
			uint8_t humidity_byte1 = readByte(data);
			uint8_t humidity_byte2 = readByte(data + 8u);
			uint8_t temperature_byte1 = readByte(data + 16u);
			uint8_t temperature_byte2 = readByte(data + 24u);
			uint16_t sum = readByte(data + 32u);

			uint16_t check = static_cast<uint16_t>(humidity_byte1) + static_cast<uint16_t>(humidity_byte2) +
					static_cast<uint16_t>(temperature_byte1) + static_cast<uint16_t>(temperature_byte2);
			if(check != sum)
			{
				m_status = SENSOR_STATUS::SENSOR_ERROR;
				m_error = SENSOR_ERROR::ERROR_READING;
				strcpy(m_errorDescription, "Failed the checksum");
			}
			else
			{
				m_temperature = (float)temperature_byte1 + (float)temperature_byte2*0.1;
				m_humidity = (float)humidity_byte1 + (float)humidity_byte2*0.1;
			}
		}
	}

	void Temperature_Sensor::sampleDHT11(uint8_t* data)
	{
		// DHT11 data transmite:
		//    1. 1bit start, PULL LOW 50us
		//    2. PULL HIGH:
		//         - 26-28us, bit(0)
		//         - 70us, bit(1)
		uint32_t time = 0u;
		for (uint16_t j = 0; j < 40u; ++j)
		{
			  time = m_gpio->durationState(GPIO_Handler::GPIO_STATUS::LOW, m_timer); // 1.
			  if (time < 50u) // specs says: 50us
			  {
					m_status = SENSOR_STATUS::SENSOR_ERROR;
					m_error = SENSOR_ERROR::ERROR_READING;
					strcpy(m_errorDescription, "Failed wait gpio low for 50us");
			  }
			  else
			  {
				  // read a bit
				  time = m_gpio->durationState(GPIO_Handler::GPIO_STATUS::HIGH, m_timer);              // 2.
				  if (time < 20) // specs say: 20us
				  {
					  m_status = SENSOR_STATUS::SENSOR_ERROR;
					  m_error = SENSOR_ERROR::ERROR_READING;
					  strcpy(m_errorDescription, "Failed wait gpio high for 20us");
				  }
				  data[ j ] = (time > 40 ? 1 : 0);     // specs: 26-28us -> 0, 70us -> 1
			  }
		}

		// DHT11 EOF:
		//    1. PULL LOW 50us.
		time = m_gpio->durationState(GPIO_Handler::GPIO_STATUS::LOW, m_timer);                     // 1.
		if (time < 24)					// specs say: 50us
		{
			m_status = SENSOR_STATUS::SENSOR_ERROR;
			m_error = SENSOR_ERROR::ERROR_READING;
			strcpy(m_errorDescription, "Failed wait gpio low for 24us");
		}
	}

	// Methods for DHT22
	void Temperature_Sensor::startDHT22()
	{
		// ToDo
	};

	void Temperature_Sensor::checkResponseDHT22()
	{
		// ToDo
	}

	void Temperature_Sensor::readDHT22()
	{
		// ToDo
		/*
		uint8_t humidity_byte1;
		readByte(humidity_byte1);
		uint8_t humidity_byte2;
		readByte(humidity_byte2);
		uint8_t temperature_byte1;
		readByte(temperature_byte1);
		uint8_t temperature_byte2;
		readByte(temperature_byte2);
		uint8_t SUM;
		readByte(SUM);

		uint16_t temperature = ((temperature_byte1 << 8) | temperature_byte2);
		uint16_t humidity = ((humidity_byte1 << 8) | humidity_byte2);

		m_temperature = temperature / 10u;
		m_humidity = humidity / 10u;
		*/
	}

	void Temperature_Sensor::sampleDHT22(uint8_t* data)
	{
		// ToDo
	}

	uint8_t Temperature_Sensor::readByte(uint8_t* data)
	{
		uint8_t v = 0u;
	    for (uint16_t i = 0u; i < 8u; ++i) {
	        v += data[i] << (7u - i);
	    }
	    return v;

		/*
		uint8_t retVal;
		// the previous High state last 80us
//		if(m_gpio->waitUntilFor(GPIO_Handler::GPIO_STATUS::LOW, m_timer, 100u))
		if(m_gpio->waitUntil(GPIO_Handler::GPIO_STATUS::LOW, 80u))
		{
			for(uint8_t i = 0u; i < 8u; ++i)
			{
//				m_gpio->waitUntil(GPIO_Handler::GPIO_STATUS::HIGH, 100u);
				m_gpio->waitUntil(GPIO_Handler::GPIO_STATUS::HIGH, 0u);
				uint32_t duration = m_gpio->durationState(GPIO_Handler::GPIO_STATUS::HIGH, m_timer);
	//			m_gpio->waitUntil(GPIO_Handler::GPIO_STATUS::LOW, 0u);
//				if(GPIO_Handler::GPIO_STATUS::LOW == m_gpio->getStatus())
	//			if(GPIO_Handler::GPIO_STATUS::HIGH == m_gpio->getStatus())
				if(duration < 30u)
				{
					retVal &= ~(1 << (7 - i));
				}
				else
				{
					retVal |= (1 << (7 - i));
				}
//				m_gpio->waitUntil(GPIO_Handler::GPIO_STATUS::LOW, 0u);
	//			m_gpio->waitUntil(GPIO_Handler::GPIO_STATUS::HIGH, 0u);
			}
			value = retVal;
		}
		else
		{
			m_status = SENSOR_STATUS::SENSOR_ERROR;
			m_error = SENSOR_ERROR::ERROR_READING;
			strcpy(m_errorDescription, "Failed wait gpio low for 50us");
		}
		*/
	}

	float Temperature_Sensor::getTemperature(const UNITY_MEASURE um)
	{
		float retValue = m_temperature;
		if(UNITY_MEASURE::FARENEITH == um)
		{
			retValue = 32.0f + m_temperature*(9.0f/5.0f);
		}
		return retValue;
	}

	float Temperature_Sensor::getHumidity()
	{
		return m_humidity;
	}
}


