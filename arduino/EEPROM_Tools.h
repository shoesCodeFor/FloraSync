#include <EEPROM.h>
// Our memory map uses 303-720 inclusive for usable memory area (418)

/* In this function you can initialize the entire span of memory with on string */
void initBot(char [418] stringIn){
    int stop = 720;
    int value = 0;
    for(int address = 303; address < 720; address++){
        value = int(stringIn[address]);
        EEPROM.write(address, value);
    }    
}

void readEEPROM(int startingBlock, int chunkSize){
        char oneChar;
        for(int i = startingBlock, i < chunkSize, i++;){
           oneChar = EEPROM.read(i);
            
       }
}
char *arrayFromEEPROM(int startingBlock, int chunkSize, char buf[])
	{
    int placeKeeper = 0;
	char oneChar;
        for(int i = startingBlock; i < chunkSize; i++){
            oneChar = EEPROM.read(i);
            buf[placeKeeper] = oneChar;
        }
	return buf;
	}