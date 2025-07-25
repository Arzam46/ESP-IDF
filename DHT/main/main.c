// Including libraries
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "dht.h"
#include "esp_log.h"

#define DHT_GPIO 27 // GPIO pin connected to DHT sensor

void app_main(void)
{
    // Initial message when program starts
    ESP_LOGI("DHT", "Starting DHT reading...");

    while (1)
    {
        float temperature = 0, humidity = 0; // Variables to store data

        // Reading Temp&Humid
        esp_err_t result = dht_read_float_data(DHT_TYPE_DHT11, DHT_GPIO, &humidity, &temperature);
        if (result == ESP_OK)
        {
            ESP_LOGI("DHT", "Temperature: %.1f °C, Humidity: %.1f %%", temperature, humidity); // Display data on Serial monitor
        }
        else
        {
            ESP_LOGE("DHT", "Failed to read from DHT sensor: %s", esp_err_to_name(result)); // Display error message if Sensor is not initialized
        }
        // delay
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
