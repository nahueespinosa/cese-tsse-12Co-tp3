#include "leds.h"

#define LEDS_ALL_OFF    0x0000
#define LEDS_ALL_ON     0xFFFF
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
    *address = LEDS_ALL_ON;
}

void Leds_TurnAllOff() {
    *address = LEDS_ALL_OFF;
}

bool Leds_IsOn(uint8_t led) {
    return false;
}