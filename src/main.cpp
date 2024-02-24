/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>

#include <gpio_led.h>

LOG_MODULE_REGISTER(app, LOG_LEVEL_DBG);

// constexpr gpio_dt_spec status_red_led = GPIO_DT_SPEC_GET(DT_NODELABEL(status_red), gpios);
// constexpr gpio_dt_spec status_blue_led = GPIO_DT_SPEC_GET(DT_NODELABEL(status_blue), gpios);
// constexpr gpio_dt_spec status_green_led = GPIO_DT_SPEC_GET(DT_NODELABEL(status_green), gpios);
// constexpr gpio_dt_spec user_led = GPIO_DT_SPEC_GET(DT_NODELABEL(user_led), gpios);

void timer_stop(k_timer *timer)
{
    const auto led = static_cast<GPIO_LED*>(timer->user_data);
    led->off();
}

void timer_handler(k_timer *timer)
{
    // gpio_pin_toggle_dt(&status_green_led);
    auto led = static_cast<GPIO_LED*>(timer->user_data);
    led->toggle();
}

k_timer green_timer {};
k_timer red_timer {};
k_timer blue_timer {};

int main()
{
    GPIO_LED green { GPIO_DT_SPEC_GET(DT_NODELABEL(status_red), gpios) };
    GPIO_LED red { GPIO_DT_SPEC_GET(DT_NODELABEL(status_green), gpios) };
    GPIO_LED blue { GPIO_DT_SPEC_GET(DT_NODELABEL(user_led), gpios) };
    
    k_timer_init(&green_timer, timer_handler, timer_stop);
    k_timer_init(&red_timer, timer_handler, timer_stop);
    k_timer_init(&blue_timer, timer_handler, timer_stop);

    green_timer.user_data = static_cast<void*>(&green);
    red_timer.user_data = static_cast<void*>(&red);
    blue_timer.user_data = static_cast<void*>(&blue);

    k_timer_start(&green_timer, K_MSEC(100), K_MSEC(500));
    k_timer_start(&red_timer, K_MSEC(600), K_MSEC(500));
    k_timer_start(&blue_timer, K_MSEC(1), K_MSEC(500));

    while (true) {
        k_sleep(K_FOREVER);
    }
}
