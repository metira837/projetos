struct perso{
	short int hp;
	char name[40];
	short int damage;
	short int defense;
	char race[10];
	char attacks[20][4];

};


/* functions of perso.c */

void your_race (struct perso *perso1);

