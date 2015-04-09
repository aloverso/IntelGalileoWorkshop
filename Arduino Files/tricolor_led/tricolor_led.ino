// set variables to reference each pin number
int RED_PIN = 9;
int GREEN_PIN = 10;
int BLUE_PIN = 11;

// This function runs once as soon as the script uploads
void setup()
{
  // declare each pin as OUTPUT so we can write to it
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);  
}
 
// This function runs repeatedly
void loop()
{
  set_color(255, 0, 0);  // red
  delay(1000);
  set_color(0, 255, 0);  // green
  delay(1000);
  set_color(0, 0, 255);  // blue
  delay(1000);
  set_color(255, 255, 0);  // yellow
  delay(1000);  
  set_color(80, 0, 80);  // purple
  delay(1000);
  set_color(0, 255, 255);  // aqua
  delay(1000);
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
