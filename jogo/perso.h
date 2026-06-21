#ifndef PERSO_H
#define PERSO_H

struct attack{
	short int damage;
	char type[5];
	short int pp;
	char name[21];

};

struct perso{
	short int hp;
	char name[40];
	short int damage;
	short int defense;
	char race[10];
	struct attack attacks[3];
	char type[5];
	short int money;

};
/* functions of perso.c */

void your_race (struct perso *perso1);
void create_perso(struct perso *perso1);
#endif
