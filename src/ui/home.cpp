#include "ui.h"
#include "fonts/Petme8x8.h"
#include <TFT_eSPI.h>
#include <gfxfont.h>

static const unsigned char PROGMEM image_alarm_btn_mid_bits[] = {0x79,0x3c,0xb3,0x9a,0xed,0x6e,0xd0,0x16,0xa0,0x0a,0x41,0x04,0x41,0x04,0x81,0x02,0xc1,0x06,0x82,0x02,0x44,0x04,0x48,0x04,0x20,0x08,0x10,0x10,0x2d,0x68,0x43,0x84};

static const unsigned char PROGMEM image_settings_btn_mid_bits[] = {0x03,0xc0,0x12,0x48,0x2c,0x34,0x40,0x02,0x23,0xc4,0x24,0x24,0xc8,0x13,0x88,0x11,0x88,0x11,0xc8,0x13,0x24,0x24,0x23,0xc4,0x40,0x02,0x2c,0x34,0x12,0x48,0x03,0xc0};



void drawHome(void) {
    tft.fillScreen(0x0);
    // date_disp
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.setFreeFont(&FreeSerif9pt7b);
    tft.drawString("Sun, Feb 1, 2026", 99, 107);
    // hour_minute_disp
    tft.setFreeFont(&FreeMono24pt7b);
    tft.drawString("00:00", 90, 64);
    // alarm_btn_mid
    tft.drawBitmap(153, 192, image_alarm_btn_mid_bits, 15, 16, 0x651D);
    // settings_btn_mid
    tft.drawBitmap(152, 155, image_settings_btn_mid_bits, 16, 16, 0x651D);
    // settings_btn_start
    tft.setTextColor(0x651D);
    tft.setFreeFont(&Petme8x8);
    tft.drawString("Sett", 118, 159);
    // settings_btn_end
    tft.drawString("ings", 169, 159);
    // alarm_btn_start
    tft.drawString("Ala", 126, 196);
    // alarm_btn_end
    tft.drawString("rm", 171, 196);
    // Layer 9
    tft.setTextColor(0xFFFF);
    tft.setFreeFont();
    tft.drawString("", 162, 25);
}
