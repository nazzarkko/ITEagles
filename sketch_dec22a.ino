// As usual, we'll create constants to name the pins we're using.
// This will make it easier to follow the code below.

const int sensorPin = 0;
// const int ledPin = 9;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 6;

// We'll also set up some global variables for the light level a calibration value and
//and a raw light value
int lightCal;
int lightVal;


void setup()
{
  Serial.begin(9600);
  // We'll set up the LED pin to be an output.
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  lightCal = 400;//analogRead(sensorPin);
  //we will take a single reading from the light sensor and store it in the lightCal
  //variable. This will give us a prelinary value to compare against in the loop
}

void getRGBfromLight(int &red, int &green, int &blue, int light) {
  float r = red/255.0;
  float g = green/255.0;
  float b = blue/255.0;
  float l = light/255.0 - 0.8;
  l = l*2;
  l = min(max(l,0), 1);
  Serial.println(l);

  red = 255*(l);
  green = 145*(l);
  blue = 255*(l);

}

void loop()
{
  //Take a reading using analogRead() on sensor pin and store it in lightVal
  lightVal = analogRead(sensorPin);

  int r,g,b;



  getRGBfromLight(r,g,b, (lightCal-lightVal));
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);

}