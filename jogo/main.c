#include "perso.h"
#include "enemy.h"
#include <stdio.h>

void your_race(struct perso *perso1);


int main(void){
	struct perso you;
	printf("what is your name?\n"); scanf("%s", &you.name);
	printf("welcome, %s\n", you.name);
	your_race(&you);		
	
	return 0;
}

