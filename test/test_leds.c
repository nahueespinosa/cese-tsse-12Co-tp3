#include "unity.h"
#include "leds.h"

uint16_t ledsVirtuales;

void setUp(void) {
    Leds_Create(&ledsVirtuales);
}

void tearDown(void) {
}

void test_LedsOffAfterCreate(void) {
    uint16_t ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

void test_SingleLedTurnOn(void) {
    Leds_TurnOn(4);
    TEST_ASSERT_EQUAL_HEX16(0x8, ledsVirtuales);
}

void test_SingleLedTurnOff(void) {
    Leds_TurnOn(1);
    Leds_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}