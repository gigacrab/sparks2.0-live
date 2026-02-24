#include <TFT_eSPI.h>

extern TFT_eSPI tft;
extern struct tm timeInfo;

enum class UIState {
    HOME,
    TIMEZONE,
    ALARM_MANAGER,
    ALARM_CONFIG,
    ALARM_RING
};

const char days[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
const char months[12][4] = {"Jan", "Feb", "Mac", "Apr", "May", "Jun", "Aug", "Sep", "Oct", "Nov", "Dec"};

bool inRange(int x, int min, int max);

void drawHome();
void handleHomeInput(int x, int y);
void setUI(UIState nextUI, int a = 0);
void updateHomeTime();

void drawAlarmManager();
void handleAlarmManagerInput(int x, int y);

void drawAlarmConfig();
void handleAlarmConfigInput(int x, int y);

void drawAlarmRing(int a);
void handleAlarmRingInput(int x, int y);

void drawTimezone();
void handleTimezoneInput(int x, int y);