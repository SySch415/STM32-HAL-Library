#include "../include/gpio.hpp"
#include "../regs/gpio_regs.hpp"
#include <cstdint>

hal::GPIO::GPIO(Port port, uint8_t pin, Mode mode) : port_(nullptr), pin_(pin) {

  switch (port) {

  case hal::GPIO::Port::A:
    port_ = regs::GPIOA;
    break;
  case hal::GPIO::Port::B:
    port_ = regs::GPIOB;
    break;
  case hal::GPIO::Port::C:
    port_ = regs::GPIOC;
    break;
  }

  port_->MODER &= ~(0x3 << (pin_ * 2));
  port_->MODER |= (static_cast<uint32_t>(mode) << (pin_ * 2));
}

void hal::GPIO::set() { port_->BSRR = (1 << pin_); }

void hal::GPIO::reset() { port_->BSRR = (1 << (pin_ + 16)); }

bool hal::GPIO::read() { return (port_->IDR >> pin_) & 1; }

void hal::GPIO::set_pupd(Pull pupd) {
  port_->PUPDR |= (static_cast<uint32_t>(pupd) << pin_ * 2);
}

void hal::GPIO::set_alt_func(uint8_t af) {

  if (pin_ <= 7) {
    port_->AFRL |= (af << (pin_ * 4));
  } else {
    port_->AFRH |= (af << ((pin_ - 8) * 4));
  }
}
