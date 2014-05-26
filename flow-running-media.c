#include <RunningMedian.h>
int sensor = 2; // Analog in
int val =0; // Current reading for analog pin
int MIDPOINT = 520; // Base reading for analogRead. Note this is equivalent to 0v due to 2.5 volt bias to op-amp. 1024 = 5v
int LOWLIM = 130; // Lower limit for the wave amplitude value
RunningMedian samples = RunningMedian(5);

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
long m = samples.getMedian(); // Running media of the wave amplitude
if (m > LOWLIM) {
Serial.println(m);
}
delay(100);
}
