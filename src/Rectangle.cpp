#include "Rectangle.hpp"

Rectangle::Rectangle(float x, float y, float w, float h, SDL_Color color) {
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = w;
    this->rect.h = h;
    this->color = color;
}

void Rectangle::update(float dt, const bool* keyState) {
    const float speed = 300.0f;

    if (keyState[SDL_SCANCODE_W]) {
        rect.y -= speed * dt;
    }
    if (keyState[SDL_SCANCODE_S]) {
        rect.y += speed * dt;
    }
    if (keyState[SDL_SCANCODE_A]) {
        rect.x -= speed * dt;
    }
    if (keyState[SDL_SCANCODE_D]) {
        rect.x += speed * dt;
    }

    if (rect.x < 0) rect.x = 0;
    if (rect.y < 0) rect.y = 0;
    if (rect.x + rect.w > 800) rect.x = 800 - rect.w;
    if (rect.y + rect.h > 600) rect.y = 600 - rect.h;
}

void Rectangle::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}