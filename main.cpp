/*
 * Copyright (c) 2006-2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

DigitalOut myled(LED1);

void blink(int waitTime);
void sInMorse();
void oInMorse();
void mInMorse();
void yInMorse();
void gInMorse();
void uInMorse();

int main()
{
    // check that myled object is initialized and connected to a pin
    if (myled.is_connected()) {
        printf("myled is initialized and connected!\n\r");
    }

    // Blink LED
    while (1) {
        mInMorse();

        wait_us(500000); // waits for 500ms

        yInMorse();

        wait_us(1000000); // waits for 1 second

        gInMorse();

        wait_us(500000); // waits for 500ms

        uInMorse();

        wait_us(500000); // waits for 500ms

        yInMorse();

        wait_us(3000000); // waits for 3 seconds
    }
}

// Lights LED1 for a specified amount of time
void blink(int waitTime) {
    myled = 1;          // set LED1 pin to high
    printf("myled = %d \n\r", (uint8_t)myled);
    wait_us(waitTime);

    myled.write(0);     // set LED1 pin to low
    printf("myled = %d \n\r", myled.read());
    wait_us(250000);
}

void sInMorse() {
    blink(200000);
    blink(200000);
    blink(200000);
}

void oInMorse() {
    blink(500000);
    blink(500000);
    blink(500000);
}

void mInMorse() {
    blink(500000);
    blink(500000);
}

void yInMorse() {
    blink(500000);
    blink(200000);
    blink(500000);
    blink(500000);
}

void gInMorse() {
    blink(500000);
    blink(500000);
    blink(200000);
}

void uInMorse() {
  blink(200000);
  blink(200000);
  blink(500000);
}