#include "perso.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

short int pos_attack(struct perso *perso1){
	short int pos;
	for(long int unsigned a = 0; a < sizeof(perso1->attacks) / sizeof(perso1->attacks[0]);a++){
		if(perso1->attacks[a].name[0] =='\0')	
			break;
		pos++;
	
	}
	return pos;	
}
void add_attack(struct perso *perso1, short int pos, char name_attack[]){
	strcpy(perso1->attacks[pos].name, name_attack);
	perso1->attacks[pos].pp = 20;
	perso1->attacks[pos].damage = 10;
	strcpy(perso1->attacks[pos].action, "attack");
}

void no_sei(struct perso *perso1){
	short int a = sizeof(perso1->attacks) / sizeof(perso1->attacks[0]);		
	for(short int b = 0; b <= a; b++){
		printf("attack %hd: %s\n", b+1, perso1->attacks[b].name);
		
	}
}

void no_sei2(struct perso *perso1){
	short int a = sizeof(perso1->itens) / sizeof(perso1->itens[0]);
	for(short int b = 0; b <= a; b++){
		printf("item %hd: %s\n", b+1,  perso1->itens[b].name);
	
	}

}

void show_you(struct perso *perso1){
	printf("name: %s\n", perso1->name);
	printf("hp: %hd\n", perso1->hp);
	printf("attack: %hd\n", perso1->damage);
	printf("defense: %hd\n", perso1->defense);
	printf("race: %s\n", perso1->race);
	printf("type: %s\n", perso1->type);
	printf("money: %hd\n", perso1->money);
	no_sei(perso1);
	no_sei2(perso1);

	}

static void race_status(struct perso *perso2){
	if((strcmp(perso2->race, "demon")) == 0){
		perso2->hp += 50;
		perso2->damage += 10;
		perso2->defense += 10;
		strcpy(perso2->type, "fire");
		add_attack(perso2, pos_attack(perso2), "ball of fire");
		}
	else if((strcmp(perso2->race,"human")) == 0){
		perso2->hp -= 10;
		perso2->damage += 30;
		perso2->defense -= 5;
		strcpy(perso2->type, "earth");
		add_attack(perso2, pos_attack(perso2), "ball of earth");

		}
	else if((strcmp(perso2->race, "sky")) == 0){
		perso2->hp += 100;	
		perso2->damage -= 5;
		perso2->defense -= 5;	
		strcpy(perso2->type, "wind");
		add_attack(perso2, pos_attack(perso2), "ball of wind");

	}
	else if((strcmp(perso2->race, "shark")) == 0){
		perso2->hp += 10;
		perso2->defense += 40;
		perso2->damage -= 5;
		strcpy(perso2->type, "water");
		add_attack(perso2, pos_attack(perso2), "ball of water");

		}

	}
		
void create_perso(struct perso *perso2){
	perso2->hp = 100;
	perso2->damage = 10;
	perso2->defense = 10;
	perso2->money = 50;
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
