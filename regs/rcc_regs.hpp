#pragma once
#include <cstdint>

namespace hal::regs {

constexpr uint32_t RCC_BASE_ADDR = 0x40023800;

struct Rcc_Regs {
  volatile uint32_t CR;
  volatile uint32_t PLLCFGR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t AHB1RSTR;
  volatile uint32_t AHB2RSTR;
  uint32_t RESERVED_DO_NOT_USE0;
  uint32_t RESERVED_DO_NOT_USE1;
  volatile uint32_t APB1RSTR;
  volatile uint32_t APB2RSTR;
  uint32_t RESERVED_DO_NOT_USE2;
  uint32_t RESERVED_DO_NOT_USE3;
  volatile uint32_t AHB1ENR;
  volatile uint32_t AHB2ENR;
  uint32_t RESERVED_DO_NOT_USE4;
  uint32_t RESERVED_DO_NOT_USE5;
  volatile uint32_t APB1ENR;
  volatile uint32_t APB2ENR;
  uint32_t RESERVED_DO_NOT_USE6;
  uint32_t RESERVED_DO_NOT_USE7;
  volatile uint32_t AHB1LPENR;
  volatile uint32_t AHB2LPENR;
  uint32_t RESERVED_DO_NOT_USE8;
  uint32_t RESERVED_DO_NOT_USE9;
  volatile uint32_t APB1LPENR;
  volatile uint32_t APB2LPENR;
  uint32_t RESERVED_DO_NOT_USE10;
  uint32_t RESERVED_DO_NOT_USE11;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
  uint32_t RESERVED_DO_NOT_USE12;
  uint32_t RESERVED_DO_NOT_USE13;
  volatile uint32_t SSCGR;
  volatile uint32_t PLLI2SCFGR;
  uint32_t RESERVED_DO_NOT_USE14;
  volatile uint32_t DCKCFGR;
};

inline auto *RCC = reinterpret_cast<Rcc_Regs *>(RCC_BASE_ADDR);

} // namespace hal::regs
