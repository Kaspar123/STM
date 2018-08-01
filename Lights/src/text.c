#include "text.h"

const uint8_t A_letter[] = {0x3F, 0x48, 0x48, 0x48, 0x3F};
const uint8_t B_letter[] = {0x7F, 0x49, 0x49, 0x49, 0x36};
const uint8_t C_letter[] = {0x3E, 0x41, 0x41, 0x41, 0x22};
const uint8_t D_letter[] = {0x7F, 0x41, 0x41, 0x41, 0x3E};
const uint8_t E_letter[] = {0x7F, 0x49, 0x49, 0x49, 0x41};
const uint8_t F_letter[] = {0x7F, 0x48, 0x48, 0x48, 0x40};
const uint8_t G_letter[] = {0x3E, 0x41, 0x41, 0x45, 0x06};
const uint8_t H_letter[] = {0x7F, 0x08, 0x08, 0x08, 0x7F};
const uint8_t I_letter[] = {0x00, 0x41, 0x7F, 0x41, 0x00};
const uint8_t J_letter[] = {0x02, 0x41, 0x41, 0x41, 0x7E};
const uint8_t K_letter[] = {0x7F, 0x08, 0x14, 0x22, 0x41};
const uint8_t L_letter[] = {0x7F, 0x01, 0x01, 0x01, 0x01};
const uint8_t M_letter[] = {0x7F, 0x20, 0x18, 0x20, 0x7F};
const uint8_t N_letter[] = {0x7F, 0x20, 0x10, 0x08, 0x7F};
const uint8_t O_letter[] = {0x3E, 0x41, 0x41, 0x41, 0x3E};
const uint8_t P_letter[] = {0x7F, 0x48, 0x48, 0x48, 0x30};
const uint8_t Q_letter[] = {0x3E, 0x41, 0x45, 0x43, 0x3F};
const uint8_t R_letter[] = {0x7F, 0x48, 0x4C, 0x4A, 0x31};
const uint8_t S_letter[] = {0x31, 0x49, 0x49, 0x49, 0x46};
const uint8_t T_letter[] = {0x40, 0x40, 0x7F, 0x40, 0x40};
const uint8_t U_letter[] = {0x7E, 0x01, 0x01, 0x01, 0x7E};
const uint8_t V_letter[] = {0x7C, 0x02, 0x01, 0x02, 0x7C};
const uint8_t W_letter[] = {0x7F, 0x02, 0x04, 0x02, 0x7F};
const uint8_t X_letter[] = {0x63, 0x14, 0x08, 0x14, 0x63};
const uint8_t Y_letter[] = {0x60, 0x10, 0x0F, 0x10, 0x60};
const uint8_t Z_letter[] = {0x43, 0x45, 0x49, 0x51, 0x61};

const uint8_t n1[] = {0x01, 0x21, 0x7F, 0x01, 0x01};
const uint8_t n2[] = {0x21, 0x43, 0x45, 0x49, 0x31};
const uint8_t n3[] = {0x22, 0x41, 0x49, 0x49, 0x36};
const uint8_t n4[] = {0x08, 0x18, 0x28, 0x7F, 0x08};
const uint8_t n5[] = {0x72, 0x51, 0x51, 0x51, 0x4E};
const uint8_t n6[] = {0x3E, 0x49, 0x49, 0x49, 0x26};
const uint8_t n7[] = {0x40, 0x40, 0x4F, 0x50, 0x60};
const uint8_t n8[] = {0x36, 0x49, 0x49, 0x49, 0x36};
const uint8_t n9[] = {0x32, 0x49, 0x49, 0x49, 0x3F};
const uint8_t n0[] = {0x3E, 0x41, 0x41, 0x41, 0x3E};

const uint8_t QUEST_mark[] = {0x20, 0x40, 0x45, 0x48, 0x30};
const uint8_t EXC_mark[] = {0x00, 0x00, 0x7D, 0x00, 0x00};
const uint8_t plus_sign[] = {0x08, 0x08, 0x3E, 0x08, 0x08};
const uint8_t minus_sign[] = {0x08, 0x08, 0x08, 0x08, 0x08};
const uint8_t SPACE_letter[] = {0x00, 0x00, 0x00, 0x00, 0x00};

// ASCII mapping
const uint8_t* const ascii[ASCII_UPPER - ASCII_LOWER + 1] = {
        [INDEX('A')] = A_letter,
        [INDEX('B')] = B_letter,
        [INDEX('C')] = C_letter,
        [INDEX('D')] = D_letter,
        [INDEX('E')] = E_letter,
        [INDEX('F')] = F_letter,
        [INDEX('G')] = G_letter,
        [INDEX('H')] = H_letter,
        [INDEX('I')] = I_letter,
        [INDEX('J')] = J_letter,
        [INDEX('K')] = K_letter,
        [INDEX('L')] = L_letter,
        [INDEX('M')] = M_letter,
        [INDEX('N')] = N_letter,
        [INDEX('O')] = O_letter,
        [INDEX('P')] = P_letter,
        [INDEX('Q')] = Q_letter,
        [INDEX('R')] = R_letter,
        [INDEX('S')] = S_letter,
        [INDEX('T')] = T_letter,
        [INDEX('U')] = U_letter,
        [INDEX('V')] = V_letter,
        [INDEX('W')] = W_letter,
        [INDEX('X')] = X_letter,
        [INDEX('Y')] = Y_letter,
        [INDEX('Z')] = Z_letter,
        // --- special symbols
        [INDEX('!')] = EXC_mark,
        [INDEX('?')] = QUEST_mark,
        [INDEX(' ')] = SPACE_letter
};
