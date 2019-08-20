/*=============================================================================  
|   Source code:  outputDeck.c
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

/* function: argValidation
 *
 * runs only if run is true; run is true if correct number of arguments are 
 * inputted at command-line, otherwise error is outputted; when run is true, 
 * command-line input is assigned to handSize (cards per hand) and totalHands
 * (number of players); calls initializeAll function
 */
void argValidation(int argc, char *argv[])
{
    int run = FALSE;
    if(argc == NUM_ARGS)
    {
	run = TRUE;
    } 

    
    if(run == TRUE)
    {   
        int argCount;
        int handSize;
        int totalHands; 
        for(argCount = 1; argCount < argc; argCount++)
        {   
            if(argCount == 1)
            {   
                handSize = atoi(argv[argCount]);
            }
            else if(argCount == 2)
            {   
                totalHands = atoi(argv[argCount]);
            }
        }
        
	if( handSize * totalHands <= MAX_CARDS)
        {
            
            initializeAll(handSize, totalHands);
        }
        else
        {   
            puts("Not valid command-line input. Total cards necessary exceeds"
                        " size of deck.");
        }
    }
    else
    {   
        puts("Incorrect number of arguments. File name, number of cards per" 
		" hand, and number of hands are necessary.");
    }

}

/* function: printCard
 * 
 * initializes const char pointer array for suit and const char pointer array 
 * for face; creates individual card based on input from function where 
 * printCard was called (contents at particular deck index); prints card with 
 * their face and suit; C = Clubs, D = Diamonds, H = Hearts, S = Spades
 * 
 */
void printCard(int card)
{
    const char *suit[NUM_SUITS] = { "C", "D", "H", "S" };
    const char *face[NUM_FACES] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "T",
                                     "J", "Q", "K" };

    printf("[%c-%c]  ", *face[ card % NUM_FACES ], *suit[ card / NUM_FACES ]);
}


/* function: printDeck
 * 
 * iterate though the deck array of size (MAX_CARDS) and call printCard()
 * function; newline after after 13th card  
 */
void printDeck(int cDeck[], int cardNum)
{
    for(cardNum = 0; cardNum < MAX_CARDS; cardNum++)
    {
        printCard(cDeck[cardNum]);
	
	//prints 13 cards per line
	if( (cardNum % NUM_FACES) == SPACE)
        {
            puts("");
        }       
    }
}

/* function: printHand
 * 
 *  iterate through hand 2D array; to print players number (row value)
 *  and print card by calling printCard() function
 *	   
 */
void printHand(int handSize, int totalHands, int row, int col, 
	int cHand[totalHands][handSize])
{
    for(row = 0; row < totalHands; row++)
    {
        printf("\nPlayer %d] - ", (row + 1));

        for(col = 0; col < handSize; col++)
        {
            printCard(cHand[row][col]);
        }
    }
}
