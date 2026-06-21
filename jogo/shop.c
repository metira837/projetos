#include <stdio.h>
#include "shop.h"
#include <string.h>
#include <stdbool.h>


static bool check(char name[],struct perso *perso1, short int options){
	short int a = 3;
	bool ks = false;
	if(options == 1){
		for(; a > 0; a--){
			if((strcmp(name, perso1->attacks[a].name)) == 0){
				ks = true;
				break;
			}
				
		}
	}

	else{
		printf("binga");
	}
	return ks;		
	
	
}


static short int show_shop(short int options){
	short int a = 0;
	switch(options){
		case 1:
			printf("1-ball of wind(cost 30 money)\n2-ball of fire(cost 30 money)\n3-ball of water(cost 30 money)\n4-ball of earth(cost 30 money)\n"); scanf("%hd", &a);
			break;
		case 2:
			printf("1-healing Potion(cost 50 money)\n2-poison potion(cost 50 of money)"); scanf("%hd", &a);
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
	struct item itens1[2] = {{"poison potion", 1}, {"heal potion", 1}};


       	option:
		printf("select option that wants buy:\n1-moves 2-items\n3-quit of shop\n"); scanf("%hd", &options);
	
	switch(options)	{
		case 1:
			a = show_shop(options);
			if(a > 4){
				printf("no exist this option\n");
				goto option;
			}

			else if(money < 30)
				printf("necessary 30 of money");

			else if(check(skills[a-1].name, perso1, options)){
					printf("you has this skill\n");
			       }
					
				
			else{
				printf("you obtained the skill %s\n", skills[a-1].name);
				strcpy(perso1->attacks[1].name, skills[a-1].name);
				strcpy(perso1->attacks[1].type, skills[a-1].type);
				perso1->attacks[1].pp = skills[a-1].pp;
				perso1->money -= 30;
						
			}
			break;
		case 2:
			a = show_shop(options);
			if(a > 1){
				printf("this option not exist\n");
				goto option;
			}
			else if(money < 50)
				printf("necessary 50 of money");
			else{
				printf("you obtained the potion");
				perso1->money -= 50;
				strcpy(perso1->itens[1].name, itens1[a-1].name);
				perso1->itens[1].quantity += itens1[a-1].quantity;
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

