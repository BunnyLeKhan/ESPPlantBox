#ifndef _DEBUG_HEADER_
#define _DEBUG_HEADER_ 

// -------------------------------------
// INCLUDES
// -------------------------------------
#include "ESP_Configuration.h"

// -------------------------------------
// FUNCTION
// -------------------------------------
#if DEBUG == 1
/* Casual print function
 * arg tag  : TAG from the function (ex: main)
 * arg text : text u want to print  (ex: abcd...)
 */
void ESP_Debug_printText(const char * tag, char * text) {
  Serial.print(tag);
  Serial.println(text);
  Serial.println("\n");
}

/* Casual print function
 * arg tag  : TAG from the function (ex: main)
 * arg text : text u want to print  (ex: abcd...)
 */
void ESP_Debug_printString(const char * tag, String strg) {
  Serial.print(tag);
  Serial.println(strg);
  Serial.println("\n");
}

/* Init print function */
void ESP_Debug_printInit() {
  Serial.println("ESPlant is an open-source project about an plant box monitored by an ESP32");
  Serial.println("Author : Corentn Cuomo-Graff - Guillaume Frick");
  Serial.println("Date : 02 june 2023");
}

template <typename Debug_T>
void ESP_Debug_printValue(const char* tag, Debug_T value) {
  Serial.print(tag);
  Serial.println(value);
  Serial.println();
}

#else 
void ESP_Debug_printString(const char * tag, String strg)   {}
void ESP_Debug_printText(const char * tag, char * text)     {}
void ESP_Debug_printInit()                                  {}
template <typename Debug_T>
void ESP_Debug_printValue(const char* tag, Debug_T value)   {}

#endif // DEBUG == 1

#endif // _DEBUG_HEADER_ 
