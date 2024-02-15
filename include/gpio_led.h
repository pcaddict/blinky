#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>

class GPIO_LED
{
  public:
    GPIO_LED(const gpio_dt_spec *led);

    void on();
    void off();
    void toggle();

  private:
    const gpio_dt_spec *_led;
};