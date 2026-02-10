#include "ui.h"
#include <SPI.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>

TFT_eSPI tft = TFT_eSPI(); // automatically uses HSPI defined in User_Setup.h

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33

XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);

void setup() {
	SPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
	touchscreen.begin();

	// Set the TFT touch rotation in landscape mode
	touchscreen.setRotation(2);

	tft.init();
	// Set the TFT display rotation in landscape mode
	tft.setRotation(1);

	// Clear the screen before writing to it
	tft.fillScreen(TFT_BLACK);

	drawHome();
}

void loop() {

}

bool inRange(int x, int min, int max) {
	return (x >= min && x <= max);
}