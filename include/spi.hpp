#pragma once
#include "../regs/spi_regs.hpp"
#include <cstdint>

namespace hal {
class SPI {
public:
  enum class ID { SPI1, SPI2 };
  enum class PSr { D2, D4, D8, D16, D32, D64, D128, D256 };

  SPI(ID spi_id, PSr prescaler);
  uint8_t transfer_data(uint8_t data);

private:
  regs::Spi_Regs *spi_;
};
}; // namespace hal
