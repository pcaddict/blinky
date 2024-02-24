#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>

class GPIO_LED
{
  public:
    GPIO_LED(const gpio_dt_spec &led, const uint32_t flags = GPIO_OUTPUT_INACTIVE);

    void on();
    void off();
    void toggle();

  private:
    const gpio_dt_spec _led;
};