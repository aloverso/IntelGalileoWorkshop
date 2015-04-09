
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
  for (int i=0; i<255; i++)  // First phase of fades from red to green
  {
    set_color(255-i, i, 0);
  }
  for (int i=0; i<255; i++) // Second phase of fades from green to blue
  {
    set_color(0,255-i,i);
  }
  for (int i=0; i<255; i++) // Third phase of fades from blue back to red
  {
    set_color(i,0,255-i);
  } 
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
