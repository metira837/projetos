#include "shop.h"
#include <stdbool.h>
#include "perso.h"
#include "enemy.h"
#include <stdio.h>

//declarations of functions

void your_race(struct perso *perso1);
void create_perso(struct perso *perso1);
void shop(short int money, struct perso *perso1);
void show_you(struct perso *perso1);
void no_sei2(struct perso *perso1);
void no_sei2(struct perso *perso1);
void create_enemy(struct enemy *enemy1);

int main(void){
	short int wave = 0;
	struct perso you;
	bool option = true;
	struct enemy enemy1;
	printf("what is your name?\n"); scanf("%s", you.name);
	printf("welcome, %s\n", you.name);
	your_race(&you);		
	create_perso(&you);
	shop(you.money, &you);
	show_you(&you);
	create_enemy(&enemy1);
		
	do{
		printf("you is at wave %hd\n", wave);
		++wave;
	
	}
	
	while(you.hp != 0 || option != false);
	return 0;
	}



