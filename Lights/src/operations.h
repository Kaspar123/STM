#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__

#include <stm32f30x.h>
#include <string.h>
#include <stdbool.h>
#include "config.h"
#include "layout.h"
#include "text.h"
#include "signs.h"

void toBuffer(uint8_t color);
void setLED(const uint16_t led, const uint8_t red, const uint8_t green, const uint8_t blue);
void setLEDxy(const uint16_t x, const uint16_t y, const uint8_t red, const uint8_t green, uint8_t blue);
void clear();
void shiftRight(bool circular);
void shiftLeft(bool circular);

void slice_small_letter(const uint8_t letter[], const uint8_t n, const uint8_t y_cord);
void slice_large_letter(const uint8_t letter[], const uint8_t n, const uint8_t y_cord);
void slice_sign(const uint16_t sign[], const uint8_t n, const uint8_t y_cord, const uint8_t red, const uint8_t green, const uint8_t blue);

void print_small_letter(const uint8_t letter[], const uint8_t y_cord);
void print_large_letter(const uint8_t letter[], const uint8_t y_cord);
void print_sign(const uint16_t sign[], const uint8_t y_cord, const uint8_t red, const uint8_t green, const uint8_t blue);

void writeText(const char *str);
bool checkIfTextIsPresent(bool islarge);

#endif
