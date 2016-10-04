#include <EEPROM.h>

//This will count the 100,000 Write to memory allowed
// 721,722,723,724,725 Maximum of 99,999
//ex. - 11,322
int tenBase1, tenBase2, tenBase3, tenBase4, tenBase5 = 0;


int RES_CONTING_BLOCK=721
int counter = 0;    
int counter1, counter2, counter3, counter4, counter5 = 0;

/* Our memory map uses 303-720 inclusive for usable memory area (418)
  NOTE: on 512k memory we can do 1-418  
/*
/* In this function you can initialize the entire span of memory with one string */
void initBot(char [418] stringIn){
    int stop = 720;
    int value = 0;
    for(int address = 303; address < 720; address++){
        value = int(stringIn[address]);
        EEPROM.write(address, value);
    }
    
   memWriteProtect();
    
}




// This will return an entire char array
char *arrayFromEEPROM(int startingBlock, int chunkSize)
	{
    char buf[chunkSize];
    int placeKeeper = 0;
	char oneChar;
        for(int i = startingBlock; i < chunkSize; i++){
            oneChar = EEPROM.read(i);
            buf[placeKeeper] = oneChar;
            placeKeeper++;
        }
	return buf;
} // End of arrayFromEEPROM



// This funtion is meant to be used similarily to the one above.  This method returns a single character so call a for loop in you main program
char readEEPROM(int memoryBlock){
        char oneChar;
        oneChar = EEPROM.read(memoryBlock);
        return oneChar;    
}

void memWriteProtect(){
    //This counter funtion will read and store the amount of times we've written to the EEPROM
    
    
    // Ten Base 1 = 1-9
    tenBase1 = EEPROM.read(729);
    if(tenBase1 == 9){
        tenBase1=0;
        counter1 = 10;
    }
    else{
        tenBase1++;
    }
    
    // Ten Base 2 = 10-90
    tenBase2 = EEPROM.read(728);//10
    if(tenBase2==9 && counter1==10){
        tenBase2==0;
        counter2=100;
    }
    else if(counter1==10){
        tenBase2++;
    }
    
    // Ten Base 3 = 100-900
    tenBase3 = EEPROM.read(727);//100
    if(tenBase3 ==9 && counter2==100){
        tenBase3=0;
        counter3=1000;
    }
    else if(counter2==100){
        tenBase3++;
    }
    
    // Ten Base 4 = 1000-9000
    tenBase4 = EEPROM.read(726);//1000
    if(tenBase4 ==9 && counter3==1000){
        tenBase4=0;
        counter4=10000;
    }
    else if(counter3==1000){
        tenBase4++;
    }
    
    // Ten Base 5 = 10000-90000
    tenBase5 = EEPROM.read(725);//10000
    if(tenBase5 ==9 && counter4==10000){
        tenBase5=0;
        counter5=100000;
    }
    else if(counter4==10000){
        tenBase5++;
        
    }
    
    counter = tenBase1 + (tenBase2*10) + (tenBase3*100) + (tenBase4*1000) + (tenBase5*10000);
    if(counter5==100000){
        counter=99999;// We're maxed out
        Serial.println("DANGER: MEMORY LOSS RISK DETECTED.  You can only safely write 100,000 time to EEPROM");
    }
    if(counter==99999){
        EEPROM.write(729, 9);
        EEPROM.write(728, 9);
        EEPROM.write(727, 9);
        EEPROM.write(726, 9);
        EEPROM.write(725, 9);
    }
    else{
        EEPROM.write(729, tenBase1);
        EEPROM.write(728, tenBase2);
        EEPROM.write(727, tenBase3);
        EEPROM.write(726, tenBase4);
        EEPROM.write(725, tenBase5);
    }
    Serial.println("Written to memory");
    Serial.println(counter);
    Serial.println("times");
    
}