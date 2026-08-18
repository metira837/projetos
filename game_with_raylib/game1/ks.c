#include "raylib.h"
#include <stdlib.h>

int main(void){
	const int screenwidth = 1500, screenheight = 700;
	short int jump = 0;
	Vector2 ball = {700, (screenheight/2)-50};
	InitWindow(screenwidth, screenheight, "nada");
	
	Rectangle recs[] =  {{0, screenheight/2, 5000, 1000}, {0, ball.y - 400, 5000, 300}, {-500, -150, 500, 2000}};


	Camera2D ca = {0};
	ca.target = ball;
	ca.offset = (Vector2) {screenwidth/2, screenheight/2};
	ca.rotation = 0.0f;
	ca.zoom = 1.5f;

	SetTargetFPS(60);
	

	while(!WindowShouldClose()){
		float deltatime = GetFrameTime();
		if(IsKeyDown(KEY_D)){
			ball.x += 10; 
		}
		if(IsKeyDown(KEY_W) && ball.y == (screenheight / 2) - 20){
			ball.y += -50;
		}
		if(IsKeyDown(KEY_S)){
			ball.y += 10;
		}
		if(IsKeyDown(KEY_A)){
			ball.x -= 10;
		
		}
		if(CheckCollisionCircleRec(ball, 10.0f, recs[0])){
			ball.y = (screenheight/2) - 20;
		}
	
		if(ball.x > recs[0].width || ball.x < 0 || ball.y != (screenheight/2) - 20){
				ball.y += 1;		
		
		}
		ca.target = ball;
			
		BeginDrawing();
		  ClearBackground(RAYWHITE);	
		  BeginMode2D(ca);
		  	DrawCircleV(ball, 20,  RED);
			DrawText("merda na chaleira", 500, 300, 50, DARKGRAY);
			for(int a = 0; a < sizeof(recs) / sizeof(recs[1]); a++) DrawRectangleRec(recs[a], DARKGRAY);

		  EndMode2D();	

		EndDrawing();
	
	
	}
	CloseWindow();
	return 0;


}
