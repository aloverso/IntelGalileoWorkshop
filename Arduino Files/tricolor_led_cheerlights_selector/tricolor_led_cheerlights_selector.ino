#include <SD.h> // The SD library is used to read a temporary file,
                // where the py script stores a color value

int update_rate = 10000; // Update rate in ms (10 s)
long prev_millis = 0; // Stores our last color check time
// TODO: store the previous button value

// Initialize pin numbers
int RED_PIN = 11;
int GREEN_PIN = 10;
int BLUE_PIN = 9;
// TODO: Add variable for button pin

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
  // TODO: Set pin mode for button pin
}

// loop() checks for a new color after the update_rate time had passed
// If the color has changed, update the display.
void loop() 
{
  // TODO: Print current button value to Serial
 
  // TODO: If button reading has changed from 1 to 0, call
  // a function to execute python script to tweet a new color
  
  // TODO: update the previous button value
  
  // Only check for new colors if update rate has passed
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


// updateColors runs our cheerlights python script and parses its
// color output into a file that we can read
void update_colors()
{
  // Send a system call to run our python script and route the
  // output of the script to a file.
  system("python /media/realroot/cheerlights_receiver.py > /media/realroot/colors");
  File colors_file = SD.open("colors"); // open emails for reading
  
  // read from colors until we hit a newline
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

// TODO: Create a function
// This function calls our python script to send a 
// random new color in a tweet to cheerlights

