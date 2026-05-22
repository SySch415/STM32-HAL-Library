#pragma once
#include "../regs/tim_regs.hpp"
#include <cstdint>
#include <type_traits>

namespace hal {

enum class TimSize { BIT16, BIT32 };
enum class TimType { TIM2, TIM3, TIM4, TIM5 };

template <TimSize T> class TIMX {
public:
  using CounterSize =
      typename std::conditional<T == TimSize::BIT32, uint32_t, uint16_t>::type;

  TIMX(hal::TimType timer_type) {

    switch (timer_type) {
    case hal::TimType::TIM2:
      _regs = hal::regs::TIM2;
      break;
    case hal::TimType::TIM3:
      _regs = hal::regs::TIM3;
      break;
    case hal::TimType::TIM4:
      _regs = hal::regs::TIM4;
      break;
    case hal::TimType::TIM5:
      _regs = hal::regs::TIM5;
      break;
    default:
      while (1) {
      };
    }
  }

  void set_ARR(CounterSize val) { _regs->ARR = val; }

  void set_CNT(CounterSize val) { _regs->CNT = val; }

  void set_CCR(uint8_t reg_val, CounterSize val) {

    switch (reg_val) {
    case 1:
      _regs->CCR1 = val;
      break;
    case 2:
      _regs->CCR2 = val;
      break;
    case 3:
      _regs->CCR3 = val;
      break;
    case 4:
      _regs->CCR4 = val;
      break;
    default:
      while (1) {
      };
    }
  }

  void set_PSC(uint16_t val) { _regs->PSC = val; }

  void enable_Counter() { _regs->CR1 |= (1 << 0); }

  void enable_CCER(uint8_t channel_val) {
    _regs->CCER |= (1 << ((channel_val - 1) * 4));
  }

  void set_PWM_mode_1(uint8_t channel) {

    switch (channel) {
    case 1:
      _regs->CCMR1 |= (6 << 4) | (1 << 3);
      break;
    case 2:
      _regs->CCMR1 |= (6 << 12) | (1 << 11);
      break;
    case 3:
      _regs->CCMR2 |= (6 << 4) | (1 << 3);
    case 4:
      _regs->CCMR2 |= (6 << 12) | (1 << 11);
      break;
    }
  }

private:
  regs::Tim_Regs *_regs;
};
}; // namespace hal
