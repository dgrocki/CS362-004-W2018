#include<stdio.h>
#include<stdlib.h>
#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include<time.h>

int acheck(score, actual){
	if(actual == score){
		return 1;
	}else{
		return 0;	
	}
}


void testVillage() {


	srand(time(NULL));
	int players = 2;

	int master[27] =  {curse ,
	estate,
   duchy,
   province,

   copper,
   silver,
   gold,

   adventurer,
   /* If no/only 1 treasure found, stop when full deck seen */
   council_room,
   feast, /* choice1 is supply # of card gained) */
   gardens,
   mine, /* choice1 is hand# of money to trash, choice2 is supply# of
	    money to put in hand */
   remodel, /* choice1 is hand# of card to remodel, choice2 is supply# */
   smithy,
   village,

   baron, /* choice1: boolean for discard of estate */
   /* Discard is always of first (lowest index) estate */
   great_hall,
   minion, /* choice1:  1 = +2 coin, 2 = redraw */
   steward, /* choice1: 1 = +2 card, 2 = +2 coin, 3 = trash 2 (choice2,3) */
   tribute,

   ambassador, /* choice1 = hand#, choice2 = number to return to supply */
   cutpurse,
   embargo, /* choice1 = supply# */
   outpost,
   salvager, /* choice1 = hand# to trash */
   sea_hag,
   treasure_map
  };


	int cards[10];
	//	= {adventurer, council_room, feast, gardens, mine
	//	, remodel, smithy, village, baron, great_hall};
	int p = 1;
	int bonus = 0;
	int r = 2000;	
	int success = 0;
	int hand_size =0;	
	int deck_size =0;
	int maxdeck_size =0;
	int discard_size=0;
	int v_pos = -1;
	int loop;
	int i;
	int check1=0, check2=0, check3=0, check4=0, check5 = 0, check6=0;
	int preActions;
	int dd_empty = 0;


	for(loop = 0; loop < r; loop++){
		struct gameState g;
		players = rand()%3+2;
		p = rand()%players;
		g.playedCardCount = 0;
		for(i = 0; i < 10 ; i++){
			cards[i] = master[rand()%27];
		}
		cards[rand()%10] = village;
		
		
		initializeGame(players, cards, 1000, &g); // initialize a new game
		g.whoseTurn = p;

		hand_size = rand()%100;	
		maxdeck_size = rand()%100;

		if(maxdeck_size == 0){
			discard_size = 0;
			deck_size =0;
		}else{
			discard_size = rand()%maxdeck_size;
			deck_size = maxdeck_size - discard_size;
		}
		v_pos = -1;
		//reasonably won' t have more than 100 cards in your deck or hand
		g.handCount[p] = hand_size;
		g.deckCount[p] = deck_size;
		g.discardCount[p] = discard_size;

		for(i = 0; i < hand_size; i ++){
			g.hand[p][i] = cards[rand()%10];
			if(g.hand[p][i] == village){
				v_pos = i;
			}

		}
		if (v_pos == -1 && hand_size > 0){
			g.hand[p][0] = village;
			v_pos = 0;
		}

		for(i = 0; i < deck_size; i ++){
			g.deck[p][i] = cards[rand()%10];
		}

		for(i = 0; i < discard_size; i ++){
			g.discard[p][i] = cards[rand()%10];
		}


		//test if stops after finding 2 treasures
		//test if shuffles discard if decke empty
		//test if discarda all drawn cards

		
		preActions = g.numActions;
		if(maxdeck_size == 0){
			dd_empty++;
		}
		success = cardEffect(village, 0,0,0, &g,v_pos,&bonus);


		//	2 less treasures in deck		
		if(acheck(g.handCount[p], hand_size))	//+0 since village should be removed and 1 added
			check1++;


		
		if(acheck(maxdeck_size, g.deckCount[p]+g.discardCount[p]+1))//1 cards removed from deck and or discard if shuffled
			check2++;

		if(acheck(g.handCount[p], hand_size-1)) //check for times where deck and discard empty
			check6++;

		if(acheck(preActions+2, g.numActions))
			check5++;


		if(acheck(success, 0))
			check3++;

		//if shuffled
/*		if(deck_size - 3 >= 0){	//no shuffle
			if(discard_size+1 == g.discardCount[p]){
				check4++;
			}
		}else{
			if(g.discardCount[p] == 1){
				check5++;
			}
		}
*/
		if(acheck(1 , g.playedCardCount))
			check4++;


	}
	printf("Village added 1 card  %d out of %d times\n", check1, r-dd_empty);
	printf("Village removed 1 card from the deck/discard %d out of %d times\n", check2, r-dd_empty);
	printf("Village drew nothing with 0 cards in deck/discard %d out of %d times\n", check6, dd_empty);
	printf("Village added 2 actions  %d out of %d times\n", check5, r);
	printf("Village ran successsfully %d out of %d times\n", check3, r);
	printf("Village properly discarded %d out of %d times\n", check4, r);
//	printf("Smithy shuffled and properly discarded %d out of %d times\n", check5, r);



}
int main(int argc, char *argv[])
{
	testVillage();
	return 0;
}


