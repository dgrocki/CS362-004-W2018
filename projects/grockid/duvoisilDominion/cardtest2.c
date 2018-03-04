#include<stdio.h>
#include<stdlib.h>
#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include<time.h>

//adventurer
//
void set_discard(struct gameState *g){
		int p = 0;

		g->discard[p][0] = estate;
		g->discard[p][1] = duchy;
		g->discard[p][2] = copper;
		g->discard[p][3] = copper;
		g->discard[p][4] = copper;
}
void set_deck(struct gameState *g){
		int p = 0;
		g->deck[p][0] = estate;
		g->deck[p][1] = duchy;
		g->deck[p][2] = copper;
		g->deck[p][3] = copper;
		g->deck[p][4] = copper;


}

void set_hand(struct gameState *g){

		int p = 0;

		g->hand[p][0] = copper;
		g->hand[p][1] = smithy;
		g->hand[p][2] = copper;
		g->hand[p][3] = adventurer;

}


void acheck(score, actual){
	if(actual == score){
		printf("TEST PASSED\n");
	}else{
		
		printf("TEST FAILED\n");
	}
}

void testAdventurer() {


	srand(time(NULL));
	struct gameState g;
	int players = 2;
	int cards[10] = {adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall};
	int p = 0;
	int bonus = 0;	
	int success = 0;
	int inital_hand = 5;


	printf("\n------------------TESTING ADVENTURER------------------\n\n");
	initializeGame(players, cards, 1000, &g); // initialize a new game

	g.handCount[p] = inital_hand;
	g.deckCount[p] = 5;
	
	set_hand(&g);
	set_deck(&g);
	//test if stops after finding 2 treasures
	//test if shuffles discard if decke empty
	//test if discarda all drawn cards
	


	


	


	success = cardEffect(adventurer, 0,0,0, &g,3,&bonus);


	printf("\n\nTesting Cards in Deck If Adventurer Ran Successfully\n");
	acheck(success, 0);

		
	printf("\n\nTesting If Adventurer Found 2 treasures\n");
	acheck(success, inital_hand + 1);	//add 2 treasures to hand and then discard adventure card
	


	
	g.discardCount[p] = 5;
	set_discard(&g);
	
	success = cardEffect(2, 0,0,0, &g,1,&bonus);
	
	printf("\n\nTesting Cards in Discard If Adventurer Ran Successfully\n");
	acheck(success, 0);

	
	


	//test number drawn
	//test discarded
	//


//		memset(&g, 23, sizeof(struct gameState));   // clear the game state


}
int main(int argc, char *argv[])
{
	testAdventurer();
	return 0;
}



