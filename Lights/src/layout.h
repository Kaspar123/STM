#ifndef __LAYOUT_H__
#define __LAYOUT_H__

#include <stm32f30x.h>

// parameters of the whole frame
#define MAXPIX 512
#define X 16
#define Y 32

// parameters of the building block
#define BX 8
#define BY 32

// total number of bits in frame(additional for > 50us)
#define ADDITIONAL          2
#define NUM_OF_BITS         ((MAXPIX + ADDITIONAL) * 24)

typedef struct RGB {
    uint8_t g[8];
    uint8_t r[8];
    uint8_t b[8];
} RGB;

RGB pulses[MAXPIX + ADDITIONAL];

uint16_t convert(const uint16_t x, const uint16_t y);
void unconvert(const uint16_t converted, uint16_t *const x, uint16_t *const y);

#endif
