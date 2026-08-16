#include "shop.h"
#include <string.h>
#include "battle.h"
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
void potions(struct perso *perso1, struct enemy *enemy1, struct item *item1);
short int attack_perso(struct perso *perso1, struct enemy *enemy1, struct attack *atk_perso);
void attack_enemy(struct perso *perso1, struct enemy *enemy1,  struct attack_enemy atk_enemy);
void show_options(struct perso *perso1, struct action *action1);





int main(void){
	short int wave = 1;
	struct perso you;
	bool option = true;
	struct enemy enemy1;
	struct action action1;
	printf("what is your name?\n"); scanf("%s", you.name);
	printf("welcome, %s\n", you.name);
	your_race(&you);		
	create_perso(&you);
	shop(you.money, &you);
	show_you(&you);
	create_enemy(&enemy1);
	do{
		create_enemy(&enemy1);
		printf("you is at wave %hd\n", wave);
		printf("your enemy is %s\n", enemy1.name);
		show_options(&you, &action1);		
		printf("%s\n", action1.action_user);
		printf("%d\n", strcmp("attack", action1.action2));
		break;


		++wave;
	
	}
	
	while(you.hp != 0 || option != false);
	return 0;
	}



