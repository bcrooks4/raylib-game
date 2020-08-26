//
// Created by Bill on 20/08/2020.
//

#include "Engine.h"

RESULT Initialise() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1200, 800, "");
    SetTargetFPS(60);
    SetExitKey(0);
    return RETURN_SUCCESS;
}

RESULT Update() {
    if (UPDATE_SCENE) {
        if ((*UPDATE_SCENE)()) {
            printf("\n\nError in update function!\n\n");
            Close();
        }
    }
    SetWindowTitle(TextFormat("%d FPS", GetFPS()));
    if (IsKeyPressed(KEY_F)) {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_UNDECORATED);
        CloseWindow();
        InitWindow(GetMonitorWidth(0), GetMonitorWidth(0), "");
        SetExitKey(0);
        SetTargetFPS(60);
    }
    return RETURN_SUCCESS;
}

RESULT Draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    if (RENDER_SCENE) {
        if ((*RENDER_SCENE)()) {
            Close();
        }
    }
    EndDrawing();
    return RETURN_SUCCESS;
}

RESULT Close() {
    if (CLOSE_SCENE) {
        (*CLOSE_SCENE)();
    }
    CloseWindow();
    return RETURN_SUCCESS;
}
