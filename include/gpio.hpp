#include "../regs/gpio_regs.hpp"
#include <cstdint>

namespace hal {

class GPIO {

public:
  enum class Port { A, B, C };
  enum class Mode { Input, Output, AF, Analog };
  enum class Pull { None, Up, Down, Reserved };

  GPIO(Port port, uint8_t pin, Mode mode);
  void set();
  void reset();
  bool read();
  void set_pupd(Pull pupd);
  void set_alt_func(uint8_t af);

private:
  regs::Gpio_Regs *port_;
  uint8_t pin_;
};

}; // namespace hal
