/*
 * uart_handler.cpp
 *
 *  Created on: Dec 30, 2023
 *      Author: giaco
 */

#include "uart_handler.hpp"
#include <cstring>

namespace Handlers
{
	UART_Handler::UART_Handler(UART_MODE mode = UART_MODE::NONE) :
			Handler(), m_mode(mode)
	{
	}

	UART_Handler::~UART_Handler()
	{

	}

	UART_Handler::UART_STATUS UART_Handler::send(const std::string& msg)
	{
		if(!msg.empty())
		{
			uint8_t cMsg[sizeof(msg.c_str()) + 1];
			strcpy(cMsg, msg.c_str());
			if(cMsg[sizeof(cMsg)-1] != '\n')
			{
				cMsg[sizeof(msg.c_str())] = '\n';
			}
			this->send(cMsg, sizeof(cMsg));
		}
		return m_status;
	}
}


