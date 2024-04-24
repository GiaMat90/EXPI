/*
 * math.hpp
 *
 *  Created on: Mar 16, 2024
 *      Author: giaco
 */

#ifndef MATH_HPP_
#define MATH_HPP_

#include <string>
#include <cstdint>

namespace Math
{
	class Float_t
	{
	public:
		Float_t();
		explicit Float_t(float value, uint16_t precision = 1u);
		~Float_t();
		std::string toString();
		uint32_t getDecimals();
		uint32_t getInteger();
	private:
		uint16_t m_precision = 0u;
		uint32_t m_i = 0u;
		uint32_t m_d = 0u;
	};

}


#endif /* MATH_HPP_ */
