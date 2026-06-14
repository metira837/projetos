#include "perso.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct perso your_race(struct perso perso1){
	char races[4][7] = {"demon", "sky", "human", "golbin"};

	srand(time(NULL));
	short int random = rand() % 4;


	strcpy(perso1.race, races[random]);
	printf("your race %s\n", perso1.race);
	return perso1;

}
