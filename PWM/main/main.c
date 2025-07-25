// Including Libraries
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "driver/ledc.h"

#define led_pin GPIO_NUM_18 // defining GPIO pin

void app_main(void)
{
    // Configuring ADC
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_12);

    // Configuring PWM Timer
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .timer_num = LEDC_TIMER_0,
        .duty_resolution = LEDC_TIMER_12_BIT,
        .freq_hz = 5000,
        .clk_cfg = LEDC_AUTO_CLK};

    ledc_timer_config(&ledc_timer);

    // Configuring PWM Channel
    ledc_channel_config_t ledc_channel = {
        .channel = LEDC_CHANNEL_0,
        .duty = 0,
        .gpio_num = led_pin,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .timer_sel = LEDC_TIMER_0,
        .hpoint = 0};
    ledc_channel_config(&ledc_channel);

    // Main loop:Read ADC and and set PWM Accordingly
    while (1)
    {
        int adc_value = adc1_get_raw(ADC1_CHANNEL_6); // Reading value raw value from ADC
        int duty = adc_value;
        // Setting PWM accordingly
        ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, duty);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
        // Displaying data on serial monitor
        printf("ADC:%d->PWM:%d\n", adc_value, duty);

        // Delay
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}