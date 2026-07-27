#include "shop.h"
#include "perso.h"
#include "enemy.h"
#include <stdio.h>

//declarations of functions

void your_race(struct perso *perso1);
void create_perso(struct perso *perso1);
void shop(short int money, struct perso *perso1);
void show_you(struct perso *perso1);
int main(void){
	struct perso you;
	printf("what is your name?\n"); scanf("%s", you.name);
	printf("welcome, %s\n", you.name);
	your_race(&you);		
	create_perso(&you);
	shop(you.money, &you);
	show_you(&you);
	return 0;
	}



