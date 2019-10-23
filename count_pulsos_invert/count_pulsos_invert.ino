const byte interruptPin = 2; // intr 0
volatile unsigned long start_sec; // this is to hold start of sec
int centi_sec;
void setup()
{
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(0, update_sec_start, FALLING); // or RISING
}

void loop()
{
  // lots of code here
  // read your time: hr,min,sec;
  centi_sec = (millis()-start_sec);
  // printout time..
}

void update_sec_start() // this updates every second.
{
  start_sec=millis();
}
