#include "raylib.h"
#include "raymath.h"
#define PLAYER_SPEED 10
#define PLAYER_SPEED_JUMP 200

struct perso{
	short int hp;
	Vector2 pos;
	short int damage;
	Image texture;
};
struct enemy{
	short int hp;
	Vector2 pos;
	short int damage;
	Image texture;
};


void draw_rectangle(Rectangle rec[], int recLeght);

int main(void){
	const int screenwidth = 1500, screenheight = 700;
	InitWindow(screenwidth, screenheight, "nada");

// 	declare the perso and enemy
	struct perso perso1 = {.hp = 100, .damage = 10, .pos = {screenwidth/2-50, screenheight/2}};
	struct enemy enemy1;

//	declare rectangle
	Rectangle recs[] =  {{0, screenheight/2, 5000, 1000}, {0, perso1.pos.y - 400, 3000, 300}, {0, -150, 50, 2000}};
	Rectangle battle[] = {{2800, 0, 200, 1000}, {5000, -100, 100, 1000}};

	bool start_battle = false;

//     camera
	Camera2D ca = {0};
	ca.target = perso1.pos;
	ca.offset = (Vector2) {screenwidth/2, screenheight/2};
	ca.rotation = 0.0f;
	ca.zoom = 1.0f;


	SetTargetFPS(60);
	

	while(!WindowShouldClose()){

		if(IsKeyDown(KEY_D)) perso1.pos.x += PLAYER_SPEED; 

		if(IsKeyDown(KEY_W) && perso1.pos.y == screenheight/2-20) perso1.pos.y -= PLAYER_SPEED_JUMP;

		if(IsKeyDown(KEY_S)) perso1.pos.y += PLAYER_SPEED;

		if(IsKeyDown(KEY_A)) perso1.pos.x -= PLAYER_SPEED;


		if(CheckCollisionCircleRec(perso1.pos, 10.0f, recs[0])) perso1.pos.y  = screenheight/2 - 20;
		if(CheckCollisionCircleRec(perso1.pos, 10.0f, recs[1])) perso1.pos.y += 20;
		if(CheckCollisionCircleRec(perso1.pos, 10.0f, recs[2])) perso1.pos.x += 10;
		if(start_battle){
			if(CheckCollisionCircleRec(perso1.pos, 15.0f, battle[1])) perso1.pos.x -= 10;
			if(CheckCollisionCircleRec(perso1.pos, 15.0f, battle[0])) perso1.pos.x += 10; 	
		
		}
		
		if(perso1.pos.x > recs[0].width || perso1.pos.x < 0 || perso1.pos.y != (screenheight/2) - 20) perso1.pos.y += 2;		
		if(perso1.pos.x > recs[1].width) start_battle = true;	
		
		ca.target = Vector2Lerp(ca.target, perso1.pos, 0.100f);
	
		BeginDrawing();
		  ClearBackground(RAYWHITE);	
		  BeginMode2D(ca);
		  	DrawCircleV(perso1.pos, 20,  RED);
			DrawText("merda na chaleira", 500, 300, 50, DARKGRAY);
			draw_rectangle(recs, sizeof(recs) /  sizeof(recs[0]));		
			if(start_battle){
				draw_rectangle(battle, sizeof(battle) /  sizeof(battle[0]));		
		
			
			}

		 EndMode2D();	
		EndDrawing();
	
	
	}
	CloseWindow();
	return 0;


}

void draw_rectangle(Rectangle rec[], int recLeght){
	for(int a = 0; a < recLeght; a ++) DrawRectangleRec(rec[a], DARKGRAY);
}

