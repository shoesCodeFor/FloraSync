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


// This will return an entire char array
char *arrayFromEEPROM(int startingBlock, int chunkSize, char buf[])
	{
    int placeKeeper = 0;
	char oneChar;
        for(int i = startingBlock; i < chunkSize; i++){
            oneChar = EEPROM.read(i);
            buf[placeKeeper] = oneChar;
        }
	return buf;
} // End of arrayFromEEPROM



// This funtion is meant to be used similarily to the one above.  This method returns a single character so call a for loop in you main program
char readEEPROM(int memoryBlock){
        char oneChar;
        oneChar = EEPROM.read(memoryBlock);
        return oneChar;    
}