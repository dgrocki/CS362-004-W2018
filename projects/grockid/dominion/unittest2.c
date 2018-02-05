#include<stdio.h>
#include<stdlib.h>
#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include<time.h>



void testFullDeckCount() {


	srand(time(NULL));
	struct gameState g, pre_g;
	int players = 2;
	int cards[10] = {adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall};
	int p,i;
	int count1; 
	int count2;
	int count3;
	int count0;
	
	//	struct BSTree *tree = buildBSTTree();

	//    struct data myData1;
	//	struct data myData2;
	//	struct data myData3;
	//	struct data myData4;
	//	struct data myData5;



	printf("------------------TESTING FULL DECK COUNT------------------\n\n");



	for (p = 0; p < players; p++)
	{
		initializeGame(players, cards, 1000, &g); // initialize a new game
		g.deckCount[p] = 3;
		g.handCount[p] = 3;
		g.discardCount[p] = 3;





		for(i = 0; i < 3; i++){
			g.hand[p][i] = cards[i%3]; // set cards to first 3 cards of deck
			g.deck[p][i] = cards[(i+1)%3];
			g.discard[p][i] = cards[(i+2)%3];
		}


		memcpy(&pre_g, &g, sizeof(struct gameState));

		 
		
		count0 = fullDeckCount(p,cards[0], &g);

		 count1 = fullDeckCount(p,cards[1], &g);
		 count2 = fullDeckCount(p,cards[2], &g);
		 count3 = fullDeckCount(p,cards[3], &g);


		printf("\nTesting card 1 counted correctly\n");
		assert(count1 == 3);
		printf("TEST PASSED\n");
		printf("\nTesting card 2 counted correctly\n");
		assert(count0 == 3);
		printf("TEST PASSED\n");
		printf("\nTesting card 3 counted correctly\n");
		assert(count2 == 3);
		printf("TEST PASSED\n");
		printf("\nTesting card 4 counted correctly\n");
		assert(count3 == 0);
		printf("TEST PASSED\n");
	}
}
int main(int argc, char *argv[])
{
	testFullDeckCount();
	return 0;
}



