#include "motor_control.h"
#include "firing_control.h"
#include "serial_commands.h"

void setup() {
    Serial.begin(9600);       
    motors_init();            
    firing_init();            
}

void loop() {
    handle_serial();          
}
