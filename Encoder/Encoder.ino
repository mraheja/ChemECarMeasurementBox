  
  #define CLK 2
  #define DT 3
  #define SW 4
  
  int counter = 0; // how many clicks there has been (+ for CW)
  int currentStateCLK;
  int lastStateCLK;
  String currentDir = "";
  const float pi = 3.14;
  const float R = 3.25; // the radius of the wheel
  const int N = 40; // how many clicks per one wheel rotation
  float distance = 0;
  float prevDistance = 0;
  unsigned long currTime = 0;
  unsigned long prevTime = 0;
  float currSpeed = 0;

 void setup() {
  
  // Set encoder pins as inputs
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

  // Setup Serial Monitor
  Serial.begin(9600);

  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);
}

 void loop() {

  // Keeps track of the time passed
  currTime = millis();
  
   // Read the current state of CLK
   currentStateCLK = digitalRead(CLK);

   // If last and current state of CLK are different, then pulse occurred
   // React to only 1 state change to avoid double count
   if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {
      counter ++;
      currentDir ="CW";
    } else {
      // Encoder is rotating CW so increment
      counter --;
      currentDir ="CCW";
    }

    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print("  |  Counter: ");
    Serial.print(counter);
    
    // Is the distance that has been traveled
    distance = ((2*pi*R)/N) * counter / 100;
    Serial.print("  |  Distance: ");
    Serial.print(distance);
    Serial.print(" m");

    // Prints the time passed
    Serial.print("  |  Time: ");
    Serial.print(currTime);
    Serial.println(" ms");

    // Is the speed of the car
    //currSpeed = distance / currTime; // TODO: take the difference
    //Serial.print("  |  Speed: ");
    //Serial.print(currSpeed);
    //Serial.println(" m/ms");
  }

  // sets the last state to the current state
  lastStateCLK = currentStateCLK;

  // a little delay
  delay(1);
}
