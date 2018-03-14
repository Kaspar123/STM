#include "layout.h"

uint16_t C1(const uint16_t x, const uint16_t y, uint16_t seg_start);
uint16_t C2(const uint16_t x, const uint16_t y, uint16_t seg_start);
void UN1(const uint16_t converted, uint16_t *const x, uint16_t *const y, uint16_t seg_length);
void UN2(const uint16_t converted, uint16_t *const x, uint16_t *const y, uint16_t seg_length);

uint16_t convert(const uint16_t x, const uint16_t y) {
  return C1(x, y, X - BX);
}

void unconvert(const uint16_t converted, uint16_t *const x, uint16_t *const y) {
  UN1(converted, x, y, BX);
}

uint16_t C1(const uint16_t x, const uint16_t y, uint16_t seg_start) {
  if (x < seg_start) return (Y * BX) + C2(x, y, seg_start - BX);
  return (y * BX) + ((y & 0x0001) ? (BX - (x % BX + 1)) : x % BX);
}

uint16_t C2(const uint16_t x, const uint16_t y, uint16_t seg_start) {
  if (x < seg_start) return (Y * BX) + C1(x, y, seg_start - BX);
  return ((Y - y - 1) * BX) + ((y & 0x0001) ? (BX - (x % BX + 1)) : x % BX);
}

void UN1(const uint16_t converted, uint16_t *const x, uint16_t *const y, uint16_t seg_length) {
  const uint16_t n = Y * seg_length;
  if (converted > (n - 1)) {
    UN2(converted, x, y, seg_length + seg_length);
    return;
  }
  *y = (converted / BX);
  *x = (*y & 0x0001) ? (BX - ((converted % BX) + 1)) : (converted % BX);
}

void UN2(const uint16_t converted, uint16_t *const x, uint16_t *const y, uint16_t seg_length) {
  const uint16_t n = Y * seg_length;
  if (converted > (n - 1)) {
    UN1(converted, x, y, seg_length + seg_length);
    return;
  }
  *y = Y - (converted / BX) - 1;
  *x = (*y & 0x0001) ? (BX - ((converted % BX) + 1)) : (converted % BX);
}
