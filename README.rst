Overview
********

This project replaces manual GPIO control of LEDs with the use of the LED
API functions led_{on, off, blink}. These functions require a struct device *
reference to pass to the LED driver.

The devicetree requires the following (refer to the gpio-leds compatible): 

.. code-block:: DTS

   / {
   	aliases {
   		led0 = &myled0;
   	};

   	leds {
   		compatible = "gpio-leds";
   		myled0: led_0 {
   			gpios = <&gpio0 13 GPIO_ACTIVE_LOW>;
                };
   	};
   };

Build errors
************

With the project built as-is, the following error is encountered:

.. code-block:: Build-Error
    undefined reference to `__device_dts_ord_20'. 

__device_dts_ord_20 refers to the "leds" device as demonstrated in the
previous section. 

If we replace 
.. code-block:: device
    DEVICE_DT_GET(DT_PARENT(DT_ALIAS(led0)));
    with
    DEVICE_DT_GET(DT_NODELABEL(status_red));

the error above changes to the appropriate __device_dts_ord_NN.