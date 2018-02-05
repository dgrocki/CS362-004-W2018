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
		g->hand[p][1] = duchy;
		g->hand[p][2] = province;
		g->hand[p][3] = smithy;
		g->hand[p][4] = smithy;
		g->hand[p][5] = smithy;
		g->hand[p][6] = smithy;
		g->hand[p][7] = smithy;
		g->hand[p][8] = smithy;
		g->hand[p][9] = smithy;
		g->hand[p][10] = smithy;
		g->hand[p][11] = smithy;


}


void acheck(score, actual){
	if(actual == score){
		printf("TEST PASSED score: %d expected: %d\n",score,actual);
	}else{
		
		printf("TEST FAILED score: %d expected: %d\n",score,actual);
	}
}

void testScoreFor() {


	srand(time(NULL));
	struct gameState g;
	int players = 2;
	int cards[10] = {adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall};
	int p = 0;
	int score = 0; 
	int actual =0;
	
	printf("------------------TESTING SCORE FOR------------------\n\n");



//		memset(&g, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(players, cards, 1000, &g); // initialize a new game
		
		printf("\nTesting Score Beginning of Game\n");
		score = scoreFor(p,&g);	//should start with score 3
		acheck(score,3);	


			
		printf("\n\nTesting Score Hand Only\n");

		g.handCount[p]= 11;
		g.deckCount[p] = 0;
		g.discardCount[p] = 0;
		set_hand(&g);
		actual = 10;

		printf("Testing 1 Providence, 1 Duchy, 1 Estate\n");
		score = scoreFor(p,&g);
		acheck(score, actual);
		
//////////
	
		printf("Testing 1 Providence, 1 Duchy, 1 Estate, 1 Curse\n");
		
		g.hand[p][3] = curse;
		actual = 9;
		acheck(scoreFor(p,&g),actual);

////////
		
	
		printf("Testing 1 Providence, 1 Duchy, 1 Estate, 1 Curse, 1 Great Hall\n");
		g.hand[p][4] = great_hall;
		actual = 10;
		acheck(scoreFor(p,&g),actual);

///////
			
		printf("Testing 1 Providence, 1 Duchy, 1 Estate, 1 Curse, 1 Great Hall, 1 Garden\n");
		g.hand[p][5] = gardens;
		actual = 11;
		acheck(scoreFor(p,&g),actual);



		//check discard



		printf("\n\nTesting Score Deck Only\n");
			
		g.handCount[p]= 0;
		g.deckCount[p] = 11;
		g.discardCount[p] = 0;
		set_deck(&g);
		actual = 10;


		printf("Testing 1 Providence, 1 Duchy, 1 Estate\n");
		score = scoreFor(p,&g);
		acheck(score, actual);
		
//////////
	
		
		printf("Testing 1 Providence, 1 Duchy, 1 Estate, 1 Curse\n");
		g.discard[p][3] = curse;
		actual = 9;
		acheck(scoreFor(p,&g),actual);

////////
		
	
		printf("Testing 1 Providence, 1 Duchy, 1 Estate, 1 Curse, 1 Great Hall\n");
		g.discard[p][4] = great_hall;
		actual = 10;
		acheck(scoreFor(p,&g),actual);

///////
			
		printf("Testing 1 Providence, 1 Duchy, 1 Estate, 1 Curse, 1 Great Hall, 1 Garden\n");
		g.discard[p][5] = gardens;
		actual = 11;
		acheck(scoreFor(p,&g),actual);







//deck/////
//
//
		
		printf("\n\nTesting Score Discard Only\n");
		g.handCount[p]= 0;
		g.deckCount[p] = 0;
		g.discardCount[p] = 11;
		set_discard(&g);
			actual = 10;


		printf("Testing 1 Providence, 1 Duchy, 1 Estate\n");
		score = scoreFor(p,&g);
		acheck(score, actual);
		
//////////
	
		
		printf("Testing 1 Providence, 1 Duchy, 1 Estate, 1 Curse\n");
		g.deck[p][3] = curse;
		actual = 9;
		acheck(scoreFor(p,&g),actual);

////////
		
		printf("Testing 1 Providence, 1 Duchy, 1 Estate, 1 Curse, 1 Great Hall\n");
	
		g.deck[p][4] = great_hall;
		actual = 10;
		acheck(scoreFor(p,&g),actual);

///////
			
		printf("Testing 1 Providence, 1 Duchy, 1 Estate, 1 Curse, 1 Great Hall, 1 Garden\n");
		g.deck[p][5] = gardens;
		actual = 11;
		acheck(scoreFor(p,&g),actual);


//all of above
//
		printf("\n\nTesting Score all Only\n");
		g.handCount[p]= 11;
		g.deckCount[p] = 11;
		g.discardCount[p] = 11;
		set_deck(&g);
		set_hand(&g);
		set_discard(&g);
		actual = 30;

	
		printf("Testing 3 Providence, 3 Duchy, 3 Estate\n");
		score = scoreFor(p,&g);
		acheck(score, actual);
		
//////////
	
		
		printf("Testing 3 Providence, 3 Duchy, 3 Estate, 3 Curse\n");
		g.deck[p][3] = curse;
		g.discard[p][3] = curse;
		g.hand[p][3] = curse;
		actual -= 3;
		acheck(scoreFor(p,&g),actual);

////////
		
		printf("Testing 3 Providence, 3 Duchy, 3 Estate, 3 Curse, 3 Great Hall\n");
	
		g.deck[p][4] = great_hall;
		g.hand[p][4] = great_hall;
		g.discard[p][4] = great_hall;
		actual += 3;
		acheck(scoreFor(p,&g),actual);

///////
			
		printf("Testing 3 Providence, 3 Duchy, 3 Estate, 3 Curse, 3 Great Hall, 3 Garden\n");
		g.deck[p][5] = gardens;
		g.hand[p][5] = gardens;
		g.discard[p][5] = gardens;
		actual += 9; //3 for each garden since 33 cards;
		acheck(scoreFor(p,&g),actual);



}
int main(int argc, char *argv[])
{
	testScoreFor();
	return 0;
}



