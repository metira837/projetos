#include "raylib.h"


int main(void){
	const int screenwidth = 1500, screenheight = 700;
	Vector2 ball = {700, (screenheight/2)-50};
	Rectangle rec = {0, screenheight/2, 5000, 1000};
	InitWindow(screenwidth, screenheight, "nada");

	Camera2D ca = {0};
	ca.target = (Vector2) {ball.x + 20.0f, ball.y + 20.0f};
	ca.offset = (Vector2) {screenwidth/2, screenheight/2};
	ca.rotation = 0.0f;
	ca.zoom = 1.0f;

	SetTargetFPS(60);


	while(!WindowShouldClose()){
		if(IsKeyDown(KEY_D)){
			ball.x += 10;
		}
		if(IsKeyDown(KEY_W)){
			ball.y -= 10;	
		}
		if(IsKeyDown(KEY_S)){
			ball.y += 10;
		}
		if(IsKeyDown(KEY_A)){
			ball.x -= 10;
		
		}
		if(CheckCollisionCircleRec(ball, 10.0f, rec)){
			ball.y = (screenheight/2) - 20;
		}
	
		if(ball.x > rec.width || ball.x < 0 || ball.y != (screenheight/2) - 20){
				ball.y += 5;
		
		}

		ca.target = (Vector2) {ball.x + 10, ball.y + 10};
			
		BeginDrawing();
		  ClearBackground(RAYWHITE);	
		  BeginMode2D(ca);
			DrawCircleV(ball, 20,  RED);
			DrawRectangleRec(rec, DARKGRAY);
			DrawText("merda na chaleira", 500, 300, 50, DARKGRAY);
			

		  EndMode2D();	
		  
		EndDrawing();
	
	
	}
	CloseWindow();
	return 0;


}
