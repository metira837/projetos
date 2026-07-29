#include <stdio.h>
#include <string.h>
#include "perso.h"
#include "enemy.h"

short int  attack_perso(struct perso *perso1, struct enemy *enemy1, struct attack atk_perso){
	short int damage1 = 0;
	damage1 += perso1->damage;
	if(atk_perso->pp == 0)
			return 0;

	if(strcmp(perso1->type, atk_perso->type ) == 0 )
		damage1 *= 1.5;	
	return 1;
	enemy1->hp -= damage1;
	}

void attack_enemy(struct perso *perso1, struct enemy *enemy1,  struct attack_enemy atk_enemy){
		short int damage = 0;
		damage = (enemy1->damage + atk_enemy.damage) * 1.5;	
	perso1->hp -= damage;
}
