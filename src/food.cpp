#include "food.h"

Food::Food(int x, int y): position({x, y}){};

//getter
int Food::GetPosX ()const {return position.x; }
int Food::GetPosY ()const {return position.y; }
SDL_Point Food::GetPosition ()const { return position; };

void Food::Render(SDL_Rect &block, SDL_Renderer* sdl_renderer){
    SDL_SetRenderDrawColor(sdl_renderer, color.r, color.g, color.b, color.a);
    block.x = position.x * block.w;
    block.y = position.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
};