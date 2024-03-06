#include <stdio.h>

#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC55S69_cm33_core0.h"
#include "fsl_debug_console.h"

#include "lcd.h"
#include "imag.h"

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

	LCD_Init(FLEXCOMM8_PERIPHERAL);

	LCD_Set_Bitmap((uint16_t *)imag_160x128);

	LCD_GramRefresh();

	while(1)
	{

	}

	return 0 ;
}
