#include <stdio.h>
#include "shop.h"
#include <string.h>



short int show_shop(short int options){
	short int a;
	switch(options){
		case 1:
			printf("1-ball of wind(cost 30 money)\n2-ball of fire(cost 30 money)\n3-ball of water(cost 30 money)\n4-ball of earth(cost 30 money)\n"); scanf("%hd", &a);
			break;
		case 2:
			printf("1-healing Potion(cost 50 money)\n"); scanf("%hd", &a);
			break;
		case 3:
			printf("leaving of shop...\n");
			break;
		default:
			printf("this option not exist lol\n");

			break;
	}
	return a;
}


static void option(short int money, struct perso *perso1){
	short int a, options; 
	struct attack skills[4] = {{20, "wind", 20, "ball of wind"}, {20, "fire", 20, "ball of fire"}, {20, "water", 20, "ball of water"}, {20,"earth", 20, "ball of earth"}};
       	option:
		printf("select option that wants buy:\n1-moves 2-items\n3-quit of shop\n"); scanf("%hd", &options);
	
	switch(options)	{
		case 1:
			a = show_shop(options);
			if(money < 30)
				printf("necessary 30 of money");
			else{
				printf("you obtained the skill %s\n", skills[a].name);
				strcpy(perso1->attacks[1].name, skills[a].name);
				strcpy(perso1->attacks[1].type, skills[a].type);
				perso1->attacks[1].pp = skills[a].pp;
						
			}
			break;
		case 2:
			a = show_shop(options);
			if(money < 50)
				printf("necessary 50 of money");
			else{
				printf("you obtained the potion");
				
			}
			break;
		case 3:
			a = show_shop(options);
			break;
		default:
			a = show_shop(options);
			goto option;
	}
	
	
}
void shop(short int money, struct perso *perso1){
	printf("welcome the shop\nyou has %d of money\n", money);
	option(money, perso1);	

}

