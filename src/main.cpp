#include "include/includes.hpp"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Todo App");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(COLOR_BACKGROUND);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
