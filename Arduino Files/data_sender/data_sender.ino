#include <stdlib.h>

const int update_rate = 20000; // Update rate in ms (20 s)
int sensor_pin = 0; // ANALOG
long prev_millis = 0; // Stores our last color check time

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Only if update rate has passed
  if (millis() > prev_millis + update_rate) {
    prev_millis = millis(); // update lastMillis
    int reading = analogRead(sensor_pin);
    float voltage = reading / 1023.0 * 5.0; // convert to a voltage
    send_voltage(voltage);
  }

  // Bit of protection in case millis overruns:
  if (millis() < prev_millis)
    prev_millis = 0;
}

// Sends a voltage to the Python script
void send_voltage(float volts) {
  // convert data types
  char buffer[10];
  String v = dtostrf(volts, 5, 2, buffer);
  
  // create request command
  String request = "python /media/realroot/thingspeak_sender.py " + v;
  
  // adjust request so data type matches that required by system
  char command[request.length()+1];
  request.toCharArray(command, request.length()+1);
  Serial.println(command);
  system(command); // send command
}

// Helper function
// Converts a double to a string
char *dtostrf (double val, signed char width, unsigned char prec, char *sout) {
  char fmt[20];
  sprintf(fmt, "%%%d.%df", width, prec);
  sprintf(sout, fmt, val);
  return sout;
}

