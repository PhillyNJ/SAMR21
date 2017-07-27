#include <asf.h>
#include "conf_usart.h"

#define BLINK_PERIOD 1000
volatile uint32_t g_ul_ms_ticks = 0;
volatile bool g_b_systick_event = false;

int main (void)
{
	system_init();
	delay_init();
	configure_console(115200);
	printf("SAMR21 sys tick example\n");
	SysTick_Config(system_gclk_chan_get_hz(GCLK_GENERATOR_0)/1000);		

	while (1) {
	
		if(g_b_systick_event == true){
			g_b_systick_event = false;
			if(g_ul_ms_ticks % BLINK_PERIOD == 0){
				port_pin_toggle_output_level(LED_0_PIN);
				g_ul_ms_ticks = 0;
				
			}
		}
	}
}
void SysTick_Handler (void)
{
	g_ul_ms_ticks++;
	g_b_systick_event = true;
	
}