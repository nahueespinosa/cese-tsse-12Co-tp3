#include <stdint.h>
#include <stdbool.h>

void Leds_Create(uint16_t * port);
void Leds_TurnOn(uint8_t led);
void Leds_TurnOff(uint8_t led);
void Leds_TurnAllOn();
void Leds_TurnAllOff();