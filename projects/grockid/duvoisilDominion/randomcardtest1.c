#include<stdio.h>


void testAdventurer() {


	srand(time(NULL));
	struct gameState g;
	int players = 2;
	int cards[10] = {adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall};
	int p = 0;
	int bonus = 0;	
	int success = 0;
	int hand_size = rand()%100;	
	int deck_size = rand()%100;

	printf("\n------------------TESTING ADVENTURER------------------\n\n");
	initializeGame(players, cards, 1000, &g); // initialize a new game

	//reasonably won' t have more than 100 cards in your deck or hand
	g.handCount[p] = hand_size;
	g.deckCount[p] = deck_size;
	g.discardCount[p] = deck_size+hand_size;
	
	
	for(i = 0; i < hand_size; i ++){
		g.hand[p][i] = 
	
	}


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
	
	success = cardEffect(adventurer, 0,0,0, &g,1,&bonus);
	
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


