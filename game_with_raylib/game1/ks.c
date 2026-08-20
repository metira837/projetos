#include "raylib.h"
#include "raymath.h"
#define PLAYER_SPEED 10
#define PLAYER_SPEED_JUMP 200

void draw_rectangle(Rectangle rec[], int recLeght);

int main(void){
	const int screenwidth = 1500, screenheight = 700;
	Vector2 ball = {700, (screenheight/2)-50};
	InitWindow(screenwidth, screenheight, "nada");
	
	Rectangle recs[] =  {{0, screenheight/2, 5000, 1000}, {0, ball.y - 400, 3000, 300}, {0, -150, 50, 2000}};
	Rectangle battle[] = {{3000, 600, 2000, 300}, {5000, -100, 100, 1000}};
	bool start_battle = false;
	Camera2D ca = {0};
	ca.target = ball;
	ca.offset = (Vector2) {screenwidth/2, screenheight/2};
	ca.rotation = 0.0f;
	ca.zoom = 1.0f;


	SetTargetFPS(100);
	

	while(!WindowShouldClose()){

		if(IsKeyDown(KEY_D)) ball.x += PLAYER_SPEED; 

		if(IsKeyDown(KEY_W) && ball.y == screenheight/2-20) ball.y -= PLAYER_SPEED_JUMP;

		if(IsKeyDown(KEY_S)) ball.y += PLAYER_SPEED;

		if(IsKeyDown(KEY_A)) ball.x -= PLAYER_SPEED;


		if(CheckCollisionCircleRec(ball, 10.0f, recs[0])) ball.y = screenheight/2 - 20;
		if(CheckCollisionCircleRec(ball, 1.0f, recs[1])) ball.y += 100;
		if(CheckCollisionCircleRec(ball, 10.0f, recs[2])) ball.x = 70;
		if(CheckCollisionCircleRec(ball, 15.0f, battle[1])) ball.x -= 10;
	
		if(ball.x > recs[0].width || ball.x < 0 || ball.y != (screenheight/2) - 20) ball.y += 2;		
		if(ball.x > recs[1].width) start_battle = true;
		



		ca.target = Vector2Lerp(ca.target, ball, 0.100f);
	
		BeginDrawing();
		  ClearBackground(RAYWHITE);	
		  BeginMode2D(ca);
		  	DrawCircleV(ball, 20,  RED);
			DrawText("merda na chaleira", 500, 300, 50, DARKGRAY);
			draw_rectangle(recs, sizeof(recs) /  sizeof(recs[0]));		
			draw_rectangle(battle, sizeof(battle) /  sizeof(battle[0]));		


		 EndMode2D();	
		EndDrawing();
	
	
	}
	CloseWindow();
	return 0;


}

void draw_rectangle(Rectangle rec[], int recLeght){
	for(int a = 0; a < recLeght; a ++) DrawRectangleRec(rec[a], DARKGRAY);
}

