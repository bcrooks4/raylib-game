//
// Created by Bill on 20/08/2020.
//

#include "SCENE_Credits.h"

SCENE_METHOD SCENE_CREDITS_Start() {
    SceneData = malloc(sizeof(char));
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_CREDITS_Update() {
    if (IsKeyPressed(KEY_ESCAPE)) {
        ChangeScene(SCENE_MainMenu);
    }
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_CREDITS_Render() {
    const char* text1 = "Made by Bill Crooks";
    int x1 = GetScreenWidth() / 2 - MeasureText(text1, 64) / 2;
    int y1 = GetScreenHeight() / 2 - 64;

    const char* text2 = "Using the Raylib Engine";
    int x2 = GetScreenWidth() / 2 - MeasureText(text2, 64) / 2;
    int y2 = GetScreenHeight() / 2 + 64;

    DrawText(text1, x1, y1, 64, WHITE);
    DrawText(text2, x2, y2, 64, WHITE);

    DrawText("Press escape to go back",
             0, GetScreenHeight() - 42,
             32,
             (Color){50, 50, 50, 255});

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_CREDITS_Close() {
    return RETURN_SUCCESS;
}