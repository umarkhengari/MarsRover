
// I2C Settings

#include <cstdint>
#define S_SCL   33
#define S_SDA   32

//
String jsonFeedbackWeb = "";
String thisMacStr = "";
byte espNowMode = 3;
bool ctrlByBroadcast = true;
uint8_t mac_whitelist_broadcast[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
bool runNewJsonCmd = false;
bool uartCmdEcho = true;
