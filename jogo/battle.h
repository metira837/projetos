#include "enemy.h"
#include "perso.h"
void potions(struct perso *perso1, struct enemy *enemy1, struct item *item1);
short int attack_perso(struct perso *perso1, struct enemy *enemy1, struct attack *atk_perso);
void attack_enemy(struct perso *perso1, struct enemy *enemy1,  struct attack_enemy atk_enemy);
struct action show_options(struct perso *perso1);
struct action{
	// action of user (example: ball of fire or poison potion)
	char action_user [10];
	// action of attack or potion
	char action[8];


};
