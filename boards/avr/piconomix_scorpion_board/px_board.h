#ifndef __PX_BOARD_H__
#define __PX_BOARD_H__
/* =============================================================================
     ____    ___    ____    ___    _   _    ___    __  __   ___  __  __ TM
    |  _ \  |_ _|  / ___|  / _ \  | \ | |  / _ \  |  \/  | |_ _| \ \/ /
    | |_) |  | |  | |     | | | | |  \| | | | | | | |\/| |  | |   \  /
    |  __/   | |  | |___  | |_| | | |\  | | |_| | | |  | |  | |   /  \
    |_|     |___|  \____|  \___/  |_| \_|  \___/  |_|  |_| |___| /_/\_\

    Copyright (c) 2013 Pieter Conradie <https://piconomix.com>
 
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to
    deal in the Software without restriction, including without limitation the
    rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
    sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
   
    Title:          px_board.h : Piconomix ATmega328P Scorpion Board
    Author(s):      Pieter Conradie
    Creation Date:  2013-12-10

============================================================================= */
/** 
 *  @ingroup BOARDS_AVR
 *  @defgroup BOARDS_AVR_PICONOMIX_SCORPION px_board.h : Piconomix ATmega328P Scorpion Board
 *  
 *  ![Piconomix ATmega328P Scorpion Board](piconomix_scorpion_board/piconomix_scorpion_board.jpg)
 *  
 *  File(s):
 *  - boards/avr/piconomix_scorpion_board/px_board.h 
 *  - boards/avr/piconomix_scorpion_board/px_board_gpio.h 
 *  - boards/avr/piconomix_scorpion_board/px_board.c
 */   
/// @{

/* _____STANDARD INCLUDES____________________________________________________ */

/* _____PROJECT INCLUDES_____________________________________________________ */
#include "px_defines.h"
#include "px_board_gpio.h"

#ifdef __cplusplus
extern "C" {
#endif
/* _____DEFINITIONS__________________________________________________________ */
/// Board name
#define BOARD_AVR_PICONOMIX_SCORPION

/// Processor frequency in Hz
#ifndef F_CPU
#define F_CPU           7372800ul
#endif

/// @name ADC Channel mux definitions
//@{
#define ADC0    1
#define ADC1    0
#define ADC2    7
#define ADC3    6
//@}

/* _____TYPE DEFINITIONS_____________________________________________________ */
/// Identify which GPIO pins are used for CS in board_spi_cs_lo() and board_spi_cs_hi()
typedef enum
{
    PX_BOARD_SPI_CS_NONE = 0,
    PX_BOARD_SPI_CS,                ///< General CS pin on SPI header
    PX_BOARD_SPI_CS_DF,             ///< Adesto AT45D DataFlash
} px_board_spi_cs_t;

/* _____GLOBAL VARIABLES_____________________________________________________ */

/* _____GLOBAL FUNCTION DECLARATIONS_________________________________________ */
/// Initialise the board hardware
extern void px_board_init(void);

/**
 *  Set specified SPI Chip Select low
 *  
 *  @param cs_id    ID which GPIO pin must be used for Chip Select
 */
extern void px_board_spi_cs_lo(uint8_t cs_id);

/**
 *  Set specified SPI Chip Select high
 *  
 *  @param cs_id    ID which GPIO pin must be used for Chip Select
 */
extern void px_board_spi_cs_hi(uint8_t cs_id);

/**
 * Blocking delay for specified number of microseconds.
 *  
 * @param delay_us  Number of microseconds to block
 */
extern void px_board_delay_us(uint16_t delay_us);

/**
 *  Blocking delay for specified number of milliseconds.
 *  
 *  @param delay_ms  Number of milliseconds to block
 */
void px_board_delay_ms(uint16_t delay_ms);

/* _____MACROS_______________________________________________________________ */
/// Detect if push button is being pressed
#define PX_PB_IS_PRESSED()  PX_GPIO_PIN_IS_LO(PX_GPIO_PB)

/// Enable LED
#define PX_LED_ON()         PX_GPIO_PIN_SET_HI(PX_GPIO_LED)
/// Disable LED
#define PX_LED_OFF()        PX_GPIO_PIN_SET_LO(PX_GPIO_LED)
/// Toggle LED
#define PX_LED_TOGGLE()     PX_GPIO_PIN_TOGGLE(PX_GPIO_LED)

// Select UART Port 0
#define PX_UART_SEL_0()     PX_GPIO_PIN_SET_HI(PX_GPIO_UART_SEL)
// Select UART Port 1
#define PX_UART_SEL_1()     PX_GPIO_PIN_SET_LO(PX_GPIO_UART_SEL)

/// @}
#ifdef __cplusplus
}
#endif

#endif // #ifndef __PX_BOARD_H__
