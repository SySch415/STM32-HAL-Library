#pragma once
#include <cstdint>

namespace hal::regs {

constexpr uint32_t TIM2_BASE_ADDR = 0x40000000;
constexpr uint32_t TIM3_BASE_ADDR = 0x40000400;
constexpr uint32_t TIM4_BASE_ADDR = 0x40000800;
constexpr uint32_t TIM5_BASE_ADDR = 0x4000C000;

struct Tim_Regs {
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMCR;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t CCMR1;
  volatile uint32_t CCMR2;
  volatile uint32_t CCER;
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
  uint32_t RESERVED_DONOTUSE0;
  uint32_t CCR1;
  uint32_t CCR2;
  uint32_t CCR3;
  uint32_t CCR4;
  uint32_t RESERVED_DONOTUSE1;
  volatile uint32_t DCR;
  volatile uint32_t DMAR;
  volatile uint32_t TIM2_OR;
  volatile uint32_t TIM5_OR;
};

inline auto *TIM2 = reinterpret_cast<Tim_Regs *>(TIM2_BASE_ADDR);
inline auto *TIM3 = reinterpret_cast<Tim_Regs *>(TIM3_BASE_ADDR);
inline auto *TIM4 = reinterpret_cast<Tim_Regs *>(TIM4_BASE_ADDR);
inline auto *TIM5 = reinterpret_cast<Tim_Regs *>(TIM5_BASE_ADDR);

}; // namespace hal::regs
