#include "ui.h"
#include <TFT_eSPI.h>
#include <gfxfont.h>
#include "fonts/Petme8x8.h"



void drawTimezone(void) {
    tft.fillScreen(0x0);
    // back_btn
    tft.setTextColor(0x651D);
    tft.setTextSize(1);
    tft.setFreeFont(&Petme8x8);
    tft.drawString("<Back", 10, 10);
    // UK_btn_out
    tft.drawRect(169, 89, 91, 52, 0x651D);
    // MY_btn_out
    tft.drawRect(60, 89, 91, 52, 0x651D);
    // MY_btn_in
    tft.setFreeFont(&FreeSerif24pt7b);
    tft.drawString("MY", 69, 96);
    // UK_btn_in
    tft.drawString("UK", 181, 96);
    // confirm_btn
    tft.setFreeFont(&Petme8x8);
    tft.drawString("Confirm", 132, 221);
}

void handleTimezoneInput(int x, int y) {
    if (inRange(x, 10 - 10, 50 + 10) && inRange(y, 10 - 10, 19 + 10)) { // pressed back

    } else if (inRange(x, 120 - 10, 200 + 10) && inRange(y, 221 - 10, 230 + 10)) { // pressed confirm

    } else if (inRange(x, 60, 151) && inRange(y, 89, 141)) { // pressed MY

    } else if (inRange(x, 169, 260) && inRange(y, 89, 141)) { // pressed UK

    }
}
