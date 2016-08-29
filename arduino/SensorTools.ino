float aSensorRead(int pin1, char[2]readPin, int interval){
    float reading = 0;
    float sensorReading = 0;
    float runningTotal;
    float count = 0;
    
    /* Sub-routine for sensor read
       We will try and have a 10 read minimum as default
    */
    if(interval < 10){
        interval = 10;
    }
    
    /* NOTE: We only power the pin when taking a reading to save power and shut off after for loop */
    digitalWrite(pin1, HIGH);  
    delay(500);
    for(int i=0; i < interval; i++){
      runningTotal += analogRead(readPin);
      count++;
    }
    /*  Turn off the sensor */
    digitalWrite(pin1, LOW);
    
    /* Print to console */
    Serial.println("We got ");
    Serial.println(count);
    Serial.println("readings");
    
    /* Create an average Total_of_All_Readings/Num_Of_Readings */
    reading = runningTotal/count;
    
    /*  We print out our reading to help us test */
    Serial.println("Sensor Status is:");
    Serial.println(reading);
 

    return reading;
}

<<<<<<< HEAD
/* This is to open our relay */
void openRelay(int interval, int pin1){
    if(interval = null){
        interval = 10000 //10 Seconds   
    }
    digitalWrite(pin1, LOW);
    Serial.print("Opening the relay");
    for(int i = 0; i < interval; i++){
        Serial.print(".");   
    }
    delay(inter
}

=======
float quickRead(int pin1, char[2] readPin, float threshold){
    float aReading = 0;
    digitalWrite(pin1, HIGH);
    delay(500);
    aReading = analogRead(readPin);
    digitalWrite(pin1,LOW);
    return aReading;    
    
}

void openRelay(int relayPin, int threshold){
    digitalWrite(realyPin, LOW);
    Serial.print("Opening Relay");
    for(int i=0; i < threshold; i++){
        Serial.print(".");   
    }
    digitalWrite(relayPin, HIGH);
}



>>>>>>> refs/remotes/origin/master
