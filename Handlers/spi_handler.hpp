/*
 * gpio_handler.hpp
 *
 *  Created on: Jan 4, 2024
 *      Author: giaco
 */

#ifndef SPI_HANDLER_HPP_
#define SPI_HANDLER_HPP_

#include "handlers.hpp"

namespace Handlers
{
	class SPI_Handler : public Handler
	{
	public:
		SPI_Handler() : Handler() {};
		virtual ~SPI_Handler(){};
	protected:
	};
}

#endif /* GPIO_HANDLER_HPP_ */
