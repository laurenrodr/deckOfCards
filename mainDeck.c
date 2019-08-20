/*=============================================================================  
|   Source code:  mainDeck.c
|        Author:  Lauren Rodriguez  
|    Assignment:  Program #3 -- DeckOfCards
|  
|            Course:  COP 4338 -- Programming III 
|           Section:  U03  
|        Instructor:  William Feild  
|        Due Date:  10/11/18, at the beginning of class
|  
|        Language:  C
|  
|  Description:  This programs creates an initial deck of cards (52 cards, no
|		 jokers), with 4 Suits (Clubs, Diamond, Hearts, and Spades) 
|		 and 13 faces (Ace, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, 
|		 King). The deck is printed, shuffled, and dispersed amongst a number
|		 of players.   
|                  
|        Input:  From the command line, the user is required to input number 
|		 of cards each player will receive and the number of players 
|		 (in that order).
|		 i.e. ./runDeck 7 5 (to print 5 hands w/ 7 cards each) 
|  
|       Output:  The original deck is output in order (by face and suit). Then 
|		 a randomly shuffled version of the deck is printed. Then the 
|		 player number is printed with the cards in its hand.
|  
|     Process:  1. The program takes the input from the command-line
|		2. The input is validated to make sure it meets the required
|			number of arguments necessary
|		3. The original deck of 52 cards in created. and printed.
|		4. The deck is randomly shuffled and then printed.
|		5. A 2D array is created for the hands with the row being the 
|			player number and each of the columns being a card 
|			assigned to the player (starting from the top of the 
|			deck)
|		6. The player number is then printed, along with each of the 
|			player's cards
|  
|   Required Features Not Included:  None 
|  
|   Known Bugs:  No bugs known 
|  *===========================================================================*/
#include "deckCards.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));    
    argValidation(argc, argv);

    return NO_ERROR;   
}

/* function: initializeAll
 * 
 * creates deck and hand arrays; declares other values needed as paramters 
 * for functions; calls all other program functions and prints deck/hands
 * 
 */
void initializeAll(int handSize, int totalHands)
{
    int cDeck[MAX_CARDS];		 //card deck array
    int cHand[totalHands][handSize]; 	//card hands array
    int cardNum; 			//loop counter
    int totalCards = totalHands * handSize;
    int row;				//loop counter (hand array)
    int col;				//loop counter (hand array)
    
    puts("\nOriginal Ordered Deck:");
    createDeck(cDeck, cardNum);
    printDeck(cDeck, cardNum);

    puts("\nRandom Shuffled Deck:");
    shuffleDeck(cDeck);
    printDeck(cDeck, cardNum);

    printf("\n%s", "Player Hands: (dealt from top/front of deck)");
    createHand(cDeck, cardNum, handSize, totalHands, row, col, cHand);
    printHand(handSize, totalHands, row, col, cHand);   
    puts(""); //space after every hand    
}

/* function: createDeck
 * 
 * creates original deck function using a for loop; loops 51 times and assigns 
 * each element (card) of the deck a number
 *
 */
void createDeck(int cDeck[], int cardNum)
{
    for(cardNum = 0; cardNum < MAX_CARDS; cardNum++)
    {
	   cDeck[cardNum] = cardNum;
    }
}

/* function: shuffleDeck
 *
 * shuffles entire original card deck using Fisher-Yates shuffle algorithm
 * https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
 * http://www.programming-algorithms.net/article/43676/Fisher-Yates-shuffle
 *
 */
void shuffleDeck(int cDeck[])
{
    int cardLoc; //card location in array
    int newLoc; //new card location
    int tempVar;

    for(cardLoc = 0; cardLoc < MAX_CARDS; cardLoc++)
    {
    	newLoc = rand() % MAX_CARDS;
    	tempVar = cDeck[cardLoc];
    	cDeck[cardLoc] = cDeck[newLoc];
    	cDeck[newLoc] = tempVar;	
    }

}

/* function: createHand
 *
 * initializes cardNum for deck array iteration values; for loop for row and 
 * column in hand 2D array to initlaize deck array to row and column in hand 
 * array; increments cardNum after every assignment
 *
 */
void createHand(int cDeck[], int cardNum, int handSize, int totalHands, 
	int row, int col, int cHand[totalHands][handSize])
{
    cardNum = 0;
    for(row = 0; row < totalHands; row++)
    {
    	for(col = 0; col < handSize; col++)
    	{
    	    cHand[row][col] = cDeck[cardNum];
      	    cardNum++;
        }
    }
}



