#include "../include/rcc.hpp"

hal::RCC::RCC() { rcc_ = regs::RCC; }

void hal::RCC::clock_enable(const Periph &p) {

  switch (p) {
  case hal::RCC::Periph::GPIOA:
    rcc_->AHB1ENR |= (1 << 0);
    break;
  case hal::RCC::Periph::GPIOB:
    rcc_->AHB1ENR |= (1 << 1);
    break;
  case hal::RCC::Periph::GPIOC:
    rcc_->AHB1ENR |= (1 << 2);
    break;
  case hal::RCC::Periph::GPIOD:
    rcc_->AHB1ENR |= (1 << 3);
    break;
  case hal::RCC::Periph::GPIOE:
    rcc_->AHB1ENR |= (1 << 4);
    break;
  case hal::RCC::Periph::GPIOH:
    rcc_->AHB1ENR |= (1 << 7);
    break;
  case hal::RCC::Periph::CRC:
    rcc_->AHB1ENR |= (1 << 12);
    break;
  case hal::RCC::Periph::DMA1:
    rcc_->AHB1ENR |= (1 << 21);
    break;
  case hal::RCC::Periph::DMA2:
    rcc_->AHB1ENR |= (1 << 22);
    break;
  case hal::RCC::Periph::TIM1:
    rcc_->APB2ENR |= (1 << 0);
    break;
  case hal::RCC::Periph::TIM2:
    rcc_->APB1ENR |= (1 << 0);
    break;
  case hal::RCC::Periph::TIM3:
    rcc_->APB1ENR |= (1 << 1);
    break;
  case hal::RCC::Periph::TIM4:
    rcc_->APB1ENR |= (1 << 2);
    break;
  case hal::RCC::Periph::TIM5:
    rcc_->APB1ENR |= (1 << 3);
    break;
  case hal::RCC::Periph::WWDG:
    rcc_->APB1ENR |= (1 << 11);
    break;
  case hal::RCC::Periph::SPI1:
    rcc_->APB2ENR |= (1 << 12);
    break;
  case hal::RCC::Periph::SPI2:
    rcc_->APB1ENR |= (1 << 14);
    break;
  case hal::RCC::Periph::SPI3:
    rcc_->APB1ENR |= (1 << 15);
    break;
  case hal::RCC::Periph::USART1:
    rcc_->APB2ENR |= (1 << 4);
    break;
  case hal::RCC::Periph::USART2:
    rcc_->APB1ENR |= (1 << 17);
    break;
  case hal::RCC::Periph::USART6:
    rcc_->APB2ENR |= (1 << 5);
    break;
  case hal::RCC::Periph::I2C1:
    rcc_->APB1ENR |= (1 << 21);
    break;
  case hal::RCC::Periph::I2C2:
    rcc_->APB1ENR |= (1 << 22);
    break;
  case hal::RCC::Periph::I2C3:
    rcc_->APB1ENR |= (1 << 23);
    break;
  case hal::RCC::Periph::PWREN:
    rcc_->APB1ENR |= (1 << 28);
    break;
  case hal::RCC::Periph::ADC1:
    rcc_->APB2ENR |= (1 << 8);

  default:
    while (1) {
    };
  }
}
