#include <stdio.h>
#include <string.h>
#include "enemy.h"
#include <time.h>
#include <stdlib.h>


void random_enemy(struct enemy *enemy1){
	char names[3][10] = {"goblin", "demon", "dog"};
	srand(time(NULL));
	short int number = rand() % 3;
	strcpy(enemy1->name, names[number]);		
}
