#include "ui.h"
#include <TFT_eSPI.h>
#include <gfxfont.h>
#include "fonts/Petme8x8.h"



void drawAlarmManager(void) {
    tft.fillScreen(0x0);
    // back_btn
    tft.setTextColor(0x651D);
    tft.setTextSize(1);
    tft.setFreeFont(&Petme8x8);
    tft.drawString("<Back", 10, 10);
    // alarms_title_disp
    tft.setTextColor(0xFFFF);
    tft.drawString("Existing Alarms", 30, 39);
    // alarm_details_disp
    tft.drawString("1. blablabla", 30, 58);
    // delete_btn
    tft.setTextColor(0x651D);
    tft.drawString("Delete", 263, 58);
    // alarm_new_btn
    tft.drawString("Create New", 120, 221);
}

void handleAlarmManagerInput(int x, int y) {
    if (inRange(x, 10 - 10, 50 + 10) && inRange(y, 10 - 10, 19 + 10)) { // pressed back

    } else if (inRange(x, 120 - 10, 200 + 10) && inRange(y, 221 - 10, 230 + 10)) { // pressed create new

    }
}