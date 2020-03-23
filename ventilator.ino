// GPIO
int output_DIR = 8;
int output_PUL = 9;

// Number of steps in motor step
const uint8_t microsteps = 2;
// Number of steps/revolution. Motor step angle: 0.9
const uint16_t number_of_steps = 400 * microsteps;

// Respiratory rate: this is also the motor RPM
uint8_t RR = 11;
// Microseconds to wait between falling and rising edges
unsigned pulseDelay = (((60 * 1000000) / number_of_steps) / RR) / 2;
boolean motorDirection = HIGH;

/**
 * Set PUL and DIR GPIO modes to OUTPUT.
 */
void setup() {
    pinMode(output_PUL, OUTPUT);
    pinMode(output_DIR, OUTPUT);
    digitalWrite(output_DIR, motorDirection);
}

/**
 * Generates simple pulse signal on PUL Output
 */
void loop() {
    digitalWrite(output_PUL, HIGH);
    delayMicroseconds(pulseDelay);
    digitalWrite(output_PUL, LOW);
    delayMicroseconds(pulseDelay);
}
