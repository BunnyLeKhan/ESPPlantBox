/* ESPPLant is an open-source project about an plant box monitored by an ESP32
 * Author : Corentn Cuomo-Graff - Guillaume Frick
 * Date : 02 june 2023
 * Main File
 */

// -------------------------------------
// INCLUDES
// -------------------------------------
#include "ESP_Debug.h"

// -------------------------------------
// VARIABLES
// -------------------------------------
static const char * TAG_main = "main: ";

int vInt = 4;
float vFloat = 3.1415;
String vString = "abcd";
char * vCharPtr = "efgh";

// -------------------------------------
// FUNCTIONS
// -------------------------------------
void setup() {
  Serial.begin(115200);
  ESP_Debug_printInit();

  ESP_Debug_printText(TAG_main, "ESPlant Project");
  ESP_Debug_printValue(TAG_main, vInt);
  ESP_Debug_printValue(TAG_main, vFloat);

  // Créer le message en une ligne
  String message = "Valeur : " + String(vInt) + ", Texte : " + vString + vCharPtr + ", Nombre : " + String(vFloat);
  ESP_Debug_printString(TAG_main, message);
}

void loop() {
  // Votre code ici
}
