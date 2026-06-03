#pragma once

#include "../regs/adc_regs.hpp"
#include <cstdint>

namespace hal {
class ADC {
public:
  enum class CH : uint8_t {
    CH0,
    CH1,
    CH2,
    CH3,
    CH4,
    CH5,
    CH6,
    CH7,
    CH8,
    CH9,
    CH10,
    CH11,
    CH12,
    CH13,
    CH14,
    CH15
  };

  enum class SAMPLE_T : uint8_t {
    CYCLE_3,
    CYCLE_15,
    CYCLE_28,
    CYCLE_56,
    CYCLE_84,
    CYCLE_112,
    CYCLE_144,
    CYCLE_480
  };

  ADC();
  uint16_t read(hal::ADC::CH ch);
  void set_sample_t(hal::ADC::CH ch, hal::ADC::SAMPLE_T time);

private:
  hal::regs::adc_regs *adc_;
};
}; // namespace hal
