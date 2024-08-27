#ifndef FOOD_H
#define FOOD_H

#include "snake.h"
#include "SDL.h"
class Snake;


class Food{
    public:
    Food(int x, int y);

    //getter
    int GetPosX ()const;
    int GetPosY ()const;
    SDL_Point GetPosition ()const;

    virtual void ApplyEffect(Snake& snake) = 0;
    void Render(SDL_Rect &block, SDL_Renderer* sdl_renderer);

    protected:
    SDL_Point position;
    SDL_Color color;   
};

#endif