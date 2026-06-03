#pragma once
#include <cstdint>

namespace hal::regs {

constexpr uint32_t ADC_BASE_ADDR = 0x40012000;

struct adc_regs {
  volatile uint32_t SR;
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t JOFR1;
  volatile uint32_t JOFR2;
  volatile uint32_t JOFR3;
  volatile uint32_t JOFR4;
  volatile uint32_t HTR;
  volatile uint32_t LTR;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t JSQR;
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
  volatile uint32_t DR;
  volatile uint32_t CCR;
};
inline auto *ADC1 = reinterpret_cast<adc_regs *>(ADC_BASE_ADDR);
}; // namespace hal::regs
