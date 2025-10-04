#include <SDL3/SDL.h>
#include <vector>
#include <memory>

#include "GameObject.hpp"
#include "Rectangle.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Object-Centric Demo", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    if (!window) {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    std::vector<std::unique_ptr<GameObject>> gameObjects;

    gameObjects.emplace_back(std::make_unique<Rectangle>(100.0f, 100.0f, 50.0f, 50.0f, SDL_Color{255, 0, 0, 255}));

    // --- Game Loop ---
    bool running = true;
    Uint64 lastFrameTime = SDL_GetPerformanceCounter();

    while (running) {
        Uint64 currentFrameTime = SDL_GetPerformanceCounter();
        float deltaTime = (float)(currentFrameTime - lastFrameTime) / (float)SDL_GetPerformanceFrequency();
        lastFrameTime = currentFrameTime;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.key == SDLK_ESCAPE) {
                    running = false;
                }
            }
        }

        const bool* keyState = SDL_GetKeyboardState(NULL);

        for (const auto& obj : gameObjects) {
            obj->update(deltaTime, keyState);
        }

        // --- Render ---
        SDL_SetRenderDrawColor(renderer, 20, 20, 40, 255);
        SDL_RenderClear(renderer);

        for (const auto& obj : gameObjects) {
            obj->render(renderer);
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}