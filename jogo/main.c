#include "shop.h"
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
void random_enemy(struct enemy *enemy1);


int main(void){
	struct perso you;
	struct enemy enemy1;
	printf("what is your name?\n"); scanf("%s", you.name);
	printf("welcome, %s\n", you.name);
	your_race(&you);		
	create_perso(&you);
	shop(you.money, &you);
	show_you(&you);
	random_enemy(&enemy1);
	printf("%s\n", enemy1.name);
	return 0;
	}



