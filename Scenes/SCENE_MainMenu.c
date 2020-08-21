//
// Created by Bill on 20/08/2020.
//

#include "SCENE_MainMenu.h"

SCENE_METHOD SCENE_MAIN_MENU_Start() {
    SCENE_MAIN_MENU_Data *data = (SCENE_MAIN_MENU_Data *) malloc(sizeof(SCENE_MAIN_MENU_Data));
    SceneData = data;
    data->cursorHighlight = 0;
    data->alpha = 0.0f;
    data->mouseMoved = false;
    data->mousePreviousPosition = GetMousePosition();

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_MAIN_MENU_Update() {
    SCENE_MAIN_MENU_Data* data = SceneData;

    data->alpha += 0.025f;
    if (data->alpha > 1) data->alpha = 1;

    data->mouseMoved = GetMousePosition().x != data->mousePreviousPosition.x ||
                       GetMousePosition().y != data->mousePreviousPosition.y;
    if (data->mouseMoved && GetScreenHeight() - GetMouseY() < 4 * 64 &&
        (float) GetMouseX() / (float) GetScreenWidth() > 0.75f) {
        data->cursorHighlight = 3 - (int) ((GetScreenHeight() - GetMouseY()) / 64);
    }

    if (IsKeyPressed(KEY_DOWN)) {
        data->cursorHighlight++;
    }
    else if (IsKeyPressed(KEY_UP)) {
        data->cursorHighlight--;
    }

    if (data->cursorHighlight > 3) {
        data->cursorHighlight = 3;
    }
    else if (data->cursorHighlight < 0) {
        data->cursorHighlight = 0;
    }

    if (IsKeyPressed(KEY_R)) {
        ChangeScene(SCENE_SplashScreen);
    }

    if (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        switch (data->cursorHighlight) {
            case 0:         // Play
                ChangeScene(SCENE_NewWorldMenu);
                break;
            case 1:         // Options
                break;
            case 2:         // Credits
                ChangeScene(SCENE_Credits);
                break;
            case 3:         // Quit
                Close();
                break;
        }
    }

    data->mousePreviousPosition = GetMousePosition();
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_MAIN_MENU_Render() {
    SCENE_MAIN_MENU_Data* data = SceneData;

    for (int i = 0; i < 4; i++) {

        const char* text;
        int x, y;

        switch (i) {
            case 0:
                text = "Quit";
                y = GetScreenHeight() - 64 * 1;
                break;
            case 1:
                text = "Credits";
                y = GetScreenHeight() - 64 * 2;
                break;
            case 2:
                text = "Options";
                y = GetScreenHeight() - 64 * 3;
                break;
            case 3:
                text = "Play";
                y = GetScreenHeight() - 64 * 4;
                break;
        }

        x = GetScreenWidth() - MeasureText(text, 64);
        Color drawColour = 3 - data->cursorHighlight == i ? WHITE : (Color) {50, 50, 50, 255};
        if (3 - data->cursorHighlight == i) {
            x -= 32;
        }
        DrawText(text, x, y, 64, Fade(drawColour, data->alpha));
    }

    DrawText("v0.1a", 0, GetScreenHeight() - 32, 32, (Color){50, 50, 50, 255});
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_MAIN_MENU_Close() {
    return RETURN_SUCCESS;
}

