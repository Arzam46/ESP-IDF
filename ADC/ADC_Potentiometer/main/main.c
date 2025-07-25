#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"



void app_main(void)
{
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_DB_12);


    while(1){
        int Value=adc1_get_raw(ADC1_CHANNEL_6);
        printf("ADC: %d\n",Value);
        vTaskDelay(pdMS_TO_TICKS(50));
    }

}