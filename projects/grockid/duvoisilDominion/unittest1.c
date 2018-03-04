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

}
void set_deck(struct gameState *g){
		int p = 0;
		g->deck[p][0] = estate;
		g->deck[p][1] = duchy;
		g->deck[p][2] = province;
		g->deck[p][3] = smithy;
		g->deck[p][4] = smithy;


}

void set_hand(struct gameState *g){

		int p = 0;

		g->hand[p][0] = estate;
		g->hand[p][1] = duchy;
		g->hand[p][2] = province;
		g->hand[p][3] = smithy;
		g->hand[p][4] = smithy;


}


void acheck(score, actual){
	if(actual == score){
		printf("TEST PASSED\n");
	}else{
		
		printf("TEST FAILED\n");
	}
}

void testGainedCard() {


	srand(time(NULL));
	struct gameState g;
	int players = 2;
	int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int i;
	int success = 0;
	
	initializeGame(players, cards, 1000, &g); // initialize a new game
	
	g.handCount[0]= 5;
	g.deckCount[0] = 5;
	g.discardCount[0] = 5;
	set_deck(&g);
	set_discard(&g);
	set_hand(&g);

	printf("------------------TESTING GAINED CARDS------------------\n\n");


	printf("\nTesting with empty supply pile\n");
	g.supplyCount[1] = 0;
	success = gainCard(1, &g, 0, 0);
	acheck(success, -1);

	g.supplyCount[1] = 10;

	printf("\nTesting with non empty supply pile\n");	//testing mine at pos 4



	printf("\n\nTesting sending to discard\n");
	success = gainCard(mine, &g, 0, 0);
	success = 0;
	for(i = 0; i < g.discardCount[0]; i++){
		if(g.discard[0][i] == mine){
			success = 1;
			break;

		}
	}
	if(g.discardCount[0] != 6){
		success = 2;
	}
	acheck(success, 1);




	printf("\nTesting sending to deck\n");
	success = gainCard(mine, &g, 1, 0);
	success = 0;
	for(i = 0; i < g.deckCount[0]; i++){
		if(g.deck[0][i] == mine){
			success = 1;
			break;

		}
	}
	if(g.deckCount[0] !=6){
		success = 2;
	}
	acheck(success, 1);


	printf("\nTesting sending to hand\n");
	success = gainCard(mine, &g, 2, 0);
	success = 0;
	for(i = 0; i < g.handCount[0]; i++){
		if(g.hand[0][i] == mine){
			success = 1;
			break;

		}
	}
	if(g.handCount[0] !=6){
		success = 2;
	}
	acheck(success, 1);
}
int main(int argc, char *argv[])
{
	testGainedCard();
	return 0;
}



