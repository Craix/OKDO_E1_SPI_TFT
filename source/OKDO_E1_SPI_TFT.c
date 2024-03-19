#include <stdio.h>

#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC55S69_cm33_core0.h"
#include "fsl_debug_console.h"

#include "lcd.h"
#include "imag.h"

uint16_t out[8][256];

const uint16_t imag[] = {
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x4483, 0x4483, 0xB926, 0xB926, 0x68EC, 0x68EC, 0x5A05, 0x5A05, 0xE486, 0xE486, 0x68EC, 0x68EC, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0x68EC, 0x68EC, 0x0000, 0x0000,
0x0000, 0x0000, 0x4483, 0x4483, 0xB926, 0xB926, 0x68EC, 0x68EC, 0x5A05, 0x5A05, 0xE486, 0xE486, 0x68EC, 0x68EC, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0x68EC, 0x68EC, 0x0000, 0x0000,
0x0000, 0x0000, 0x68EC, 0x68EC, 0x4A69, 0x4A69, 0x13D5, 0x13D5, 0x7DE3, 0x7DE3, 0xB926, 0xB926, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0x68EC, 0x68EC, 0x0000, 0x0000,
0x0000, 0x0000, 0x68EC, 0x68EC, 0x4A69, 0x4A69, 0x13D5, 0x13D5, 0x7DE3, 0x7DE3, 0xB926, 0xB926, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0x68EC, 0x68EC, 0x0000, 0x0000,
0x0000, 0x0000, 0xB926, 0xB926, 0x5A05, 0x5A05, 0xE486, 0xE486, 0x4A69, 0x4A69, 0x13D5, 0x13D5, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0x68EC, 0x68EC, 0x0000, 0x0000,
0x0000, 0x0000, 0xB926, 0xB926, 0x5A05, 0x5A05, 0xE486, 0xE486, 0x4A69, 0x4A69, 0x13D5, 0x13D5, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0x68EC, 0x68EC, 0x0000, 0x0000,
0x0000, 0x0000, 0x13D5, 0x13D5, 0x4483, 0x4483, 0xB926, 0xB926, 0xE486, 0xE486, 0x5A05, 0x5A05, 0x13D5, 0x13D5, 0x0000, 0x0000, 0x0000, 0x0000, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0x68EC, 0x68EC, 0x0000, 0x0000,
0x0000, 0x0000, 0x13D5, 0x13D5, 0x4483, 0x4483, 0xB926, 0xB926, 0xE486, 0xE486, 0x5A05, 0x5A05, 0x13D5, 0x13D5, 0x0000, 0x0000, 0x0000, 0x0000, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0x68EC, 0x68EC, 0x0000, 0x0000,
0x0000, 0x0000, 0xE486, 0xE486, 0x68EC, 0x68EC, 0x4483, 0x4483, 0xB926, 0xB926, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0x68EC, 0x68EC, 0x0000, 0x0000,
0x0000, 0x0000, 0xE486, 0xE486, 0x68EC, 0x68EC, 0x4483, 0x4483, 0xB926, 0xB926, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x7DE3, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xDA8E, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0xAA97, 0x68EC, 0x68EC, 0x0000, 0x0000,
0x0000, 0x0000, 0x13D5, 0x13D5, 0x4483, 0x4483, 0xB926, 0xB926, 0x68EC, 0x68EC, 0x5A05, 0x5A05, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x0000, 0x0000,
0x0000, 0x0000, 0x13D5, 0x13D5, 0x4483, 0x4483, 0xB926, 0xB926, 0x68EC, 0x68EC, 0x5A05, 0x5A05, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x4483, 0x0000, 0x0000, 0x0000, 0x0000, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0xB926, 0x0000, 0x0000, 0x0000, 0x0000, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x68EC, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x5A05, 0x5A05, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x13D5, 0x13D5, 0x0000, 0x0000,
0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x5A05, 0x5A05, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x13D5, 0x13D5, 0x0000, 0x0000,
0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x5A05, 0x5A05, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x13D5, 0x13D5, 0x0000, 0x0000,
0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x5A05, 0x5A05, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x13D5, 0x13D5, 0x0000, 0x0000,
0x0000, 0x0000, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x5A05, 0x5A05, 0x0000, 0x0000, 0x0000, 0x0000, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x13D5, 0x13D5, 0x0000, 0x0000,
0x0000, 0x0000, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x5A05, 0x5A05, 0x0000, 0x0000, 0x0000, 0x0000, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x13D5, 0x13D5, 0x0000, 0x0000,
0x0000, 0x0000, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x5A05, 0x5A05, 0x0000, 0x0000, 0x0000, 0x0000, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x13D5, 0x13D5, 0x0000, 0x0000,
0x0000, 0x0000, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x5A05, 0x5A05, 0x0000, 0x0000, 0x0000, 0x0000, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x13D5, 0x13D5, 0x0000, 0x0000,
0x0000, 0x0000, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x5A05, 0x5A05, 0x0000, 0x0000, 0x0000, 0x0000, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x13D5, 0x13D5, 0x0000, 0x0000,
0x0000, 0x0000, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x8AE9, 0x5A05, 0x5A05, 0x0000, 0x0000, 0x0000, 0x0000, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xF58E, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x351D, 0x13D5, 0x13D5, 0x0000, 0x0000,
0x0000, 0x0000, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x0000, 0x0000, 0x0000, 0x0000, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x0000, 0x0000,
0x0000, 0x0000, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x4A69, 0x0000, 0x0000, 0x0000, 0x0000, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x5A05, 0x0000, 0x0000, 0x0000, 0x0000, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0xE486, 0x0000, 0x0000, 0x0000, 0x0000, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x13D5, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

void splitImmage(uint16_t * input, uint16_t inputX, uint16_t inputY, uint16_t * output, uint16_t outputX, uint16_t outputY)
{
    int i = 0;

    for(int iy = 0; iy < (inputY / outputY); iy++)
    {
        for(int ix = 0;  ix < (inputX / outputX); ix++)
        {
            for(int oy = 0; oy < outputY; oy++)
            {
                for(int ox = 0; ox < outputX; ox++)
                {
                    output[i++] = input[((iy * outputY) + oy) * inputX + ((ix * outputX) + ox)];
                }
            }
        }
    }
}

int main(void)
{
	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();

	#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
	#endif

	splitImmage((uint16_t *)imag, 64, 32, (uint16_t *)out, 16, 16);

	LCD_Init(FLEXCOMM8_PERIPHERAL);

	LCD_Clear(_BLUE);

	LCD_Set_ImagePart(out[0], 16, 16, 16, 16);

	LCD_Draw_Line(0,0, 50,50,_RED);

	LCD_GramRefresh();

	while(1)
	{

	}

	return 0 ;
}
