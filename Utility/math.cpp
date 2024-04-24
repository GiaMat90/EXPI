/*
 * math.cpp
 *
 *  Created on: Mar 16, 2024
 *      Author: giaco
 */

#include "math.hpp"

namespace Math
{
	Float_t::Float_t() : m_precision(0u), m_i(0u), m_d(0u)
	{
	}

	Float_t::Float_t(float value, uint16_t precision) : m_precision(precision)
	{
		m_i = value;
		uint32_t decimal_points_precision = 1u;
		for(uint16_t index = 0u; index < m_precision; ++index)
		{
			decimal_points_precision *= 10u;
		}
		m_d = (static_cast<uint32_t>((value - m_i)*decimal_points_precision)%decimal_points_precision);
	}

	Float_t::~Float_t()
	{

	}

	std::string Float_t::toString()
	{
		std::string retStr = std::to_string(m_i) + "." + std::to_string(m_d);
		return retStr;
	}

	uint32_t Float_t::getInteger()
	{
		return m_i;
	}

	uint32_t Float_t::getDecimals()
	{
		return m_d;
	}

}
