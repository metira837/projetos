#include <stdio.h>
#include <string.h>
#include "perso.h"

static void option(short int options, short int money, struct perso perso1){
	short int a; 
	char skills[4][19] = {"ball of wind", "ball of fire", "ball of water", "ball of earth"};
       

	switch(options)	{
		case 1:
			printf("1-ball of wind(cost 30 money)\n2-ball of fire(cost 30 money)\n3-ball of water(cost 30 money)\n4-ball of earth(cost 30 money)\n"); scanf("%hd", &a);
			if(money < 30)
				printf("necessary 30 of money");
			else{
				printf("you obtained the skill %s\n", skills[a]);
				strcpy(perso1.attacks[1].name, skills[a+1]);
				strcpy(perso1.attacks[1].type, "earth");
				perso1.attacks[1].pp = 25;
						
			}
			break;
		case 2:
			printf("1-healing Potion(cost 50 money)\n");
			if(money < 50)
				printf("necessary 50 of money");
			else{
				printf("you obtained the potion");
				
			}
			break;
		default:
			printf("this option not exist lol");
			break;
	}
	
	
}
void shop(short int money, struct perso perso1){
	short int options = 0;
	printf("welcome the shop\nyou has %d", money);
	printf("select option that wants buy:\n1-moves 2-items\n"); scanf("%hd", &options);
	option(options, money, perso1);	

}

