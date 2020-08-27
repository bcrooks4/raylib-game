//
// Created by Bill on 27/08/2020.
//

#include "SCENE_WorldViewer.h"


SCENE_METHOD SCENE_WORLD_VIEWER_Start() {
    printf("\n\nBRU\n\n");
    SCENE_WORLD_VIEWER_Data *data = malloc(sizeof(SCENE_WORLD_VIEWER_Data));
    SceneData = data;
    data->camera = (Camera2D) {0};
    data->camera.zoom = 1;
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_VIEWER_Update() {
    printf("Start update");
    SCENE_WORLD_VIEWER_Data *data = SceneData;

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

    printf("Finished update");
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_VIEWER_Render() {
    SCENE_WORLD_VIEWER_Data *data = SceneData;

    BeginMode2D(data->camera);
    DrawRectangle(0, 0, 128, 128, WHITE);

    EndMode2D();
    printf("Finished rendering");
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_VIEWER_Close() {

    return RETURN_SUCCESS;
}