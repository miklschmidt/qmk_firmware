#pragma once
#undef PRODUCT
#define PRODUCT         MiklsQuefrency
/*
 * I2C seems to randomly drop keystrokes. Not sure why. It seems a bit like
 * https://github.com/qmk/qmk_firmware/issues/5037, but that issue is closed,
 * and our problems happen even with underglow disabled.
 *
 * This issue occurs with multiple TRRS cables of different lengths from
 * different companies, so it's most likely not a cable issue.  It may be that
 * we are running into issues with long I2C runs, in which case stronger
 * pull-up resistors might help:
 * https://hackaday.com/2017/02/08/taking-the-leap-off-board-an-introduction-to-i2c-over-long-wires/.
 * For now, just don't use I2C.
 */
#define USE_SERIAL
// #define TAP_CODE_DELAY 56

// Use another port than b6, it's dead on the right Elite-C
#undef MATRIX_COL_PINS_RIGHT
#define MATRIX_COL_PINS_RIGHT { F5, F6, F7, B1, B3, B2, C7, C6 }

/* Use an extra LED on the right side since it's wider on the 65% PCB. */
#undef RGBLED_NUM
#define RGBLED_NUM 31
#define RGBLIGHT_LED_MAP { 6, 5, 4, 3, 2, 1, 0, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 }
/* Set up RGB lighting so it works with either side as master. */
// #define RGBLED_SPLIT { 12, 13 }
