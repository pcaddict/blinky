#include <cstddef>
#include <gpio_led.h>

GPIO_LED::GPIO_LED(const gpio_dt_spec *led) : _led {led} {
    if (device_is_ready(_led->port)) {
        gpio_pin_configure_dt(_led, GPIO_OUTPUT_INACTIVE);
    }
}

void GPIO_LED::on()
{
    gpio_pin_set_dt(_led, true);
}

void GPIO_LED::off()
{
    gpio_pin_set_dt(_led, false);
}

void GPIO_LED::toggle()
{
    gpio_port_toggle_bits(_led->port, static_cast<gpio_port_pins_t>(BIT(_led->pin)));
}