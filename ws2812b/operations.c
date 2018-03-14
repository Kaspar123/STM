#include "operations.h"

// buffer for storing temporary color value
uint8_t arr[8] = {0};
// buffer for storing text to be displayed
char TEXT[100] = {0};
// pointer to currently displayed letter
char *ptr = TEXT;
// slicing counter
uint16_t N = 0;

void toBuffer(uint8_t color) {
    for (uint8_t i = 0; i < 8; i++) {
        arr[i] = ((color << i) & 0x80) ? PWM_HIGH_WIDTH : PWM_LOW_WIDTH;
    }
}

void setLED(const uint16_t led, const uint8_t red, const uint8_t green, const uint8_t blue) {
    toBuffer(red);
    memcpy(pulses[led].r, arr, 8);
    toBuffer(green);
    memcpy(pulses[led].g, arr, 8);
    toBuffer(blue);
    memcpy(pulses[led].b, arr, 8);
}

void setLEDxy(const uint16_t x, const uint16_t y, const uint8_t red, const uint8_t green, uint8_t blue) {
    const uint16_t converted = convert(x, y);
    setLED(converted, red, green, blue);
}

void clear() {
    uint16_t i;
    uint8_t *strip = (uint8_t*) pulses;
    for (i = 0; i < MAXPIX * 24; i++) {
        strip[i] = PWM_LOW_WIDTH;
    }
    while (i++ < NUM_OF_BITS) {
        strip[i] = 0;
    }
}

void slice_small_letter(const uint8_t letter[], const uint8_t n, const uint8_t y_cord) {
    uint8_t slice = letter[n];
    for (uint8_t i = 0; i < 7; i++) {
        if ((slice >> i) & 0x01) setLEDxy(i, y_cord, 0, 100, 0);
    }
}

void slice_large_letter(const uint8_t letter[], const uint8_t n, const uint8_t y_cord) {
    uint8_t slice = letter[n];
    for (uint8_t i = 0; i < 7; i++) {
        if ((slice >> i) & 0x01) {
            setLEDxy(2 * i, y_cord, 0, 100, 0);
            setLEDxy(2 * i, y_cord + 1, 0, 100, 0);
            setLEDxy(2 * i + 1, y_cord, 0, 100, 0);
            setLEDxy(2 * i + 1, y_cord + 1, 0, 100, 0);
        }
    }
}

void slice_sign(const uint16_t sign[], const uint8_t n, const uint8_t y_cord, const uint8_t red, const uint8_t green, const uint8_t blue) {
    uint16_t slice = sign[n];
    for (uint8_t i = 0; i < 16; i++) {
        if ((slice >> i) & 0x0001) setLEDxy(i, y_cord, red, green, blue);
    }
}

void print_small_letter(const uint8_t letter[], const uint8_t y_cord) {
    for (uint8_t i = 0; i < 5; i++) slice_small_letter(letter, i, y_cord - i);
}

void print_large_letter(const uint8_t letter[], const uint8_t y_cord) {
    for (uint8_t i = 0; i < 5; i++) slice_large_letter(letter, i, y_cord - 2 * i - 1);
}

void print_sign(const uint16_t sign[], const uint8_t y_cord, const uint8_t red, const uint8_t green, const uint8_t blue) {
    for (uint8_t i = 0; i < 16; i++) slice_sign(sign, i, y_cord - i, red, green, blue);
}

void shiftRight(bool circular) {
    RGB temp[X];
    for (uint8_t i = 0; i < X; i++)
        temp[i] = pulses[convert(i, 0)];
    for (uint8_t i = 0; i < Y - 1; i++) {
        for (uint8_t j = 0; j < X; j++) {
            pulses[convert(j, i)] = pulses[convert(j, i + 1)];
        }
    }
    for (uint8_t i = 0; i < X; i++)
        if (circular) pulses[convert(i, Y - 1)] = temp[i];
        else setLEDxy(i, Y - 1, 0, 0, 0);
}

void shiftLeft(bool circular) {
    RGB temp[X];
    for (uint8_t i = 0; i < X; i++)
        if (circular) temp[i] = pulses[convert(i, Y - 1)];
    for (uint8_t i = Y - 1; i > 0; i--) {
        for (uint8_t j = 0; j < X; j++) {
            pulses[convert(j, i)] = pulses[convert(j, i - 1)];
        }
    }
    for (uint8_t i = 0; i < X; i++)
        if (circular) pulses[convert(i, 0)] = temp[i];
        else setLEDxy(i, 0, 0, 0, 0);
}

void writeText(const char *str) {
    strcpy(TEXT, str);
}

bool checkIfTextIsPresent(bool islarge) {
    if (*ptr) {
        const uint8_t *letter = ascii[INDEX(*ptr)];
        islarge ? slice_large_letter(letter, N++, 1) : slice_small_letter(letter, N++, 0);
        if (N == 6) {
            N = 0;
            *ptr = 0;
            ptr++;
        }
        return true;
    }
    ptr = TEXT;
    return false;
}
