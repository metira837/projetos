#ifndef HEADER_ENEMY
#define HEADER_ENEMY

struct attack_enemy{
	char name[10];
	short int damage;
	char type[10];
};

struct enemy{
	char name[20];
	short int hp;
	short int damage;
	short int defense;
	char type[7];
	struct attack_enemy attack[1];
};
void random_enemy(struct enemy *enemy1);
#endif


