#include "perso.h"
#include "enemy.h"
#include <stdio.h>

struct perso your_race(struct perso perso1);


int main(void){
	struct perso you;
	your_race(you);
	printf("%s", you.race);


	return 0;
}

