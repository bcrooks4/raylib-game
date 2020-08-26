//
// Created by Bill on 21/08/2020.
//

#include "SCENE_NewWorldMenu.h"


SCENE_METHOD SCENE_NEW_WORLD_MENU_START() {
    SceneData = malloc(sizeof(SCENE_NEW_WORLD_MENU_Data));
    SCENE_NEW_WORLD_MENU_Data *data = SceneData;
    data->cursorHighlight = 0;
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_NEW_WORLD_MENU_UPDATE() {
    SCENE_NEW_WORLD_MENU_Data *data = SceneData;

    if (IsKeyPressed(KEY_ESCAPE)) {
        ChangeScene(SCENE_MainMenu);
    }

    if (IsKeyPressed(KEY_ENTER)) {
        switch (data->cursorHighlight) {
            case 0:
                ChangeScene(SCENE_WorldPainterMenu);
                break;
            case 1:
                ChangeScene(SCENE_ProceduralWorldMenu);
                break;
            case 2:
                ChangeScene(SCENE_BattleMap);
                break;
            case 3:
                break;
        }
    }

    if (IsKeyPressed(KEY_DOWN)) {
        data->cursorHighlight++;
    } else if (IsKeyPressed(KEY_UP)) {
        data->cursorHighlight--;
    }
    if (data->cursorHighlight > 3)
        data->cursorHighlight = 0;
    else if (data->cursorHighlight < 0)
        data->cursorHighlight = 3;
    data->cursorHighlight = CLAMP(data->cursorHighlight, 0, 3);

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_NEW_WORLD_MENU_RENDER() {
    SCENE_NEW_WORLD_MENU_Data *data = SceneData;
    DrawRectangleLinesEx((Rectangle) {
                                 16,
                                 120,
                                 (float) GetScreenWidth() - 32,
                                 (float) GetScreenHeight() - (120 + 16)
                         }, 2, WHITE
    );
    DrawText("NEW WORLD", 16, 32, 64, WHITE);

    for (int i = 0; i < 4; i++) {
        Color textColour = data->cursorHighlight == i ? WHITE : (Color) {50, 50, 50, 255};
        switch (i) {
            case 0:
                DrawText("World Painter", 32, 128, 32, textColour);
                break;
            case 1:
                DrawText("Procedural [Slightly Broken ATM]", 32, 128 + i * 32, 32, textColour);
                break;
            case 2:
                DrawText("Battle Map", 32, 128 + i * 32, 32, textColour);
                break;
            case 3:
                DrawText("New World Creation [WIP]", 32, 128 + i * 32, 32, textColour);
                break;
        }
    }
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_NEW_WORLD_MENU_CLOSE() {
    return RETURN_SUCCESS;
}
