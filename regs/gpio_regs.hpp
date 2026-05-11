#pragma once
#include <cstdint>

namespace hal::regs {

constexpr uint32_t GPIOA_BASE_ADDR = 0x40020000;
constexpr uint32_t GPIOB_BASE_ADDR = 0x40020400;
constexpr uint32_t GPIOC_BASE_ADDR = 0x40020800;

struct Gpio_Regs {
  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFRL;
  volatile uint32_t AFRH;
};

inline auto *GPIOA = reinterpret_cast<Gpio_Regs *>(GPIOA_BASE_ADDR);
inline auto *GPIOB = reinterpret_cast<Gpio_Regs *>(GPIOB_BASE_ADDR);
inline auto *GPIOC = reinterpret_cast<Gpio_Regs *>(GPIOC_BASE_ADDR);

}; // namespace hal::regs
