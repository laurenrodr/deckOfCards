# Author: Lauren Rodriguez
# ID: 5694821
# COP4338 U03

CC = gcc
FILES = mainDeck.c outputDeck.c 
OUT_EXE = runDeck #executable

#compiles mainDeck.c and outputDeck.c
build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)

clean: 
	rm -f *.o core

#calls clean target then build target
rebuild: clean build
	
