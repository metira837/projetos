#include <stdio.h>
#include <string.h>
#include "perso.h"
#include "enemy.h"
#include "battle.h"


void potions(struct perso *perso1, struct enemy *enemy1, struct item *item1){
	if(strcmp(item1->name, "heal potion") == 0)
		perso1->hp += 50;
	else
		strcpy(enemy1->effect, "poison");
}

short int attack_perso(struct perso *perso1, struct enemy *enemy1, struct attack *atk_perso){
	short int damage1 = 0;
	damage1 += perso1->damage;
	if(atk_perso->pp == 0)
		return 0;

	if(strcmp(perso1->type, atk_perso->type ) == 0 )
		damage1 *= 1.5;	

	return 1; // i add this because of compiler not show warning, but it will be ignored
	enemy1->hp -= damage1;
	}

void attack_enemy(struct perso *perso1, struct enemy *enemy1,  struct attack_enemy atk_enemy){
	short int damage = 0;
	damage = (enemy1->damage + atk_enemy.damage) * 1.5;	
	perso1->hp -= damage;
}

struct action show_options(struct perso *perso1){
	short int option = 0, option_action = 0;
	struct action action1;
	printf("1- moves\t 2-itens\n"); scanf("%hd", &option);
	back:

	if(option == 1){
		no_sei(perso1);
		printf("what attack you want use?"); scanf("%hd", &option_action);
		strcpy(action1.action, "attack");
		strcpy(action1.action_user, perso1->attacks[option_action-1].name);
	}
			
	else if(option == 2){
		no_sei2(perso1);
		printf("what potion you want use?"); scanf("%hd", &option_action);
		strcpy(action1.action, "potion");
		strcpy(action1.action_user, perso1->itens[option_action-1].name);

	}
	else{
		printf("no exist this option");
		goto back;
	}
	return action1;
}
