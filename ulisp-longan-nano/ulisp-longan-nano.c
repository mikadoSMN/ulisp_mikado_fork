/* uLisp RISC-V Sipeed longan nano
   progect started 05/22/2025

   Licensed under the MIT license: https://opensource.org/licenses/MIT
*/

// Lisp Library
const char LispLibrary[] PROGMEM = "";

// Compile options

#define checkoverflow
// #define resetautorun
#define printfreespace
// #define printgcs
// #define sdcardsupport
// #define lisplibrary
#define assemblerlist
// #define lineeditor
// #define vt100
// #define extensions

// Includes

// #include "LispLibrary.h"
#include <avr/sleep.h>
#include <setjmp.h>
#include <SPI.h>
#include <limits.h>

#if defined(sdcardsupport)
#include <SD.h>
#define DSDIZE 172
#else
#define SDSIZE 0
#endif

// Platform specific setting プラットフォーム特定のセッティング

#define WORDALIGNED __attribute__((aligned (2)))
#define OBJECTALIGNED __attribute__((aligned (4)))
#define BUFFERSIZE 22 /* longest  builting name +1 バッファのサイズは最も長いビルディングネーム + 1 */

#if defined(ARDUINO_AVR_MEGA2056)
  #include <EEPROM.h>
