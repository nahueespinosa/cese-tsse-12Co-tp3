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

void test_TurnOnSingleLed(void) {
    Leds_TurnOn(4);
    TEST_ASSERT_EQUAL_HEX16(0x8, ledsVirtuales);
}

void test_TurnOffSingleLed(void) {
    Leds_TurnOn(1);
    Leds_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

void test_TurnOnMultipleLeds(void) {
    Leds_TurnOn(7);
    Leds_TurnOn(10);
    TEST_ASSERT_EQUAL_HEX16(0x0240, ledsVirtuales);
}

void test_TurnOffMultipleLeds(void) {
    Leds_TurnAllOn();
    Leds_TurnOff(6);
    Leds_TurnOff(2);
    TEST_ASSERT_EQUAL_HEX16(0xFFDD, ledsVirtuales);
}

void test_TurnOnAllLeds() {
    Leds_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}