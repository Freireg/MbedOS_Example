/* mbed Microcontroller Library
* Copyright (c) 2019 ARM Limited
* SPDX-License-Identifier: Apache-2.0
*/

/*
*-----------------------------------------
* Mbed OS example
* Simple Blinky threads
* Made in the LPC1768 Evaluation Board
* Made by: Guilherme Freire
*-----------------------------------------
*/
#include "mbed.h"
#include "platform/mbed_thread.h"
#include "rtos.h"


// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    50

/* 
* In the Mbed OS the Thread can be created with default configuration
* as shown in the "Task3" thread. But the user can also set the thread
* parameters as shown in the "Task1" and "Task2" threads. 
*/
Thread Task1(osPriorityNormal, 1024); 
Thread Task2(osPriorityBelowNormal, 1024);
Thread Task3;




void Blink2 (void)
{
    DigitalOut led2(LED2);

    while (true) {
        led2 = !led2;
        thread_sleep_for(BLINKING_RATE_MS);
    }
}

void Blink3 (void)
{
    DigitalOut led3(LED3);
    
    led3 = 1;
    while (true) {
        led3 = !led3;
        thread_sleep_for(BLINKING_RATE_MS);
    }
}

void Blink4 (void)
{
    DigitalOut led4(LED4);
    
    led4 = 1;
    while (true) {
        led4 = !led4;
        thread_sleep_for(BLINKING_RATE_MS);
    }
}

int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);

    /* Initialize the threads */
    Task3.start(Blink4);
    Task2.start(Blink3);
    Task1.start(Blink2);
    
    
    while (true) {
        led = !led;
        thread_sleep_for(BLINKING_RATE_MS);
    }
}
