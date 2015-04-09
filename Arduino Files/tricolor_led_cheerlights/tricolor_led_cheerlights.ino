#include <stdlib.h>
#include <SD.h> // The SD library is used to read a temporary file,
                // where the py script stores a color value

int update_rate = 10000; // Update rate in ms (10 s)
long prev_millis = 0; // Stores our last color check time

// Initialize pin numbers
int RED_PIN = 9;
int GREEN_PIN = 10;
int BLUE_PIN = 11;

// variables to store the value for each pin
int r;
int g;
int b;

void setup() 
{
  Serial.begin(9600); // Serial monitor is used for debug
  SD.begin();  // initialize the SD reader so we can access the SD on the Galileo
  // set pinmode for each LED pin to output so we can write their values
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

// loop() checks for a new color after the updateRate time had passed
// If the color has changed, update the display.
void loop() 
{
  // Only check email if emailUpdateRate ms have passed
  if (millis() > prev_millis + update_rate)
  {
    prev_millis = millis(); // update prev_millis
    // Get see if color changed
    update_colors();
    set_color(r,g,b);
  }
  
  // Bit of protection in case millis overruns:
  if (millis() < prev_millis)
    prev_millis = 0;
}


// update_colors runs our cheerlights python script and parses its
// color output into a file that we can read
void update_colors()
{
  // Send a system call to run our python script and route the
  // output of the script to a file.
  system("python /media/realroot/cheerlights_receiver.py > /media/realroot/colors");
  File colors_file = SD.open("colors"); // open emails for reading
  
  // read from colors until we hit the a newline
  while (colors_file.peek() != '\n') {
    r = colors_file.parseInt();
    g = colors_file.parseInt();
    b = colors_file.parseInt();
  }

// Use these for debug if necessary
//   Serial.println(r);
//   Serial.println(g);
//   Serial.println(b);

  colors_file.close(); // close the colors file
  system("rm /media/realroot/colors"); // remove the colors file
}

// This is a function that we created, which will take the
// three RBG color values and write each one to its
// corresponding pin
void set_color(int red, int green, int blue)
{
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);  
}
