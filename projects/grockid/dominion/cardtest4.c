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

	g->hand[p][0] = council_room;
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

void testCouncilRoom() {


	srand(time(NULL));
	struct gameState g;
	int players = 3;
	int cards[10] = {adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall};
	int i,p;
	int bonus = 0;	
	int success = 0;
	int inital_hand = 5;
	int inital_buys = 0;


	initializeGame(players, cards, 1000, &g); // initialize a new game
//	initializeGame(players, cards, 1000, &pre_g); // initialize a new game

	printf("\n------------------TESTING COUNCIL ROOM------------------\n\n");

	for(p = 0; p< players; p++){
		g.handCount[p] = inital_hand;
		g.deckCount[p] = 5;
		g.discardCount[p] = 5;

		set_hand(&g);
		set_deck(&g);
	}
	g.whoseTurn = 0;

	inital_buys = g.numBuys;
	//ran
	//current player +4 cards
	//other players + 1card
	//discard card
	//more buys


	



	success = cardEffect(council_room, 0,0,0, &g,0,&bonus);


	printf("\n\nTesting Council Room Ran Successfully\n");
	acheck(success, 0);

	printf("\nTesting adding more buys\n");


	acheck(inital_buys, g.numBuys-1);	//- since add 1 buy



	printf("\n\nTesting If Council Room discarded\n");
	success = 0;
	for(i = 0; i < inital_hand; i++){
		if(g.deck[p][i] == council_room){		//if council Room no longer in hand
			success = -1;
			break;
		}
	}
	acheck(success, 0);

	printf("\n\nTesting If Council Room Added 4 cards to Player %d and Discard 1\n", 0);

	acheck(g.handCount[0],inital_hand+3);

	for(i = 1; i < players; i++){
		printf("Testing if player %d recieved a card\n", i);
		acheck(g.handCount[i], inital_hand+1);
	}	


}
int main(int argc, char *argv[])
{
	testCouncilRoom();
	return 0;
}



