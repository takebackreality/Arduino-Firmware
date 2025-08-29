#include "serial_commands.h"
#include "motor_control.h"
#include "firing_control.h"

void handle_serial() {
    if (Serial.available()) {
        char cmd = Serial.read();

        if (cmd == 'F') {
            fire();
        }
        else if (cmd == 'M') {
            int pan = Serial.parseInt();
            int tilt = Serial.parseInt();
            set_angles(pan, tilt);
        }
    }
}
