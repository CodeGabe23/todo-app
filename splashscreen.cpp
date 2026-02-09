#include <iostream>
#include <raylib.h>
#include "src/include/designElements.hpp"

int main()
{

	InitWindow(, SCREEN_WIDTH, "To Do List");

	Vector2 mouseCursorPoint = GetMousePosition();
	Texture2D NewListBounds = { };

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		DrawText("To Do App", 300, 50, 35, BLACK);

		// Area for "New to do list" button
		DrawRectangle(250, 150, 150, 150, BLACK);
        DrawText("New To Do List", 220, 150, 25, WHITE);

		// Check for mouse collisions on the new to do list button Area
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			std::cout << "mouse left button clickaricked\n";
			// TODO: check for cursor bounds 
			mouseCursorPoint = GetMousePosition();

			if (mouseCursorPoint > )

		}

        EndDrawing();
	}
}
