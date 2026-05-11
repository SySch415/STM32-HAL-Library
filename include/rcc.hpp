#include "../regs/rcc_regs.hpp"

namespace hal {

class RCC {
public:
  enum class Periph {
    GPIOA,
    GPIOB,
    GPIOC,
    GPIOD,
    GPIOE,
    GPIOH,
    CRC,
    DMA1,
    DMA2,
    TIM1,
    TIM2,
    TIM3,
    TIM4,
    TIM5,
    WWDG,
    SPI1,
    SPI2,
    SPI3,
    USART1,
    USART2,
    USART6,
    I2C1,
    I2C2,
    I2C3,
    PWREN
  };
  RCC();

  void clock_enable(const Periph &p);

private:
  regs::Rcc_Regs *rcc_;
};
}; // namespace hal
