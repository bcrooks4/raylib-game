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

    printf("%d, %d", data->texture.width, data->texture.height);
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

    int y;
    y = (int) (GetMouseY());
    int x;
    x = (int) (GetMouseX());

    int cameraPositionX = (int) (data->camera.target.x);
    int cameraPositionY = (int) (data->camera.target.y);

    int pixelX;
    pixelX = (int) (((float) x - data->camera.offset.x) / data->camera.zoom + (float) cameraPositionX);
    int pixelY;
    pixelY = (int) (((float) y - data->camera.offset.y) / data->camera.zoom + (float) cameraPositionY);

    if (pixelX > 0 && pixelX < data->texture.width && pixelY > 0 && pixelY < data->texture.height) {
        DrawText(FormatText("On texture \n"
                            "X: %d \n"
                            "Y: %d", pixelX, pixelY), 0, 0, 32, WHITE);
    }
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_MAP_VIEWER_Close() {
    SCENE_MAP_VIEWER_Data *data = SceneData;
    UnloadTexture(data->texture);
    return RETURN_SUCCESS;
}
