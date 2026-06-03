#include "../include/adc.hpp"
#include <cstdint>

hal::ADC::ADC() : adc_(hal::regs::ADC1) { adc_->CR1 |= (1 << 0); }

uint16_t hal::ADC::read(hal::ADC::CH ch) {
  uint8_t channel{static_cast<uint8_t>(ch)};
  adc_->SQR3 = channel;
  adc_->SQR1 &= ~(0xF << 20);
  adc_->CR2 |= (1 << 30);

  while (!(adc_->SR & (1 << 1)))
    ;

  return static_cast<uint16_t>(adc_->DR);
}

void hal::ADC::set_sample_t(hal::ADC::CH ch, hal::ADC::SAMPLE_T time) {
  uint8_t channel{static_cast<uint8_t>(ch)};
  uint8_t sample{static_cast<uint8_t>(time)};

  if (channel <= 9) {
    uint8_t offset{static_cast<uint8_t>(channel * 3)};
    adc_->SMPR2 |= (sample << offset);
  } else {
    uint8_t offset{static_cast<uint8_t>((channel - 10) * 3)};
    adc_->SMPR1 |= (sample << offset);
  }
}
