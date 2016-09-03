/*
  fillBot v 3.0 -Headless 7/27/2016
  By Schuyler Ankele
  
  Concept: with a fillBot you can fill any container using a simple 
  wire based water level sensor or this one https://www.adafruit.com/product/464
  if you want amazing results. NOTE:  You must import their library.
  
  We use a relay to open and close our water solenoid or pump.  
  
  Water Sensor over Cat5 - 
  White Green VCC - D4
  Brown GND - GND
  Blue AnalogOut - A0                        
  Timing:
  typical 5 gal was 1 minute - 60000 mils
  ALTER ABOVE TO SET TIMING VARIABLES
*/


#define RELAY_PIN 6
// Serial is the date (of build) followed by type of Arduino/Atmel board if you're wanting to use our style database
#define SERIAL_NUMBER Year-Month-Day-ArduinoMake 



// We'll use this to run the loop 
#define NUM_OF_SENSORS = 1 //On this one it is Water
// This is a digital pin we'll use to turn the sensor on intermittently
#define VCC_PIN  4
#define ANALOG_READ A5 

/* Timing variables */
long previousMillis = 0;
unsigned long currentMillis = 0;
long interval = 10;  //10-default READING INTERVAL
long count = 0;
long runningTotal = 0;
//long onTime = 660000;

/* we're using floats for the average  
 *  
 calculation(error on comparison of float to int)*/
float sensor1 = 0;
float threshold = 450; 

int relayInterval = 6600000; // 3 minutes
//600 is soaked (limit)
// 200 is min
void setup(){
  Serial.begin(115200);
  Serial.println("Serial Working.  Lets setup some sensors.");
      
  pinMode(VCC_PIN, OUTPUT);
  pinMode(ANALOG_READ, INPUT);
  pinMode(RELAY_PIN,OUTPUT);
  
}


void loop(){
  digitalWrite(RELAY_PIN,HIGH);
  
  readSensor();
  if(sensor1 < threshold){
    Serial.println("We're opening up the circuit.");
    
  for(int i; i < relayInterval; i++){
    Serial.print(i);
    Serial.print(".");  
    digitalWrite(RELAY_PIN, LOW);
    if(i%5==0){
      digitalWrite(VCC_PIN, HIGH);
      sensor1 = analogRead(ANALOG_READ);
      sensor1 = (sensor1 * (-.75)) + 1000;
      Serial.println(sensor1);   
    }  
    if(sensor1 > threshold){
      break;
    } 
    
  }// End of for loop for read with relay on
  
} // end of main loop
}
void readSensor(){
      digitalWrite(VCC_PIN, HIGH);
      delay(500);
      for(int i=0; i < interval; i++){
        runningTotal += analogRead(ANALOG_READ);
        count++;
        Serial.println(i);      
}
      sensor1 = (runningTotal/count);
      sensor1 = (sensor1 * (-.75)) + 1000;
      
      Serial.println(sensor1);
      digitalWrite(VCC_PIN, LOW);
      runningTotal =0;
      count=0;
      

}
void turnOnRelay(int onTime){
  // This relay like other requires digitalWrite HIGH to keep it shut off
  // Crazy right? So we have done this in setup
  digitalWrite(RELAY_PIN, LOW);
  delay(onTime);
  digitalWrite(RELAY_PIN, HIGH);      
}


