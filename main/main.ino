/* ESPLant is an open-source project about an plant box monitored by an ESP32
 * Author : Corentn Cuomo-Graff - Guillaume Frick
 * Date : 02 june 2023
 * Main File
 */

// -------------------------------------
// INCLUDES
// -------------------------------------
#include "ESP_Debug.h"

// -------------------------------------
// CONSTANTS
// -------------------------------------
static const char * TAG_main = "main: ";

// -------------------------------------
// FUNCTIONS
// -------------------------------------
void setup() {
  Serial.begin(115200);
  ESP_Debug_printInit();

  xTaskCreatePinnedToCore(ESP_Debug_testTask, "TestDebug", DEBUG_TEST_TASK_SIZE, NULL, 1, &debugTestTaskHandle, 0);
  
  ESP_Debug_print(TAG_main, "Setup OK");
}

void loop() {}
