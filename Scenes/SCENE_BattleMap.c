//
// Created by Bill on 21/08/2020.
//

#include "SCENE_BattleMap.h"

SCENE_METHOD SCENE_BATTLE_MAP_Start() {
    SceneData = malloc(sizeof(SCENE_BATTLE_MAP_Data));
    SCENE_BATTLE_MAP_Data* data = SceneData;
    data->width = 64;
    data->height = 32;
    data->camera = (Camera2D){0};
    data->camera.zoom = 1;

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_BATTLE_MAP_Update() {
    SCENE_BATTLE_MAP_Data *data = SceneData;

    data->camera.offset.x = (float) GetScreenWidth() / 2;
    data->camera.offset.y = (float) GetScreenHeight() / 2;

    if (IsKeyDown(KEY_LEFT)) {
        data->camera.target.x -= 5 * (6 - data->camera.zoom);
    }
    if (IsKeyDown(KEY_RIGHT)) {
        data->camera.target.x += 5 * (6 - data->camera.zoom);
    }
    if (IsKeyDown(KEY_UP)) {
        data->camera.target.y -= 5 * (6 - data->camera.zoom);
    }
    if (IsKeyDown(KEY_DOWN)) {
        data->camera.target.y += 5 * (6 - data->camera.zoom);
    }
    data->camera.target.x = CLAMP(data->camera.target.x, 0, data->width * 32);
    data->camera.target.y = CLAMP(data->camera.target.y, 0, data->height * 32);

    if (GetMouseWheelMove() > 0) {
        data->camera.zoom += 0.05f;
    }
    if (GetMouseWheelMove() < 0) {
        data->camera.zoom -= 0.05f;
    }
    data->camera.zoom = CLAMP(data->camera.zoom, 0.6, 4.95);

    if (IsKeyPressed(KEY_ESCAPE)) {
        ChangeScene(SCENE_NewWorldMenu);
    }

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_BATTLE_MAP_Render() {
    SCENE_BATTLE_MAP_Data *data = SceneData;

    ClearBackground((Color){76, 156, 76, 255});

    BeginMode2D(data->camera);
    for (int i = 0, y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++, i++) {
            Color colour = (i + y) % 2 == 0 ? (Color){76, 156, 76, 255} : (Color){94, 181, 94, 255};
            DrawRectangle(x * 32, y * 32, 32, 32, colour);

            if (data->camera.zoom >= 1) {
                DrawRectangleLines(x * 32, y * 32, 32, 32, BLACK);
            }
        }
    }

    EndMode2D();

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_BATTLE_MAP_Close() {
    return RETURN_SUCCESS;
}