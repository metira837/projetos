#include "perso.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


/* i create this function because use function of string.h the programa stay slow */
static char *stn(char *dst, const char *src){
	short int a = 0;
	for(; src[a] != '\0';a++){
		dst[a] = src[a];
	}
	dst[a] = '\0';
	return dst;
}





void create_perso(struct perso *perso1){
	printf("your status:\n");
	perso1->hp = 100;
	perso1->damage = 10;
	perso1->defense = 10;

	stn(perso1->attacks[0], "ball of fire");
	stn(perso1->attacks[1], "ball of water");
	stn(perso1->attacks[2], "ball of wind");
}


void your_race(struct perso *perso1){
	short int chances = 3;
	char p[2];
	char races[4][7] = {"demon", "sky", "human", "golbin"};

	printf("test your lucky for one race good\n");

	do{
		srand(time(NULL));
		short int random = rand() % 4;
		strcpy(perso1->race, races[random]);	
		printf("you got a race %s\nyou wants trade this race?", perso1->race); scanf("%s", p);
		--chances;

	}while (chances != 0 && strcmp(p, "no"));
	if(chances == 0)
		printf("you no has more chances ;((\n");
}
