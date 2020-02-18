#include "5x6.h"


#ifdef SSD1306OLED
void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    led_set_user(usb_led);
}
#endif

#ifndef __ASSEMBLER__
#include "is31fl3731-simple.h"

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
  {0, C1_1},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
  {0, C3_3},
  {0, C3_4},
};
#endif

void matrix_init_kb(void) {

    // // green led on
    // DDRD |= (1<<5);
    // PORTD &= ~(1<<5);

    // // orange led on
    // DDRB |= (1<<0);
    // PORTB &= ~(1<<0);

	matrix_init_user();
};


