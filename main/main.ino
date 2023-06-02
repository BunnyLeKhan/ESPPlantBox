// -------------------------------------
// INCLUDES
// -------------------------------------
#include "ESP_Debug.h"

// -------------------------------------
// VARIABLES
// -------------------------------------
static const char * TAG = "main: ";

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

  // Créer le message en une ligne
  String message = "Valeur : " + String(vInt) + ", Texte : " + vString + vCharPtr + ", Nombre : " + String(vFloat);
  ESP_Debug_printText(TAG, "ESPlant Project");
  ESP_Debug_printValue(TAG, vInt);
  ESP_Debug_printValue(TAG, vFloat);
  ESP_Debug_printString(TAG, message);
}

void loop() {
  // Votre code ici
}
