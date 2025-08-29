#include "firing_control.h"

int firePin = 7;   

void firing_init() {
    pinMode(firePin, OUTPUT);
    digitalWrite(firePin, LOW);
}

void fire() {
    digitalWrite(firePin, HIGH);   
    delay(200);                    
    digitalWrite(firePin, LOW);
}
