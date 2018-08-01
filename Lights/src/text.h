#ifndef __TEXT_H__
#define __TEXT_H__

#include <stm32f30x.h>

#define ASCII_LOWER 32 // ' '
#define ASCII_UPPER 90 // Z

#define INDEX(X) (X - ASCII_LOWER)

extern const uint8_t A_letter[];
extern const uint8_t B_letter[];
extern const uint8_t C_letter[];
extern const uint8_t D_letter[];
extern const uint8_t E_letter[];
extern const uint8_t F_letter[];
extern const uint8_t G_letter[];
extern const uint8_t H_letter[];
extern const uint8_t I_letter[];
extern const uint8_t J_letter[];
extern const uint8_t K_letter[];
extern const uint8_t L_letter[];
extern const uint8_t M_letter[];
extern const uint8_t N_letter[];
extern const uint8_t O_letter[];
extern const uint8_t P_letter[];
extern const uint8_t Q_letter[];
extern const uint8_t R_letter[];
extern const uint8_t S_letter[];
extern const uint8_t T_letter[];
extern const uint8_t U_letter[];
extern const uint8_t V_letter[];
extern const uint8_t W_letter[];
extern const uint8_t X_letter[];
extern const uint8_t Y_letter[];
extern const uint8_t Z_letter[];


extern const uint8_t n1[];
extern const uint8_t n2[];
extern const uint8_t n3[];
extern const uint8_t n4[];
extern const uint8_t n5[];
extern const uint8_t n6[];
extern const uint8_t n7[];
extern const uint8_t n8[];
extern const uint8_t n9[];
extern const uint8_t n0[];

extern const uint8_t QUEST_mark[];
extern const uint8_t EXC_mark[];
extern const uint8_t plus_sign[];
extern const uint8_t minus_sign[];
extern const uint8_t SPACE_letter[];

// ASCII mapping
extern const uint8_t* const ascii[ASCII_UPPER - ASCII_LOWER + 1];

#endif
