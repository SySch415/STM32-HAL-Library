#pragma once
#include <cstdint>

namespace hal::regs {
constexpr uint32_t SPI1_BASE_ADDR = 0x40013000;
constexpr uint32_t SPI2_BASE_ADDR = 0x40003800;

struct Spi_Regs {
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SR;
  volatile uint32_t DR;
  volatile uint32_t CRCPR;
  volatile uint32_t RXCRCR;
  volatile uint32_t TXCRCR;
  volatile uint32_t I2SCFGR;
  volatile uint32_t I2SPR;
};

inline auto *SPI1 = reinterpret_cast<Spi_Regs *>(SPI1_BASE_ADDR);
inline auto *SPI2 = reinterpret_cast<Spi_Regs *>(SPI2_BASE_ADDR);
}; // namespace hal::regs
