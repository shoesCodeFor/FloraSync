/*  Simple Watering Controller - 
    Written By - Schuyler Ankele 
    This code creates a Watering Controller for the Florasync managment system.

    This design is for a watering controller with 6 sensors.  Future designs will incorperate the RF24 radio to
    communicate with the FloraSync hub.

    

    Wiring sensors - Orange is ground and right pin on sensor
    
*/
/* Configure Our Soil Sensor - this is a little trickier
  We will define two pins - the power will be enabled intermittently
  only when readings are taken to preven oxidation on our sensor 
  One Analog PIn to read data and one Digital Pin to power the sensor */

/* Soil Sensor 1  */  
#define SOIL_VCC_1  2
#define SOIL_PIN_1  A0

/* Soil Sensor 2  */  
#define SOIL_VCC_2  3
#define SOIL_PIN_2  A1

/* Soil Sensor 3  */  
#define SOIL_VCC_3  4
#define SOIL_PIN_3  A2

/* Soil Sensor 4  */  
#define SOIL_VCC_4  5
#define SOIL_PIN_4  A3


/* This pin will open our relay to turn on a water pump. */
#define HOT_LEAD 11

/* Timing variables */
long previousMillis = 0;
unsigned long currentMillis = 0;
long interval = 1000; // READING INTERVAL


/*  These are variables we will use to track soil measurments*/
long soilStatus = 0;
long runningTotal = 0;
int count= 0;

long soilStatus1 = 0;
long soilStatus2 = 0;
long soilStatus3 = 0;
long soilStatus4 = 0;

long soilAvg = 0;
long targetMoisture = 350;
void setup() {
  Serial.begin(115200);
  /* Setup Sensor 1*/
  pinMode(SOIL_VCC_1, OUTPUT);
  pinMode(SOIL_PIN_1, INPUT);
  /* Setup Sensor 2 */
  pinMode(SOIL_VCC_2, OUTPUT);
  pinMode(SOIL_PIN_2, INPUT);
  /* Setup Sensor 3 */
  pinMode(SOIL_VCC_3, OUTPUT);
  pinMode(SOIL_PIN_3, INPUT);
  /* Setup Sensor 4 */
  pinMode(SOIL_VCC_4, OUTPUT);
  pinMode(SOIL_PIN_4, INPUT);
  
  /* Setup Relay */
  pinMode(HOT_LEAD, OUTPUT);

}


void loop() {

  
    /*  Here we will test the soil before watering - 
    
    /* Open for tips about accuracy on this.  
    Arduino.cc says Analog reads are up to 10,000 times per second.
    I think thins method only gets an average of 1,000 which is pretty 
    good for our purpose */
    /* Range Notes */
    /* Zero water or totally dry is marked at 244
       Full water or submerged is marked at 700-800 depending on depth*/
    /* Damp is 300-400 - 350 seems ideal */
    /* Heavy water is 450-500 */
    /* Soaked is 550 and above */

    /* NOTE:  Depth of sensor greatly effects reading */
    /* Sub-routine for sensor 1*/
    /* NOTE: We only power the pin when taking a reading to save power and shut off after for loop */
    digitalWrite(HOT_LEAD, HIGH);
    digitalWrite(SOIL_VCC_1, HIGH);  
    delay(1000);
    /* Sub-routine for sensor 1*/
    for(int i=0; i < interval; i++){
      runningTotal += analogRead(SOIL_PIN_1);
      count++;
    }
    /* Create an average Total_of_All_Readings/Num_Of_Readings */
    digitalWrite(SOIL_VCC_1, LOW);
    Serial.println("We got ");
    Serial.println(count);
    Serial.println("readings");
    soilStatus = runningTotal/count;
    soilStatus1 = soilStatus;
    soilStatus1 = (soilStatus1  * -0.75) + 1000;
    
    /*  We print out our reading to help us test */
    Serial.println("Soil Status 1 is:");
    Serial.println(soilStatus1);
   
    /* Reset our counting variables */
    runningTotal=0;
    count=0;
    soilStatus = 0; 

    /* Sub-routine for sensor 2*/
    digitalWrite(SOIL_VCC_2, HIGH);  
    delay(1000);
    for(int i=0; i < interval; i++){
      runningTotal += analogRead(SOIL_PIN_2);
      count++;
    }
    /* Create an average Total_of_All_Readings/Num_Of_Readings */
    digitalWrite(SOIL_VCC_2, LOW);
    Serial.println("We got ");
    Serial.println(count);
    Serial.println("readings");
    soilStatus = runningTotal/count;
    soilStatus2 = soilStatus;
    soilStatus2 = (soilStatus2  * -0.75) + 1000;
    
    /*  We print out our reading to help us test */
    Serial.println("Soil Status 2 is:");
    Serial.println(soilStatus2);
  /* Reset our counting variables */
    runningTotal=0;
    count=0;
    soilStatus = 0;

    /* Sub-routine for sensor 3*/
    digitalWrite(SOIL_VCC_3, HIGH);  
    delay(1000);
    
    for(int i=0; i < interval; i++){
      runningTotal += analogRead(SOIL_PIN_3);
      count++;
    }
    /* Create an average Total_of_All_Readings/Num_Of_Readings */
    digitalWrite(SOIL_VCC_3, LOW);
    Serial.println("We got ");
    Serial.println(count);
    Serial.println("readings");
    soilStatus = runningTotal/count;
    soilStatus3 = soilStatus;
    soilStatus3 = (soilStatus3  * -0.75) + 1000;
    
    /*  We print out our reading to help us test */
    Serial.println("Soil Status 3 is:");
    Serial.println(soilStatus3);
  /* Reset our counting variables */
    runningTotal=0;
    count=0;
    soilStatus = 0;

    /* Sub-routine for sensor 4 */
    digitalWrite(SOIL_VCC_4, HIGH);  
    delay(1000);
    for(int i=0; i < interval; i++){
      runningTotal += analogRead(SOIL_PIN_4);
      count++;
    }
    /* Create an average Total_of_All_Readings/Num_Of_Readings */
    digitalWrite(SOIL_VCC_4, LOW);
    Serial.println("We got ");
    Serial.println(count);
    Serial.println("readings");
    soilStatus = runningTotal/count;
    soilStatus4 = soilStatus;
    soilStatus4 = (soilStatus4  * -0.75) + 1000;
    
    /*  We print out our reading to help us test */
    Serial.println("Soil Status 4 is:");
    Serial.println(soilStatus4);
  /* Reset our counting variables */
    runningTotal=0;
    count=0;
    soilStatus = 0;

  /* This will create an average - then we will invert it to create a number between 0-1000 for our 'soilAvg' */    
  soilAvg = (soilStatus1 + soilStatus2 + soilStatus3 + soilStatus4)/ 4;

  /* NOTE if using a soil sensor that produces a number like 0 for dry and 1000 for wet you can comment the conversion out.  
     Our purpose for the conversion is to create a low number for fry and high number for wet.  */
  // soilAvg = (soilAvg * -0.75) + 1000;
  
  /*  If it's dry it dies! So water it....but not too much
  Lets try 1 second and recheck with our soil probe on the loop */
  if(soilAvg < targetMoisture){
    digitalWrite(HOT_LEAD, LOW);
    delay(10000);
    digitalWrite(HOT_LEAD, HIGH);
    Serial.println("Watering.............");
  }
  /*  The else statment ensures our relay is off. */
  else{
     digitalWrite(HOT_LEAD, HIGH); 
    Serial.print("We're all good right now!"); 
  }
Serial.println("Soil Average is:");
Serial.println(soilAvg);
delay(10000);
}
