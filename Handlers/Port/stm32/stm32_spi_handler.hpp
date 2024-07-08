#ifndef STM32_SPI_HANDLER_HPP_
#define STM32_SPI_HANDLER_HPP_

#include "../../spi_handler.hpp"

#include <main.h>

namespace Handlers
{
	namespace STM32
	{
		class SPI : public SPI_Handler
		{
		public:
			SPI(SPI_HandleTypeDef* h);
			SPI();
			~SPI();
		private:
			SPI_HandleTypeDef* m_hSpi;;

		};
	}
}

#endif
