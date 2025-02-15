#pragma once
#include "raylib.h"
#include <math.h>
#include <stdbool.h>

typedef struct Rope {
  Vector2 position;
  int xVelocity;
  int yVelocity;
  bool drag;
  int radius;
  Color color;
  // Rope * previous;

} Rope;

float length(Vector2 vec) {
  return sqrtf((vec.x * vec.x) + (vec.y * vec.y));

}

float distance(Vector2 a, Vector2 b) {
  float x = (b.x - a.x) * (b.x - a.x);
  float y = (b.y - a.y) * (b.y - b.y);
  return sqrtf(x + y);
}

void calculateVelocity(Rope *tail, Rope *head) {

  Vector2 dir = (Vector2){.x = (tail->position.x - head->position.x),
                          .y = (tail->position.y - head->position.y)};
   float len = length(dir);
   if(len < 0.000001){
    dir = (Vector2){.x=1,.y=1};   
}else {
    dir.x /=len;
    dir.y /= len;
}
   
   Vector2 target;
   target.x = head->position.x + dir.x * 100;
   target.y = head->position.y + dir.y * 100;
    
  tail->xVelocity = (target.x - tail->position.x) * 0.05;
    tail->yVelocity = (target.y - tail->position.y) * 0.05;
    tail->position.x +=tail->xVelocity*0.016666667;
    tail->position.y += tail->yVelocity*0.016666667;
   
}
