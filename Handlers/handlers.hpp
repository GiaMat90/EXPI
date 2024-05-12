/*
 * handlers.hpp
 *
 *  Created on: Dec 30, 2023
 *      Author: giaco
 */

#ifndef HANDLERS_HPP_
#define HANDLERS_HPP_

#include <cstdint>

namespace Handlers
{
	class Handler
	{
	public:
		enum class BOARD_TYPE : uint8_t
		{
			UNDEFINED = 0,
			STM8,
			STM32,
			ESP32,
			ESP8266,
			TIVA,
			ATMEL
		};
		Handler(){};
		virtual ~Handler(){};
		inline BOARD_TYPE getBoardType(){ return m_board; }
	protected:
		BOARD_TYPE m_board = BOARD_TYPE::UNDEFINED;
	};
}

#endif /* HANDLERS_HPP_ */
