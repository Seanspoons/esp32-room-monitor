
#include "driver/gpio.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static constexpr gpio_num_t LED_PIN = GPIO_NUM_18;
static const char* TAG = "ROOM_MONITOR";

extern "C" void app_main()
{
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    ESP_LOGI(TAG, "Starting LED test");

    bool led_on = false;

    while (true) {
        led_on = !led_on;

        gpio_set_level(LED_PIN, led_on ? 1 : 0);

        ESP_LOGI(TAG, "LED: %s", led_on ? "ON" : "OFF");

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
