//
// Created by Bill on 21/08/2020.
//

#include "SCENE_MapViewer.h"

SCENE_METHOD SCENE_MAP_VIEWER_Start() {
    SCENE_MAP_VIEWER_Data *data = malloc(sizeof(SCENE_MAP_VIEWER_Data));
    SceneData = data;

    data->texture = LoadTexture("out.png");
    data->camera = (Camera2D) {0};
    data->camera.zoom = 1;
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_MAP_VIEWER_Update() {
    SCENE_MAP_VIEWER_Data *data = SceneData;

    if (IsKeyPressed(KEY_ESCAPE)) {
        ChangeScene(SCENE_NewWorldMenu);
    }

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

    if (GetMouseWheelMove() > 0) {
        data->camera.zoom += 0.05f;
    }
    if (GetMouseWheelMove() < 0) {
        data->camera.zoom -= 0.05f;
    }
    data->camera.zoom = CLAMP(data->camera.zoom, 0.1, 4.95);
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_MAP_VIEWER_Render() {
    SCENE_MAP_VIEWER_Data *data = SceneData;
    BeginMode2D(data->camera);
    DrawTexture(data->texture, 0, 0, WHITE);
    EndMode2D();
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_MAP_VIEWER_Close() {
    SCENE_MAP_VIEWER_Data *data = SceneData;
    UnloadTexture(data->texture);
    return RETURN_SUCCESS;
}
