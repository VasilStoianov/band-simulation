#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "player.h"

typedef struct Mouse{
    Vector2 position;
    bool leftClicked;
} Mouse;



void handleInput(Mouse * mouse);
int checkMousePosition(int mouseX, int mouseY,Rope * rope, Rope * secRope,bool mouseClicked);


int mouseX;
int mouseY;
int main(){

   InitWindow(800,800,"Test Window");
int key;
  Rope rope = {
  .drag = 0,
  .radius = 24,
  .position = (Vector2){.x = 120,.y = 120},
  .xVelocity = 0,
  .yVelocity = 0,
  .color = YELLOW
};
 Rope secRope = {
  .drag = 0,
  .radius = 24,
  .position = (Vector2){.x = 220,.y = 220},
  .xVelocity = 0,
  .yVelocity = 0,
  .color = YELLOW
};

Mouse mouse =  {
    .position = (Vector2){.x = 0,.y = 0},
    .leftClicked = false
};

while (!WindowShouldClose())
{

 mouseX = GetMouseX();
 mouseY = GetMouseY();
    ClearBackground(BLACK);
   BeginDrawing();
   DrawLineEx((Vector2){.x =rope.position.x,.y=rope.position.y},(Vector2){.x=secRope.position.x ,.y=secRope.position.y},15.f ,RED);

   if(mouse.leftClicked){
    checkMousePosition(mouseX,mouseY,&rope,&secRope,mouse.leftClicked);

   }
   if(rope.drag){
     rope.position.x = mouseX;
     rope.position.y = mouseY;
   }
   calculateVelocity(&secRope,&rope);
 
   DrawCircleV(rope.position,rope.radius,rope.color);
   DrawCircleV(secRope.position,secRope.radius,secRope.color);
   EndDrawing();

 handleInput(&mouse);
} 
    return 1;
}


int checkMousePosition(int mouseX, int mouseY,Rope * rope, Rope * secRope,bool mouseClicked){
    if(mouseX <= rope->position.x+rope->radius && mouseX >=rope->position.x - rope->radius
    &&
     mouseY >= rope->position.y - rope->radius && mouseY <= rope->position.y + rope->radius
     && mouseClicked
    ){
        rope->drag = !rope->drag;
    }
}


void handleInput(Mouse * mouse){
    
   bool key = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
     if(key){
      mouse->leftClicked = !mouse->leftClicked;
      
     }

}