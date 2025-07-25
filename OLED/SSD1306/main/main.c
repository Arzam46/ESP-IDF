// Including libraries
#include <stdio.h>
#include "ssd1306.h"
#include "font8x8_basic.h"
#include "driver/i2c.h"
// Define pins for I2C communication
#define I2C_MASTER_SCL_IO 22
#define I2C_MASTER_SDA_IO 21

void app_main(void)
{
    // Initialize OLED and print message
    SSD1306_t dev;
    i2c_master_init(&dev, I2C_MASTER_SDA_IO, I2C_MASTER_SCL_IO, -1); //

    ssd1306_init(&dev, 128, 64);
    ssd1306_clear_screen(&dev, false);
    ssd1306_contrast(&dev, 0xFF);
    ssd1306_display_text(&dev, 0, " Arzam Farooq!", 64, false);
}
