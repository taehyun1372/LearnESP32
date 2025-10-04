#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

void app_main(void)
{
    printf("Hello World. How do you feel?\n");
    gpio_reset_pin(2);
    gpio_set_direction(2, GPIO_MODE_OUTPUT);
    while(1)
    {
        gpio_set_level(2, 0);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
        gpio_set_level(2, 1);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}