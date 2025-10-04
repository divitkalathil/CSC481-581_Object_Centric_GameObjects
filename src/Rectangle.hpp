#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GameObject.hpp"

class Rectangle : public GameObject {
public:
    Rectangle(float x, float y, float w, float h, SDL_Color color);

    void update(float dt, const bool* keyState) override;
    void render(SDL_Renderer* renderer) override;

private:
    SDL_FRect rect;
};

#endif // RECTANGLE_H