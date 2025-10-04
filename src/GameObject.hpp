#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL3/SDL.h>

class GameObject {
public:
    virtual ~GameObject() {}

    // The base class "contract" will  use const bool*
    virtual void update(float dt, const bool* keyState) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;

protected:
    float x = 0.0f, y = 0.0f;
    float vx = 0.0f, vy = 0.0f;
    SDL_Color color = {255, 255, 255, 255};
};

#endif // GAMEOBJECT_H