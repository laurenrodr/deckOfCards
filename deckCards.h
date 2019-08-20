//Author: Lauren Rodriguez
// deckCards.h -- header file

#include <stdio.h>
#include <stdlib.h> //atoi: change argument char to int
#include <time.h> //srand; seeding random #s

#define NO_ERROR 0
#define MAX_CARDS 52 //numer of cards in deck
#define NUM_SUITS 4 
#define NUM_FACES 13
#define NUM_ARGS 3 //number of necessary arguements
#define SPACE 12 //space after 13th card

//enum for argument validation
enum Boolean { FALSE = 0, TRUE = 1 };

//function prototypes
void createDeck(int cDeck[], int cardNum);
void printCard(int card);
void printDeck(int cDeck[], int cardNum);
void initializeAll(int handSize, int totalHands);
void argValidation(int argc, char *argv[]);
void shuffleDeck(int cDeck[]);
void createHand(int cDeck[], int cardNum, int handSize, int totalHands, 
	int row, int col, int cHand[totalHands][handSize]);
void printHand(int handSize, int totalHands, int row, int col, 
	int cHand[totalHands][handSize]);
