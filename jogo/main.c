#include "shop.h"
#include "perso.h"
#include "enemy.h"
#include <stdio.h>

//declarations of functions

void your_race(struct perso *perso1);
void create_perso(struct perso *perso1);
int shop(int money);

int main(void){
	struct perso you;
	printf("what is your name?\n"); scanf("%s", &you.name);
	printf("welcome, %s\n", you.name);
	your_race(&you);		
	create_perso(&you);
		printf("%d\n", you.hp);
		printf("%d\n", you.damage);
		printf("%d\n", you.defense);
		printf("%s\n", you.type);
		shop(you.money);
		return 0;
	}



