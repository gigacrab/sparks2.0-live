#include <TFT_eSPI.h>

extern TFT_eSPI tft;

bool inRange(int x, int min, int max);

void drawHome();
void handleHomeInput(int x, int y);

void drawAlarmManager();
void handleAlarmManagerInput(int x, int y);

void drawAlarmConfig();
void handleAlarmConfigInput(int x, int y);

void drawAlarmRing();
void handleAlarmRingInput(int x, int y);

void drawTimezone();
void handleTimezoneInput(int x, int y);