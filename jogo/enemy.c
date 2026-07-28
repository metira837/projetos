#include <stdio.h>
#include <string.h>
#include "enemy.h"
#include <time.h>
#include <stdlib.h>

static void type_enemy(struct enemy *enemy1){
	if(strcmp(enemy1->name, "goblin") == 0)
		strcpy(enemy1->type, "earth");
	else if(strcmp(enemy1->name, "demon") == 0)
		strcpy(enemy1->type, "fire");
	else
		strcpy(enemy1->type, "sky");
}

static void enemy_status(struct enemy *enemy1){
	if(strcmp(enemy1->name, "goblin") == 0){
		enemy1->damage += 10;
		enemy1->defense += 10;
		enemy1->hp += 20;
		strcpy(enemy1->attack[0].name, "wall of earth");

	
	}
	else if(strcmp(enemy1->name, "demon") == 0){
		enemy1->damage += 15;
		enemy1->defense += 10;
		enemy1->hp += 30;
		strcpy(enemy1->attack[0].name, "wall of fire");
	}
	else{
		enemy1->damage += 18;
		enemy1->defense += 25;
		enemy1->hp += 30;
		strcpy(enemy1->attack[0].name, "wall of wind");
	}
	

}

static void random_enemy(struct enemy *enemy1){
	char names[3][10] = {"goblin", "demon", "dog"};
	srand(time(NULL));
	short int number = rand() % 3;
	strcpy(enemy1->name, names[number]);		
}

void create_enemy(struct enemy *enemy1){
	enemy1->hp = 100;
	enemy1->damage = 10;
	enemy1->defense = 10;
	random_enemy(enemy1);	
	type_enemy(enemy1);
	enemy_status(enemy1);


}
