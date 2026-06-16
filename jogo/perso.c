#include "perso.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>



static void race_status(struct perso *perso1){
	if((strcmp(perso1->race, "demon")) == 0){
		perso1->hp += 50;
		perso1->damage += 10;
		perso1->defense += 10;

	}
	else if((strcmp(perso1->race,"human")) == 0){
		perso1->hp -= -10;
		perso1->damage += 30;
		perso1->defense -= -5;
	}
	else if((strcmp(perso1->race, "sky")) == 0){
		perso1->hp += 100;	
		perso1->damage += -5;
	       	perso1->defense += -5;	
	}
	else if((strcmp(perso1->race, "shark")) == 0){
		perso1->hp += 10;
		perso1->defense += 40;
		perso1->damage += -5;
	}

}
	

void create_perso(struct perso *perso1){
	printf("your status:\n");
	perso1->hp = 100;
	perso1->damage = 10;
	perso1->defense = 10;
	race_status(perso1);
}


void your_race(struct perso *perso1){
	short int chances = 3;
	char p[2];
	char races[4][7] = {"demon", "sky", "human", "shark"};

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
