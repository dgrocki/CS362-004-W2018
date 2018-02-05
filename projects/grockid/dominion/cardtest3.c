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

		g->hand[p][0] = village;
		g->hand[p][1] = smithy;
		g->hand[p][2] = copper;
		g->hand[p][3] = estate;

}


void acheck(score, actual){
	if(actual == score){
		printf("TEST PASSED\n");
	}else{
		
		printf("TEST FAILED\n");
	}
}

void testVillage() {


	srand(time(NULL));
	struct gameState g, pre_g;
	int players = 2;
	int cards[10] = {adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall};
	int p = 0;
	int i;
	int bonus = 0;	
	int success = 0;
	int inital_hand = 5;

	printf("\n------------------TESTING VILLAGE------------------\n\n");

	initializeGame(players, cards, 1000, &g); // initialize a new game
	initializeGame(players, cards, 1000, &pre_g); // initialize a new game



	g.handCount[p] = inital_hand;
	g.deckCount[p] = 5;
	g.discardCount[p] = 5;

	set_hand(&g);
	set_deck(&g);

	pre_g.handCount[p] = inital_hand;
	pre_g.deckCount[p] = 5;
	pre_g.discardCount[p] = 5;
	
	set_hand(&pre_g);
	set_deck(&pre_g);





	//test add 1 card
	//test add 2 actions
	//test if card in discard, discard + 1
		


	


	success = cardEffect(village, 0,0,0, &g,0,&bonus);


	printf("\n\nTesting Village Ran Successfully\n");
	acheck(success, 0);

	printf("\nTesting adding more actions\n");


	acheck(pre_g.numActions, g.numActions-2);	//-2 since add 2 actions


		
	printf("\n\nTesting If Village Added 1 card\n");
	success = 0;
	for(i = 0; i < inital_hand; i++){
		if(g.deck[p][i] == village){		//if village no longer in hand
			success = -1;
			break;
		}
	}
	if(pre_g.handCount[p] != g.handCount[p]){	//and we didn' t fail to draw
		success = -1;
	}
	acheck(success, 0);	//add 2 treasures to hand and then discard adventure card
	
	printf("\nTesting if discarded properly\n");
	success = -1;
	if(pre_g.playedCardCount == g.playedCardCount-1){
		success = 1;
	}
	acheck(success, 1);


}
int main(int argc, char *argv[])
{
	testVillage();
	return 0;
}



