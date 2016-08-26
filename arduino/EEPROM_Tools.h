#include <EEPROM.h>
// Our memory map uses 303-720 inclusive for usable memory area (418)

/* In this function you can initialize the entire span of memory with on string */
void initBot(char [418] stringIn){
    int value = 0;
    for(int i = 0; i < 418; i++){
        value = int(stringIn[i]);
        EEPROM.write(i, value);
    }    
}

void readEEPROM(int startingBlock, int chunkSize){
       for(int i = startingBlock, i < chunkSize, i++;){
           EEPROM.read
       }
}
