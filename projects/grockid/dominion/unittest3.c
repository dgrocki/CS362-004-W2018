#include<stdio.h>
#include<stdlib.h>
#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include<time.h>



void testIsGameOver() {


	srand(time(NULL));
	struct gameState g;
	int players = 2;
	int cards[10] = {adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall};
	int p,i;
	int game_status = 0; 
	
	//	struct BSTree *tree = buildBSTTree();

	//    struct data myData1;
	//	struct data myData2;
	//	struct data myData3;
	//	struct data myData4;
	//	struct data myData5;



	printf("------------------TESTING IS GAME OVER------------------\n\n");



	for (p = 0; p < players; p++)
	{
//		memset(&g, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(players, cards, 1000, &g); // initialize a new game
		


		printf("\nTesting new game if over\n");
		game_status = isGameOver(&g);	//new game isn' t over
		assert(game_status == 0);
		printf("TEST PASSED\n");

		//part way through game
		for(i = 0; i <25; i++){
			if(g.supplyCount[i] > 0){
				g.supplyCount[i] = 5;
			}
		}
		
		printf("\nTesting part way game not over\n");
		game_status = isGameOver(&g);	//new game isn' t over
		assert(game_status == 0);
		printf("TEST PASSED\n");
	


		printf("\nTesting out of provinces\n");
		g.supplyCount[province] = 0;
		game_status = isGameOver(&g);	//out of provinces
		assert(game_status == 1);		//game should end
		printf("TEST PASSED\n");

		
		printf("\nTesting out of 2 piles\n");
		g.supplyCount[province] = 1;
		g.supplyCount[smithy] = 0;
		g.supplyCount[baron] = 0;
		game_status = isGameOver(&g);	//2 empty piles
		assert(game_status == 0);		//game should not end 
		printf("TEST PASSED\n");


		printf("\nTesting out of 3 piles\n");
		g.supplyCount[mine] = 0;
		game_status = isGameOver(&g);	//3 empty piles
		assert(game_status == 1);		//game should  end 
		printf("TEST PASSED\n");
	
		
	}
}
int main(int argc, char *argv[])
{
	testIsGameOver();
	return 0;
}



