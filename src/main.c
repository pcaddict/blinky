/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/led.h>


const struct device *status_red_led = DEVICE_DT_GET(DT_PARENT(DT_ALIAS(led0)));

int main(void)
{
	int ret;

	ret = led_on(status_red_led, 0);
}
