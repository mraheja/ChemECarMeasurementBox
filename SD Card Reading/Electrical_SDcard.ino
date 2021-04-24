
#include <SD.h>
File testRuns;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
     pinMode(10, OUTPUT);
 
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  String filename ="Run";
  int filenumber = 1;
  filename = filename + String(filenumber);
  while (SD.exists(filename)) {
    filenumber = filenumber +1;
    filename = "Run" + String(filenumber);
  }
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  testRuns = SD.open(filename, FILE_WRITE);
 
}

void loop() {
  // put your main code here, to run repeatedly:

}
