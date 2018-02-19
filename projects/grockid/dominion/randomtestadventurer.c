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


void testAdventurer() {

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


	srand(time(NULL));
	int players = 2;
	int cards[10];
	int p = 0;
	int bonus = 0;
	int r = 2000;	
	int success = 0;
	int hand_size;	
	int deck_size;
	int maxdeck_size;
	int discard_size;
	int adv_pos = -1;
	int loop;
	int i;
	int check1=0, check2=0, check3=0, check4=0, check5=0, check6=0;
	int handtreasurecount=0, decktc=0, htcn=0, dtcn=0;
	int onet= 0, zerot = 0;


	//	printf("\n------------------TESTING ADVENTURER------------------\n\n");
	for(loop = 0; loop < r; loop++){
		struct gameState g;
		players = rand()%3+2;
		p = rand()%players;
		g.playedCardCount = 0;
		for(i = 0; i < 10 ; i++){
			cards[i] = master[rand()%27];
		}
		cards[rand()%10] = adventurer;
		
		
		initializeGame(players, cards, 1000, &g); // initialize a new game
		g.whoseTurn = p;


		htcn=0;
		dtcn=0;

		handtreasurecount = 0;
		decktc = 0;
		hand_size = rand()%100;	
		maxdeck_size = rand()%100;

		if(maxdeck_size == 0){
			discard_size = 0;
			deck_size =0;
		}else{
			discard_size = rand()%maxdeck_size;
			deck_size = maxdeck_size - discard_size;
		}
		adv_pos = -1;
		//reasonably won' t have more than 100 cards in your deck or hand
		g.handCount[p] = hand_size;
		g.deckCount[p] = deck_size;
		g.discardCount[p] = discard_size;


		for(i = 0; i < hand_size; i ++){
			g.hand[p][i] = cards[rand()%10];
			if(g.hand[p][i] == adventurer){
				adv_pos = i;
			}

			if(g.hand[p][i] == copper || g.hand[p][i] == silver || g.hand[p][i] == gold){
				handtreasurecount++;
			}

		}
		if (adv_pos == -1 && hand_size > 0){
				if(g.hand[p][0] == copper || g.hand[p][0] == silver || g.hand[p][0] == gold){
					handtreasurecount--;
					}


			g.hand[p][0] = adventurer;
			adv_pos = 0;
		}

		for(i = 0; i < deck_size; i ++){
			g.deck[p][i] =  cards[rand()%10];
			if(g.deck[p][i] == copper || g.deck[p][i] == silver || g.deck[p][i] == gold){
				decktc++;
			}
		}

		for(i = 0; i < discard_size; i ++){
			g.discard[p][i] = cards[rand()%10];
			if(g.discard[p][i] == copper || g.discard[p][i] == silver || g.discard[p][i] == gold){
				decktc++;
			}
		}


		//test if stops after finding 2 treasures
		//test if shuffles discard if decke empty
		//test if discarda all drawn cards


		if(decktc == 0){
			zerot++;
		}
		if(decktc==1){
			onet++;
		}
		


		success = cardEffect(adventurer, 0,0,0, &g,adv_pos,&bonus);
		

		for(i = 0; i < g.handCount[p]; i ++){
			if(g.hand[p][i] == copper || g.hand[p][i] == silver || g.hand[p][i] == gold){
				htcn++;
			}

		}
		for(i = 0; i < g.deckCount[p]; i ++){
			if(g.deck[p][i] == copper || g.deck[p][i] == silver || g.deck[p][i] == gold){
				dtcn++;
			}
		}

		for(i = 0; i < g.discardCount[p]; i ++){
			if(g.discard[p][i] == copper || g.discard[p][i] == silver || g.discard[p][i] == gold){
				dtcn++;
			}
		}



		//	2 less treasures in deck		
		if(acheck(dtcn, decktc-2))
			check1++;

		if(acheck(htcn, handtreasurecount+2))
			check2++;
		

		//check for times with no treasures
		if(acheck(htcn, handtreasurecount+1))
			check5++;


		if(acheck(htcn, handtreasurecount)){
			check6++;
		
		}	
		//check times with only 1 treasure
		
		//	printf("\n\nTesting Cards in Deck If Adventurer Ran Successfully\n");
		if(acheck(success, 0))
			check3++;


//		if(acheck(1 , g.playedCardCount))
//			check4++;
		//	printf("\n\nTesting If Adventurer Found 2 treasures\n");
		if(acheck(g.handCount[p], hand_size + 1))
			check4++;	//add 2 treasures to hand and then discard adventure card



		//test number drawn
		//test discarded
		//


		//		memset(&g, 23, sizeof(struct gameState));   // clear the game state
	}
	printf("Adventurer removed 2 treasures from the deck %d out of %d times\n", check1, r);
	printf("Adventurer added 2 treasures to the hand %d out of %d times\n", check2, r);
	printf("Adventurer works when only 1 treasure in deck %d out of %d times\n", check5, onet);
	printf("Adventurer works when only 0 treasure in deck %d out of %d times\n", check6, zerot);

	printf("Adventurer ran successsfully %d out of %d times\n", check3, r);
	printf("Adventurer removed from hand %d out of %d times\n", check4, r);



}
int main(int argc, char *argv[])
{
	testAdventurer();
	return 0;
}


