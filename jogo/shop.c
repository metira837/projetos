#include <stdio.h>
#include "perso.h"

static void option(short int options){

	switch(options)	{
		case 1:
			printf("1-ball of wind(cost 30 money)\n2-ball of fire(cost 30 money)\n3-ball of water(cost 30 money)\n4-ball of earth(cost 30 money)\n");
			break;
		case 2:
			printf("1-healing Potion(cost 50 money)\n");
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
	option(options);	

}

