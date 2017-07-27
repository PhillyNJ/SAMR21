/* SAMR21 i2c SSD1306 oled (.98 inch) 
   The xplained pro says the i2c is on SERCOM 1 which is WRONG. Its SERCOM3!
   
   [TWI_SDA] PA16 SERCOM3 PAD[0] I²C SDA EXT1
   [TWI_SCL] PA17 SERCOM3 PAD[1] I²C SCL EXT1

*/
#include <asf.h>

#include "conf_usart.h"
#include "ssd1306_i2c.h"
#include "ssd1306_oled.h"
#include "misc_images.h"
#include "icons.h"
#include "chip.h"

extern const unsigned char arial_8ptBitmaps[];
extern const unsigned char charMap[96];
extern const unsigned int arial_8ptDescriptors[96][3];

extern const unsigned char courierNew_16ptBitmaps[];
extern const unsigned int courierNew_16ptDescriptors[96][3];

extern const unsigned char freestyleScript_22ptBitmaps[];
extern const unsigned int freestyleScript_22ptDescriptors[96][3];

extern const unsigned char kristenITC_14ptBitmaps[];
extern const unsigned int kristenITC_14ptDescriptors[96][3];

void loop_demo(void);

int main (void)
{
	system_init();
	configure_console(115200);
	printf("SAMR21 i2c OLED Tutorial\n\r");
	delay_init();
	configure_i2c();
	init_oled();
	
#if defined(SAMD21)
printf("Compiled for SAMD21\r");
#elif defined(SAMR21)
printf("Compiled for SAMR21\r");
#elif  defined(SAM4S)
printf("Compiled for SAM4s\r");
#endif
	
	while (1) {
		
		loop_demo();

		if (port_pin_get_input_level(BUTTON_0_PIN) == BUTTON_0_ACTIVE) {
			
			port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
			oled_clear();
			oled_setFont(freestyleScript_22ptBitmaps, freestyleScript_22ptDescriptors,96, charMap, 5);
			oled_clear();
			oled_printf(0,0, "Fonts");
			oled_update();
			oled_drawBitmap(star, 24, 24, 10,20);
			oled_update();
			delay_s(1);
			oled_clear();
			oled_printf(0,0, "Rain");
			oled_drawBitmap(rain, 48, 48, 30,20);
			oled_update();
			delay_s(1);
			oled_clear();
			oled_printf(0,0, "Wind");
			oled_drawBitmap(windy, 48, 48, 30,20);
			oled_update();
			delay_s(1);
			oled_clear();
		} else {
			/* No, so turn LED off. */
			port_pin_set_output_level(LED_0_PIN, !LED_0_ACTIVE);
		}
	}
}

void loop_demo(void){

	oled_setFont(courierNew_16ptBitmaps, courierNew_16ptDescriptors,96, charMap, 2);
	oled_drawBitmap(chip,64,64,32,0);
	oled_update();
	delay_s(2);
	oled_clear();
	oled_printf(1,1,"SSD1306");
	oled_printf(10,20,"Demo");
	oled_update();
	delay_s(1);
	oled_clear_line(1);
	oled_setFont(kristenITC_14ptBitmaps, kristenITC_14ptDescriptors,96, charMap, 5);
	oled_printf(1,1,"OLED");
	oled_update();
	delay_s(1);
	oled_clear();
	oled_setFont(freestyleScript_22ptBitmaps, freestyleScript_22ptDescriptors,96, charMap,0);
	oled_printf(10,1,"All");
	oled_printf(1,25,"Sizes");
	oled_setFont(kristenITC_14ptBitmaps, kristenITC_14ptDescriptors,96, charMap, -5);
	oled_printf(15,52,"Fonts");
	oled_update();
	delay_s(1);
	oled_clear_line(50);
	oled_setFont(arial_8ptBitmaps, arial_8ptDescriptors,96, charMap, -3);
	oled_printf(15,55,"Arial");
	oled_update();
	delay_s(1);
	oled_clear();
	oled_setFont(courierNew_16ptBitmaps, courierNew_16ptDescriptors,96, charMap, 0);
	oled_printf(15,1,"Cool");
	oled_printf(10,20,"Fonts");
	oled_update();
	delay_s(1);
	oled_clear();
	oled_drawCircle(64, 32, 25);
	oled_update();
	delay_s(1);
	oled_clear();	
	oled_drawRectangle(1,10, 40,50);	
	oled_update();
	delay_s(1);
	oled_clear();
	oled_drawRectangle_fill(10,10, 60,50, 1);
	oled_update();
	delay_s(1);
	oled_clear();
	oled_draw_triangle(50,1, 1,50, 100, 15);
	oled_update();
	delay_s(1);
	oled_clear();
}

