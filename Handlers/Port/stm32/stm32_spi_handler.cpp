#include "stm32_spi_handler.hpp"

namespace Handlers
{
	namespace STM32
	{
		SPI::SPI() : SPI_Handler()
		{
			m_board = BOARD_TYPE::STM32;
		}

		SPI::SPI(SPI_HandleTypeDef* h) : SPI_Handler(), m_hSpi(h)
		{
			m_board = BOARD_TYPE::STM32;
		}

		SPI::~SPI()
		{

		}
	}
}
