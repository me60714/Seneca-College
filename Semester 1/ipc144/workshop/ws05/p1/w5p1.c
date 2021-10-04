/*
	==================================================
	Workshop #5 (Part-1):
	==================================================
	Name   : Wei-Chih Kao
	ID     : 158000190
	Email  : wkao3@myseneca.ca
	Section: ZAA
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAXIMUM_PATH 70

struct PlayerInfo{
	int num_lives;
	char character_symbol;
	int num_treasure;
	int positions[MAXIMUM_PATH];
};

struct GameInfo{
	int max_num_move;
	int path_length;
	int bombs[MAXIMUM_PATH];
	int treasure[MAXIMUM_PATH];
};

int main(){
	struct PlayerInfo player;
	struct GameInfo game;

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &player.character_symbol);

	do{
		printf("Set the number of lives: ");
		scanf("%d", &player.num_lives);

		if(player.num_lives < 1 || player.num_lives > 10){
			printf("     Must be between 1 and 10!\n");
		}
		
	}while (player.num_lives < 1 || player.num_lives > 10);

	printf("Player configuration set-up is complete\n\n");
	printf("GAME Configuration\n");
	printf("------------------\n");

	do{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &game.path_length);

		if (game.path_length < 10 || game.path_length > MAXIMUM_PATH || game.path_length % 5 != 0){
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
		}

	}while (game.path_length < 10 || game.path_length > MAXIMUM_PATH || game.path_length % 5 != 0);

	do{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.max_num_move);

		if (game.max_num_move < 3 || game.max_num_move > 26){
			printf("    Value must be between 3 and 26\n");
		}

	}while (game.max_num_move < 3 || game.max_num_move > 26);

	printf("\nBOMB Placement");
	printf("\n--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

	int i;
	for (i = 0; i < game.path_length; i += 5){

		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

		int j;
		for (j = i; j < i + 5; j++){
			scanf("%d", &game.bombs[j]);
		}
	}
	printf("BOMB placement set\n");

	//treasure set
	printf("\nTREASURE Placement");
	printf("\n------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

	for (i = 0; i < game.path_length; i += 5){
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

		int j;
		for (j = i; j < i + 5; j++){
			scanf("%d", &game.treasure[j]);
		}
	}

	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.character_symbol);
	printf("   Lives      : %d\n", player.num_lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n");

	printf("\nGame:\n");
	printf("   Path Length: %d\n", game.path_length);
	
	printf("   Bombs      : ");
	
	for (i = 0; i < game.path_length; i++){
		printf("%d", game.bombs[i]);
	}
	
	printf("\n   Treasure   : ");
	
	for (i = 0; i < game.path_length; i++){
		printf("%d", game.treasure[i]);
	}

	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");

	return 0;
}