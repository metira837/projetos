#include "raylib.h"
#include "raymath.h"
#define PLAYER_SPEED 10
#define PLAYER_SPEED_JUMP 200

struct perso{
	short int hp;
	Vector2 pos;
	short int damage;
	Texture2D texture;
	Vector2 attack;
	bool can_attack;
//	when player click on E attack go to left that represent how true 
// 	when player click on R attack go to right that represent how false 
	bool side;

};


void collision_attack_perso(struct perso *perso1,struct perso *enemy1, float radiusx, float radiusy,  Rectangle *recs, short int tamrec, Rectangle *battle, short int tambattle, bool start_battle);
void draw_rectangle(Rectangle rec[], int recLeght);
bool collision_attack(Rectangle rec[], int recLeght, Vector2 shoot);

int main(void){
	const int screenwidth = 1500, screenheight = 700;
	InitWindow(screenwidth, screenheight, "nada");

// 	declare the perso and enemy
	struct perso perso1 = {.hp = 100, .damage = 10, .pos = {screenwidth/2, screenheight/2-100}};
	perso1.can_attack = true;
	Image image_perso = LoadImage("ant.png");
	ImageResizeNN(&image_perso, 100, 100);
	perso1.texture = LoadTextureFromImage(image_perso);

	struct perso enemy1 = {.hp = 100, .damage = 10, .pos = {screenwidth+3000, screenheight/2-93}};	

	Image image_enemy = LoadImage("tatu.png");
	ImageResizeNN(&image_enemy, 100, 100);

	Image image_enemy_rage = LoadImage("taturage.png");
	ImageResizeNN(&image_enemy_rage, 100, 100);

	enemy1.texture = LoadTextureFromImage(image_enemy);
	enemy1.can_attack = true;
//	declare rectangle
	Rectangle recs[] =  {{0, screenheight/2, 5000, 1000}, {0, perso1.pos.y - 400, 3000, 300}, {0, -150, 50, 2000}};
	Rectangle battle[] = {{2800, 0, 200, 1000}, {5000, -100, 100, 1000}};
	short int tamrec = sizeof(recs) / sizeof(recs[0]);
	short int tambattle = sizeof(battle) / sizeof(battle[0]);

	bool start_battle = false;

//     	camera
	Camera2D ca = {0};
	ca.target = perso1.pos;
	ca.offset = (Vector2) {screenwidth/2, screenheight/2};
	ca.rotation = 0.0f;
	ca.zoom = 1.0f;


	SetTargetFPS(60);
	

	while(!WindowShouldClose()){
		if(IsKeyDown(KEY_R) && perso1.can_attack){		
			perso1.side = false;	
			perso1.can_attack = false;
			perso1.attack = (Vector2) {perso1.pos.x + 60, perso1.pos.y + 50};
			}
		if(IsKeyDown(KEY_E) && perso1.can_attack){
			perso1.side = true;	
			perso1.can_attack = false;		
			perso1.attack = (Vector2) {perso1.pos.x + 60, perso1.pos.y + 50};

		}

		if(IsKeyDown(KEY_D)) perso1.pos.x += PLAYER_SPEED; 

		if(IsKeyDown(KEY_W) && perso1.pos.y == screenheight/2-85) perso1.pos.y -= PLAYER_SPEED_JUMP;

		if(IsKeyDown(KEY_S)) perso1.pos.y += PLAYER_SPEED;

		if(IsKeyDown(KEY_A)) perso1.pos.x -= PLAYER_SPEED;


		if(CheckCollisionCircleRec(perso1.pos, 80.0f, recs[0])) perso1.pos.y  = screenheight/2 - 85;
		if(CheckCollisionCircleRec(perso1.pos, 10.0f, recs[1])) perso1.pos.y += 20;
		if(CheckCollisionCircleRec(perso1.pos, 10.0f, recs[2])) perso1.pos.x += 10;
		if(start_battle){
			if(CheckCollisionCircleRec(perso1.pos, 85.0f, battle[1])) perso1.pos.x -= 10;
			if(CheckCollisionCircleRec(perso1.pos, 3.0f, battle[0])) perso1.pos.x += 10; 	
		}

		
		if(perso1.can_attack == false){
			collision_attack_perso(&perso1, &enemy1, 43.0f, 35.0f, recs, tamrec, battle, tambattle, start_battle);	
		}	

		if(perso1.pos.x > recs[0].width || perso1.pos.x < 0 || perso1.pos.y != (screenheight/2) - 85) perso1.pos.y += 2;		
		if(perso1.pos.x > recs[1].width) start_battle = true;	

		if(start_battle){
			if(CheckCollisionCircleRec(perso1.pos, 85.0f, battle[1])) perso1.pos.x -= 10;
			if(CheckCollisionCircleRec(perso1.pos, 3.0f, battle[0])) perso1.pos.x += 10; 	
			if(perso1.pos.x < enemy1.pos.x) enemy1.pos.x -= 5;
		
			else  enemy1.pos.x += 5;	
			if(enemy1.can_attack){
				enemy1.attack = (Vector2)  {enemy1.pos.x -10, enemy1.pos.y + 40};

				if(perso1.pos.x < enemy1.pos.x) enemy1.side = true;
				else if(perso1.pos.x > enemy1.pos.x) enemy1.side = false;
				enemy1.can_attack = false;
		}
			if(enemy1.can_attack == false){
			if(enemy1.side == true) enemy1.attack.x -= 14;	
			else if(enemy1.side == false) enemy1.attack.x += 14;
			collision_attack_perso(&enemy1, &perso1, 43.0f,35.0f, recs, tamrec, battle, tambattle, start_battle);	

					
		
		}

			if(enemy1.hp <= 50){
				enemy1.texture = LoadTextureFromImage(image_enemy_rage);	
			}
		
		}
	
		ca.target = Vector2Lerp(ca.target, perso1.pos, 0.100f);

	
		BeginDrawing();
		  ClearBackground(RAYWHITE);	
		  BeginMode2D(ca);
		  	DrawTexture(perso1.texture, perso1.pos.x, perso1.pos.y, WHITE);
			DrawTexture(enemy1.texture, enemy1.pos.x, enemy1.pos.y, WHITE);
			DrawText("merda na chaleira", 500, 300, 50, DARKGRAY);
			draw_rectangle(recs, sizeof(recs) /  sizeof(recs[0]));		
			if(start_battle){
				draw_rectangle(battle, sizeof(battle) /  sizeof(battle[0]));		
		
			
			}
			if(perso1.can_attack == false) DrawCircleV(perso1.attack, 10.0f, YELLOW);
			if(enemy1.can_attack == false) DrawCircleV(enemy1.attack, 10.0f, YELLOW);

		 EndMode2D();	
		if(perso1.hp <= 0){
			ClearBackground(RAYWHITE);
			perso1.pos.x = 7000;		
			DrawText("you lose !", screenwidth/3 + 150, screenheight/2, 50, RED);		
				
		}
		if(enemy1.hp <= 0){
			ClearBackground(RAYWHITE);
			perso1.pos.x = 7000;		
			DrawText("you win !", screenwidth/3 + 150, screenheight/2, 50, GREEN);		
		}
		EndDrawing();
	}
	
	
	CloseWindow();
	return 0;

}



void draw_rectangle(Rectangle rec[], int recLeght){
	for(int a = 0; a < recLeght; a ++) DrawRectangleRec(rec[a], DARKGRAY);
}

bool collision_attack(Rectangle rec[], int recLeght, Vector2 shoot){
	bool collision = false;
	for(int a = 0; a < recLeght; a++){
		if(CheckCollisionCircleRec(shoot, 10.0f, rec[a])){
			collision = true;	
			break;	
		}	
		
	
	}
	return collision;

}
void collision_attack_perso(struct perso *perso1,struct perso *enemy1, float radiusx, float radiusy, Rectangle *recs, short int tamrec, Rectangle *battle, short int tambattle, bool start_battle){
		if(perso1->side) perso1->attack.x -= 14;	
		if(perso1->side == false) perso1->attack.x += 14;	

		if(collision_attack(recs, tamrec, perso1->attack)) perso1->can_attack = true;
			if(start_battle) {
				if(collision_attack(battle, tambattle, perso1->attack)) perso1->can_attack = true;
				if(CheckCollisionCircles(perso1->attack, radiusx, enemy1->pos, radiusy)) {
					perso1->can_attack = true;
					enemy1->hp -= 10;
					}
				}
		}

