#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

#define BLINK_GPIO GPIO_NUM_2   // Built-in LED (ESP32 WROOM devkit usually uses GPIO2)
#define BLINK_DELAY 100         // milliseconds

static const char *TAG = "Blink";

// Blink task
void blink_task(void *pvParameter)
{
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        // Toggle LED
        gpio_set_level(BLINK_GPIO, 1);
        ESP_LOGI(TAG, "LED ON");
        vTaskDelay(pdMS_TO_TICKS(BLINK_DELAY));

        gpio_set_level(BLINK_GPIO, 0);
        ESP_LOGI(TAG, "LED OFF");
        vTaskDelay(pdMS_TO_TICKS(BLINK_DELAY));
    }
}

void app_main(void)
{
    ESP_LOGI(TAG, "Starting blink task");
    // Create FreeRTOS task
    xTaskCreate(blink_task, "blink_task", 2048, NULL, 5, NULL);
}
