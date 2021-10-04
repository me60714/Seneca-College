/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   : Wei-Chih Kao
	ID     : 158000190
	Email  : wkao3@myseneca.ca
	Section: ZAA
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXIMUM_PATH 70

struct PlayerInfo
{
	int num_lives;
	char character_symbol;
	int num_treasure;
	int positions[MAXIMUM_PATH];
	int history_path[MAXIMUM_PATH];
};

struct GameInfo
{
	int max_num_move;
	int path_length;
	int bombs[MAXIMUM_PATH];
	int treasure[MAXIMUM_PATH];
};

int main()
{
	struct PlayerInfo player;
	struct GameInfo game;

	int num_path;

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &player.character_symbol);

	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &player.num_lives);

		if (player.num_lives < 1 || player.num_lives > 10)
		{
			printf("     Must be between 1 and 10!\n");
		}

	} while (player.num_lives < 1 || player.num_lives > 10);

	printf("Player configuration set-up is complete\n\n");
	printf("GAME Configuration\n");
	printf("------------------\n");

	do
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &game.path_length);

		if (game.path_length < 10 || game.path_length > MAXIMUM_PATH || game.path_length % 5 != 0)
		{
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
		}

	} while (game.path_length < 10 || game.path_length > MAXIMUM_PATH || game.path_length % 5 != 0);
	
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.max_num_move);

		if (game.max_num_move < 3 || game.max_num_move > 15)
		{
			printf("    Value must be between 3 and 15\n");
		}

	} while (game.max_num_move < 3 || game.max_num_move > 15);

	//bomb set
	printf("\nBOMB Placement");
	printf("\n--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");

	int i;
	for (i = 0; i < game.path_length; i += 5)
	{

		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

		int j;
		for (j = i; j < i + 5; j++)
		{
			scanf("%d", &game.bombs[j]);
		}
	}
	printf("BOMB placement set\n");

	//treasure set
	printf("\nTREASURE Placement");
	printf("\n------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");

	for (i = 0; i < game.path_length; i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

		int j;
		for (j = i; j < i + 5; j++)
		{
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

	for (i = 0; i < game.path_length; i++)
	{
		printf("%d", game.bombs[i]);
	}

	printf("\n   Treasure   : ");

	for (i = 0; i < game.path_length; i++)
	{
		printf("%d", game.treasure[i]);
	}

	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");

	printf("%c%c", 0,0);

	for (i = 1; i <= game.path_length; i++)
	{
		printf("-");
	}

	printf("\n");
	printf("  ");

	for (i = 1; i <= game.path_length; i++)
	{
		if (i % 10 != 0)
		{
			printf("|");
		}
		else
		{
			printf("%d", i / 10);
		}
	}

	printf("\n");
	printf("  ");

	for (i = 1; i <= game.path_length; i++)
	{
		printf("%d", i % 10);
	}
	printf("\n");

	player.num_treasure = 0;
	
	printf("+---------------------------------------------------+\n");
	printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.num_lives, player.num_treasure, game.max_num_move);
	printf("+---------------------------------------------------+\n");

	// initialize history_path.
	int j;
	for (j = 0; j < game.path_length; j++)
	{
		player.history_path[j] = 0;
	}

	int remained_num_move = game.max_num_move;
	while ((player.num_lives > 0) && (remained_num_move > 0))
	{
		num_path = 0;

		do  
		{
			printf("Next Move [1-%d]: ", game.path_length);
			scanf("%d", &num_path);

			if (num_path < 1 || num_path > game.path_length)
			{
				printf("  Out of Range!!!\n");
			}

		} while (num_path < 1 || num_path > game.path_length);


		if ((game.bombs[num_path - 1] == 0) && (game.treasure[num_path - 1] == 0) && (player.history_path[num_path - 1] != 1))
		{
			printf("\n===============> [.] ...Nothing found here... [.]\n");
		}
		else if ((game.bombs[num_path - 1] == 1) && (game.treasure[num_path - 1] == 0) && (player.history_path[num_path - 1] != 1))
		{
			printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
			player.num_lives = player.num_lives - 1;
		}
		else if ((game.bombs[num_path - 1] == 0) && (game.treasure[num_path - 1] == 1) && (player.history_path[num_path - 1] != 1))
		{
			printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
			player.num_treasure = player.num_treasure + 1;
		}
		else if ((game.bombs[num_path - 1] == 1) && (game.treasure[num_path - 1] == 1) && (player.history_path[num_path - 1] != 1))
		{
			printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
			printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
			player.num_lives = player.num_lives - 1;
			player.num_treasure = player.num_treasure + 1;
		}
		else if (player.history_path[num_path - 1] == 1)
		{
			printf("\n===============> Dope! You've been here before!\n");
			remained_num_move++;
		}

		player.history_path[num_path - 1] = 1;

		/******************** Display info *********************/

		printf("\n");
		printf("  ");

		for (j = 1; j <= game.path_length; j++)
		{
			if (j == num_path)
			{
				printf("%c", player.character_symbol);
			}
			else
			{
				printf(" ");
			}
		}

		// problem here

		printf("\n");
		printf("  ");

		for (j = 1; j <= game.path_length; j++)
		{
			if (player.history_path[j - 1] == 0) {
				printf("-");
			}
			else {
				if ((game.bombs[j - 1] == 0) && (game.treasure[j - 1] == 0))
					printf(".");
				if ((game.bombs[j - 1] == 1) && (game.treasure[j - 1] == 0))
					printf("!");
				if ((game.bombs[j - 1] == 0) && (game.treasure[j - 1] == 1))
					printf("$");
				if ((game.bombs[j - 1] == 1) && (game.treasure[j - 1] == 1))
					printf("&");
			}
		}

		printf("\n");
		printf("  ");

		for (j = 1; j <= game.path_length; j++)
		{
			if (j % 10 != 0)
			{
				printf("|");
			}
			else
			{
				printf("%d", j / 10);
			}
		}

		printf("\n");
		printf("  ");

		for (j = 1; j <= game.path_length; j++)
		{
			printf("%d", j % 10);
		}

		printf("\n");

		remained_num_move--;
		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.num_lives, player.num_treasure, remained_num_move);
		printf("+---------------------------------------------------+\n");
	}
	
	printf("\n##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n\n");
	printf("You should play again and try to beat your score!!\n");
	
	return 0;
}