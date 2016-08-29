#include <EEPROM.h>
// Our memory map uses 303-720 inclusive for usable memory area (418)

void setup(){
    Serial.begin(115200);
    
    initBot("201608200001011000140000800");
}
void loop(){
  
}
/* In this function you can initialize the entire span of memory with on string */
void initBot(char * stringIn){
    
    int value = 0;
    int stringSpot = 0;
    for(int address = 303; address < 720; address++){
        value = stringIn[stringSpot];
        EEPROM.write(address, value);
        stringSpot++;
    }    
}


