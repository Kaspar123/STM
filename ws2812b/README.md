# ws2812b driver for STM32

ws2812b contains several parts:
  - ### layout.h
  - ### operations.h
        contains functions to render framebuffer and operate with leds
  - ### text.h
        contains definitions of letters and special symbols. All letters are represented with 5 bytes. For example letter A is represented as:
    Each number is hexadecimal representation on corresponding column, starting from the top of the letter.  
    A = { 0x3F, 0x48, 0x48, 0x48, 0x3F }
    
    0 0 0 0 0  } - unused  
    0 ***1*** ***1*** ***1*** 0  
    ***1*** 0 0 0 ***1***  
    ***1*** 0 0 0 ***1***  
    ***1*** ***1*** ***1*** ***1*** ***1***  
    ***1*** 0 0 0 ***1***  
    ***1*** 0 0 0 ***1***  
    ***1*** 0 0 0 ***1***  

    Letters are placed in array called ascii that can be indexed with the       ascii value of the letter:
    ```
    ascii[INDEX('A')] gives { 0x3F, 0x48, 0x48, 0x48, 0x3F }
    ```
    Letters can be visualized using ***print_small_letter()*** or ***print_large_letter()*** defined in [operations.h](operations.h)

  - #### signs.h
        contains definition of 16x16 led symbols. Definitions of symbols follow the same logic as in text.h

    Signs can be visualized using ***print_sign()*** defined in [operations.h](operations.h)
