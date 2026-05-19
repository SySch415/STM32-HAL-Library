#include "../include/spi.hpp"
#include <cstdint>

hal::SPI::SPI(ID spi_id, PSr prescaler) {

  switch (spi_id) {
  case hal::SPI::ID::SPI1:
    spi_ = hal::regs::SPI1;
    break;
  case hal::SPI::ID::SPI2:
    spi_ = hal::regs::SPI2;
    break;
  default:
    while (1) {
    };
  }

  //            ssm        ssi        spi enable          baud rate cotrl mstr
  spi_->CR1 |= (1 << 9) | (1 << 8) | (1 << 6) |
               (static_cast<uint8_t>(prescaler) << 3) |
               (1 << 2); // master selction
}

uint8_t hal::SPI::transfer_data(uint8_t transfer_data) {
  uint8_t rx;
  spi_->DR = transfer_data;
  while (!(spi_->SR & (1 << 0))) { // wait till recieve buffer has data
  };
  rx = spi_->DR;
  while (spi_->SR &
         (1 << 7)) { // wait for transmission to fiish (busy flag goes to zero)
  };

  return rx;
}
