//
// Created by Bill on 21/08/2020.
//

#include "SCENE_WorldPainterMenu.h"

SCENE_METHOD SCENE_WORLD_PAINTER_MENU_START() {
    SceneData = malloc(sizeof(SCENE_WORLD_PAINTER_MENU_Data));
    SCENE_WORLD_PAINTER_MENU_Data *data = SceneData;
    data->cursorHighlight = 0;
    data->size = 1;
    data->scale = 2;
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_PAINTER_MENU_UPDATE() {
    SCENE_WORLD_PAINTER_MENU_Data *data = SceneData;

    if (IsKeyPressed(KEY_ESCAPE)) {
        ChangeScene(SCENE_NewWorldMenu);
    }

    if (IsKeyPressed(KEY_ENTER)) {
        switch (data->cursorHighlight) {
            case 0:
                data->size++;
                if (data->size > 2) {
                    data->size = 0;
                }
                break;
            case 1:
                data->scale++;
                if (data->scale > 2) {
                    data->scale = 0;
                }
                break;
            default:
                int size = data->size;
                int scale = data->scale;
                free(data);

                SCENE_WORLD_PAINTER_Data *cData = malloc(sizeof(SCENE_WORLD_PAINTER_Data));
                SceneData = cData;

                switch (size) {
                    case 0:
                        cData->width = 8;
                        cData->height = 8;
                        break;
                    case 1:
                        cData->width = 16;
                        cData->height = 16;
                        break;
                    case 2:
                        cData->width = 32;
                        cData->height = 32;
                        break;
                    default:
                        cData->width = 16;
                        cData->height = 16;
                        break;
                }

                switch (scale) {
                    case 0:
                        cData->textureScale = 8;
                        break;
                    case 1:
                        cData->textureScale = 16;
                        break;
                    case 2:
                        cData->textureScale = 24;
                        break;
                    default:
                        cData->textureScale = 16;
                        break;
                }

                cData->map = malloc(sizeof(int) * cData->width * cData->height);

                contextData = true;
                ChangeScene(SCENE_WorldPainter);
                return RETURN_SUCCESS;
        }
    }

    if (IsKeyPressed(KEY_DOWN)) {
        data->cursorHighlight++;
    } else if (IsKeyPressed(KEY_UP)) {
        data->cursorHighlight--;
    }
    data->cursorHighlight = CLAMP(data->cursorHighlight, 0, 2);

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_PAINTER_MENU_RENDER() {
    SCENE_WORLD_PAINTER_MENU_Data *data = SceneData;
    DrawRectangleLinesEx((Rectangle) {
                                 16,
                                 120,
                                 (float) GetScreenWidth() - 32,
                                 (float) GetScreenHeight() - (120 + 16)
                         }, 2, WHITE
    );
    DrawText("WORLD PAINTER", 16, 32, 64, WHITE);

    for (int i = 0; i < 3; i++) {
        Color textColour = data->cursorHighlight == i ? WHITE : (Color) {50, 50, 50, 255};
        switch (i) {
            case 0:
                if (1) {
                    const char *text;
                    switch (data->size) {
                        case 0:
                            text = "Size small";
                            break;
                        case 1:
                            text = "Size medium";
                            break;
                        case 2:
                            text = "Size large";
                            break;
                    }
                    DrawText(text, 32, 128 + i * 32, 32, textColour);
                }
                break;
            case 1:
                if (1) {
                    const char *text;
                    switch (data->scale) {
                        case 0:
                            text = "Scale small";
                            break;
                        case 1:
                            text = "Scale medium";
                            break;
                        case 2:
                            text = "Scale large";
                            break;
                    }
                    DrawText(text, 32, 128 + i * 32, 32, textColour);
                }
                break;
            case 2:
                DrawText("Finish", 32, 128 + i * 32, 32, textColour);
                break;
        }
    }
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_PAINTER_MENU_CLOSE() {
    return RETURN_SUCCESS;
}
