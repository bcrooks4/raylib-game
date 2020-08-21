//
// Created by Bill on 21/08/2020.
//

#include "SCENE_ProceduralWorldMenu.h"

SCENE_METHOD SCENE_PROCEDURAL_WORLD_MENU_START() {
    SceneData = malloc(sizeof(SCENE_PROCEDURAL_WORLD_MENU_Data));
    SCENE_PROCEDURAL_WORLD_MENU_Data *data = SceneData;
    data->cursorHighlight = 0;
    data->size = 1;
    data->scale = 1;
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_PROCEDURAL_WORLD_MENU_UPDATE() {
    SCENE_PROCEDURAL_WORLD_MENU_Data *data = SceneData;

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
                int width;
                int height;
                int scale;

                switch (data->size) {
                    case 0:
                        width = 8;
                        height = 8;
                        break;
                    case 1:
                        width = 16;
                        height = 16;
                        break;
                    case 2:
                        width = 32;
                        height = 32;
                        break;
                    default:
                        width = 16;
                        height = 16;
                        break;
                }

                switch (data->scale) {
                    case 0:
                        scale = 4;
                        break;
                    case 1:
                        scale = 4;
                        break;
                    case 2:
                        scale = 8;
                        break;
                    default:
                        scale = 16;
                        break;
                }

                int* map = malloc(width * height * sizeof(int));
                for (int y = 0; y < height; y++) {
                    for (int x = 0; x < width; x++) {
                        if (x <= 1 || y <= 1 || x >= width - 2 || y >= height - 2) {
                            map[y * width + x] = 0;
                        }
                        else {
                            map[y * width + x] = rand() % 2;
                        }
                    }
                }

                Color* pixels = GenerateVoronoiTexture(map, width, height, scale);
                Image image = (Image) {
                        .data = pixels,
                        .width = width * scale,
                        .height = height * scale,
                        .mipmaps = 1,
                        .format = UNCOMPRESSED_R8G8B8A8,
                };

                ExportImage(image, "out.png");

                ChangeScene(SCENE_MapViewer);

                break;
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

SCENE_METHOD SCENE_PROCEDURAL_WORLD_MENU_RENDER() {
    SCENE_PROCEDURAL_WORLD_MENU_Data *data = SceneData;
    DrawRectangleLinesEx((Rectangle) {
                                 16,
                                 120,
                                 (float) GetScreenWidth() - 32,
                                 (float) GetScreenHeight() - (120 + 16)
                         }, 2, WHITE
    );
    DrawText("PROCEDURAL WORLD", 16, 32, 64, WHITE);

    for (int i = 0; i < 3; i++) {
        Color textColour = data->cursorHighlight == i ? WHITE : (Color){50, 50, 50, 255};
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
                DrawText("Generate", 32, 128 + i * 32, 32, textColour);
                break;
        }
    }
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_PROCEDURAL_WORLD_MENU_CLOSE() {
    return RETURN_SUCCESS;
}
