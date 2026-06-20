#include "perso.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>



static void race_status(struct perso *perso2){
	if((strcmp(perso2->race, "demon")) == 0){
		perso2->hp += 50;
		perso2->damage += 10;
		perso2->defense += 10;
		strcpy(perso2->type, "fire");

	}
	else if((strcmp(perso2->race,"human")) == 0){
		perso2->hp -= 10;
		perso2->damage += 30;
		perso2->defense -= 5;
		strcpy(perso2->type, "earth");

	}
	else if((strcmp(perso2->race, "sky")) == 0){
		perso2->hp += 100;	
		perso2->damage -= 5;
	       	perso2->defense -= 5;	
		strcpy(perso2->type, "wind");

	}
	else if((strcmp(perso2->race, "shark")) == 0){
		perso2->hp += 10;
		perso2->defense += 40;
		perso2->damage -= 5;
		strcpy(perso2->type, "water");

	}

}
	

void create_perso(struct perso *perso2){
	perso2->hp = 100;
	perso2->damage = 10;
	perso2->defense = 10;
	perso2->money = 20;
	race_status(perso2);
}


void your_race(struct perso *perso2){
	short int chances = 3;
	char p[2];
	char races[4][7] = {"demon", "sky", "human", "shark"};

	printf("test your lucky for one race good\n");

	do{
		srand(time(NULL));
		short int random = rand() % 4;
		strcpy(perso2->race, races[random]);	
		printf("you got a race %s\nyou wants trade this race?", perso2->race); scanf("%s", p);
		--chances;

	}while (chances != 0 && strcmp(p, "no"));
	if(chances == 0)
		printf("you no has more chances ;((\n");
}
