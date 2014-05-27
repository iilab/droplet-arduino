#include <RunningMedian.h>

int sensor = 2; // Analog in
int val =0; // Current reading for analog pin
int MIDPOINT = 520; // Base reading for analogRead. Note this is equivalent to 0v due to 2.5 volt bias to op-amp. 1024 = 5v 
int LOWLIM = 130; // Lower limit for the wave amplitude value
RunningMedian samples = RunningMedian(10); //running meadian with the size of the sample window

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(sensor); //read analogue input pin A2
  // Compute wave amplitude
  if (val > MIDPOINT) {
    val = val - MIDPOINT;
  } else {
    val = MIDPOINT - val;
  }
  samples.add(val);
  long m = samples.getMedian(); // Running median of the wave amplitude  
  long a = samples.getAverage(); // Running average 
  Serial.print(millis());
  Serial.print(",");
  Serial.print(val);
  Serial.print(",");
  Serial.print(m);  
  Serial.print(",");
  Serial.print(a);
  Serial.print(",");
  if (m > LOWLIM) {
    Serial.print("1");
  }
  else{
    Serial.print("0");
  }
  Serial.println();
    delay(100);
}
