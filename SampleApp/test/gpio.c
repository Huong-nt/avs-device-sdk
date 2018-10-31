

// RUN: gcc -Wall -o gpio gpio.c -lwiringPi

#include <wiringPi.h>
#include <stdio.h>


#define PIN 0

// static void waitForEnter(int pin) {
//     printf("Press SELECT to continue: ");
//     while (digitalRead(pin) == HIGH)  // Wait for push
//         delay(1);

//     while (digitalRead(pin) == LOW)  // Wait for release
//         delay(1);

//     printf("OK\n");
// }

int tick = 0;
int main(void) {
    wiringPiSetup();
    pinMode(PIN, INPUT);
    for (;;) {
        // waitForEnter(PIN);
        int current = digitalRead(PIN);
        if(!tick && (current == LOW)) tick = 1;
        if(tick && (current == HIGH)) {
            printf("OK\n");
            tick = 0;
        }
        delay(1);
    }
    return 0;
}
