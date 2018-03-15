# ws2812b driver for STM32

ws2812b contains several parts:

   - ### config.h
        Configuration file that is used to configure PWM signal.  
        Config also contains all methods for ***GPIO, DMA, PWM Timer, Interrupt*** setup  
        ***GPIO_PWM_PIN*** is used to set output pin.  
        
   - ### layout.h
        Contains all math that is needed to convert coordinates to number on strip and  
        convert number on strip to corresponding coordinate (x,y).  
        <img src="img2.jpg" alt="Drawing" style="width: 50px;"/>
        
           MAXPIX - total number of leds connected (e.g. 512 leds)  
           BX - width of one building block (e.g. 8 leds)
           BY - height of one building block (e.g. 32 leds)  
           X - width of the wanted window (e.g. 16, 2 x BX)  
           Y - height of the wanted window (e.g. 32, 1 x BY)  
        
         Every led is defined as RGB struct. Strip is defined as array of RGB structs.  
         Defining parmeters BX, BY, X, Y allows to convert coordinate (X,Y) to  
         index of RGB struct array.  
         
         convert(10, 20) --> 162 (e.g. 162th led in strip)  
    
  - ### operations.h
        contains functions to render framebuffer and operate with leds
  - ### text.h
        Contains definitions of letters and special symbols.  
        All letters are represented with 5 bytes. For example letter A is represented as:  
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
        Contains definition of 16x16 led symbols.  
        Definitions of symbols follow the same logic as in text.h

    Signs can be visualized using ***print_sign()*** defined in [operations.h](operations.h)
