#include "perso.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>




void your_race(struct perso *perso1){
	short int chances = 3;
	char p[2];
	char races[4][7] = {"demon", "sky", "human", "golbin"};

	printf("test your lucky for have one race good\n");

	do{
		srand(time(NULL));
		short int random = rand() % 4;
		strcpy(perso1->race, races[random]);	
		printf("you got a race %s\nyou wants trade this race?", perso1->race); scanf("%s", p);
		--chances;

	}while (chances != 0 && strcmp(p, "no"));
	if(chances == 0)
		printf("you no have more chances ;((\n");
}
