#include "ui.h"
#include <SPI.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include <WiFi.h>
#include <ctime>

TFT_eSPI tft = TFT_eSPI(); // automatically uses HSPI defined in User_Setup.h

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33

XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);

const char *ssid = "27 = x";
const char *password = "hellohello";
const char *ntpServer = "pool.ntp.org";

// time
struct tm timeInfo;
UIState currentUI;

void setup() {
	// init serial
	Serial.begin(115200);
	SPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
	touchscreen.begin();

	// Set the TFT touch rotation in landscape mode
	touchscreen.setRotation(2);

	tft.init();
	// Set the TFT display rotation in landscape mode
	tft.setRotation(1);

	// Clear the screen before writing to it
	tft.fillScreen(TFT_BLACK);

	// Wi-Fi init, only proceed once connected
	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED) {
		delay(100);
		Serial.print(".");
	}
	Serial.println("Connected to Wi-Fi!");

	// start an SNTP client that periodically syncs 
	// in the background with the NTP server
	// internal RTC is synced with the fetched time
	
	// 0 hour and daylight savings offset
	configTime(0, 0, ntpServer);
	// set current timezone
	setenv("TZ", "MYT-8", 1);
	tzset();
	while(!getLocalTime(&timeInfo)) {
		Serial.println("-");
	} // block until we grab current time, in struct tm format

	Serial.println("Synced system time with the NTP server!");

	currentUI = UIState::HOME;
	setUI(UIState::HOME);
}

void loop() {

}

bool inRange(int x, int min, int max) {
	return (x >= min && x <= max);
}

void setUI(UIState nextUI, int a) {
	currentUI = nextUI;
	switch (currentUI) {
		case UIState::HOME:
			drawHome();
			break;
		case UIState::TIMEZONE:
			drawTimezone();
			break;
		case UIState::ALARM_MANAGER:
			drawAlarmManager();
			break;
		case UIState::ALARM_CONFIG:
			drawAlarmConfig();
			break;
		case UIState::ALARM_RING:
			drawAlarmRing(a);
			break;
	}
}