#include<stdio.h>
#include<stdlib.h>
#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include<time.h>


void set_discard(struct gameState *g){
		int p = 0;

		g->discard[p][0] = estate;
		g->discard[p][1] = duchy;
		g->discard[p][2] = province;
		g->discard[p][3] = smithy;
		g->discard[p][4] = smithy;
		g->discard[p][5] = smithy;
		g->discard[p][6] = smithy;
		g->discard[p][7] = smithy;
		g->discard[p][8] = smithy;
		g->discard[p][9] = smithy;
		g->discard[p][10] = smithy;
		g->discard[p][11] = smithy;

}
void set_deck(struct gameState *g){
		int p = 0;
		g->deck[p][0] = estate;
		g->deck[p][1] = duchy;
		g->deck[p][2] = province;
		g->deck[p][3] = smithy;
		g->deck[p][4] = smithy;
		g->deck[p][5] = smithy;
		g->deck[p][6] = smithy;
		g->deck[p][7] = smithy;
		g->deck[p][8] = smithy;
		g->deck[p][9] = smithy;
		g->deck[p][10] = smithy;
		g->deck[p][11] = smithy;


}

void set_hand(struct gameState *g){

		int p = 0;

		g->hand[p][0] = estate;
		g->hand[p][1] = smithy;
		g->hand[p][2] = duchy;


}


void acheck(score, actual){
	if(actual == score){
		printf("TEST PASSED\n");
	}else{
		
		printf("TEST FAILED\n");
	}
}

void testSmithy() {


	srand(time(NULL));
	struct gameState g;
	int players = 2;
	int cards[10] = {adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall};
	int p = 0;
	int bonus = 0;	
	int success = 0;
	int inital_hand = 3;


	initializeGame(players, cards, 1000, &g); // initialize a new game

	
	printf("\n------------------TESTING SMITHY------------------\n\n");
	
	
	g.handCount[p] = inital_hand;
	set_hand(&g);

	success = cardEffect(smithy, 0,0,0, &g,1,&bonus);
	printf("\n\nTesting If Smithy Ran Successfully\n");
	acheck(success, 0);

		
	printf("\n\nTesting If Smithy Drew right Number of cards\n");
	acheck(success, inital_hand + 2);	//add 3 to hand and then discard 1
	
	
	


	//test number drawn
	//test discarded
	//


//		memset(&g, 23, sizeof(struct gameState));   // clear the game state


}
int main(int argc, char *argv[])
{
	testSmithy();
	return 0;
}



