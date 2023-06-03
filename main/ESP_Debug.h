#ifndef _DEBUG_HEADER_
#define _DEBUG_HEADER_ 

// -------------------------------------
// INCLUDES
// -------------------------------------
#include "ESP_Configuration.h"

// -------------------------------------
// CONSTANTS
// -------------------------------------
static const char * TAG_debug = "debug: ";

// -------------------------------------
// VARIABLES
// -------------------------------------
TaskHandle_t debugTestTaskHandle; // Gestionnaire de tâche

// -------------------------------------
// FUNCTION
// -------------------------------------
#if DEBUG == 1
/* Init print function */
void ESP_Debug_printInit() {
  Serial.println("ESPlant is an open-source project about an plant box monitored by an ESP32");
  Serial.println("Author : Corentn Cuomo-Graff - Guillaume Frick");
  Serial.println("Date : 02 june 2023\n");
}

/* Casual print function
 * arg tag  : TAG from the function (ex: main)
 * arg text : everything u want to print (ex: abcd, 3.14, 7...)
 */
template <typename Debug_T>
void ESP_Debug_print(const char* tag, Debug_T x) {
  Serial.print(tag);
  Serial.println(x);
}

#else 
void ESP_Debug_printInit()                         {}
template <typename Debug_T>
void ESP_Debug_print(const char* tag, Debug_T x)   {}

#endif // DEBUG == 1

// -------------------------------------
// TASKS
// -------------------------------------
void ESP_Debug_testTask(void *parameter) {
  int vInt = -5;
  int * vIntPtr = &vInt;
  float vFloat = 3.1415;
  double vDouble = 7.33E-2;
  String vString = "abcd";
  char * vCharPtr = "efgh";
  
  //Creation of a complex message in one line ^^
  String message = "Valeur : " + String(vInt) + ", Texte : " + vString + vCharPtr + ", Nombre : " + String(vFloat);

  ESP_Debug_print(TAG_debug, "Debug test task...");
  vTaskDelay(pdMS_TO_TICKS(500)); // Convertion in milli seconds
  
  ESP_Debug_print(TAG_debug, "Hello World");
  ESP_Debug_print(TAG_debug, vInt);
  ESP_Debug_print(TAG_debug, *vIntPtr);
  ESP_Debug_print(TAG_debug, vFloat);
  ESP_Debug_print(TAG_debug, vDouble);
  ESP_Debug_print(TAG_debug, vString);
  ESP_Debug_print(TAG_debug, vCharPtr);
  ESP_Debug_print(TAG_debug, message);
  
  ESP_Debug_print(TAG_debug, "Test OK");
  vTaskDelete(NULL); // if at the end the task is not delete the code will crash ! 
}

#endif // _DEBUG_HEADER_ 
