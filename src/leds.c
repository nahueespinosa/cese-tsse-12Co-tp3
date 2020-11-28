#include "leds.h"

#define LEDS_ALL_OFF    0x0000
#define LED_OFFSET      1
#define LSB             1

static uint16_t *address;

uint16_t LedToMask(uint8_t led) {
    if (led > 16) {
        return 0;
    }

    return LSB << (led-LED_OFFSET);
}

void Leds_Create(uint16_t * port) {
    *port = LEDS_ALL_OFF;
    address = port;
}

void Leds_TurnOn(uint8_t led) {
    *address |= LedToMask(led);
}

void Leds_TurnOff(uint8_t led) {
    *address &= ~LedToMask(led);
}

void Leds_TurnAllOn() {
    *address = 0xFFFF;
}