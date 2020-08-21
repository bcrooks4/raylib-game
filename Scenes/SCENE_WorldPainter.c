//
// Created by Bill on 20/08/2020.
//

#include "SCENE_WorldPainter.h"
#include "../Utility/Macro.h"


SCENE_METHOD SCENE_WorldPainter_Start() {
    SCENE_WORLD_PAINTER_Data *data = SceneData;

    for (int y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++) {
            data->map[y * data->width + x] = 0;
        }
    }

    data->camera = (Camera2D) {0};
    data->camera.zoom = 1;
    data->camera.target = (Vector2) {0, 0};
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WorldPainter_Update() {
    SCENE_WORLD_PAINTER_Data *data = SceneData;

    if (IsKeyDown(KEY_ESCAPE)) {
        ChangeScene(SCENE_WorldPainterMenu);
    }

    data->camera.offset.x = (float) GetScreenWidth() / 2;
    data->camera.offset.y = (float) GetScreenHeight() / 2;

    if (IsKeyDown(KEY_LEFT) || GetMouseX() < 20) {
        data->camera.target.x -= 5 * (6 - data->camera.zoom);
    }
    if (IsKeyDown(KEY_RIGHT) || GetMouseX() > GetScreenWidth() - 20) {
        data->camera.target.x += 5 * (6 - data->camera.zoom);
    }
    if (IsKeyDown(KEY_UP) || GetMouseY() < 20) {
        data->camera.target.y -= 5 * (6 - data->camera.zoom);
    }
    if (IsKeyDown(KEY_DOWN) || GetMouseY() > GetScreenHeight() - 20) {
        data->camera.target.y += 5 * (6 - data->camera.zoom);
    }

    if (GetMouseWheelMove() > 0) {
        data->camera.zoom += 0.05f;
    }
    if (GetMouseWheelMove() < 0) {
        data->camera.zoom -= 0.05f;
    }
    data->camera.zoom = CLAMP(data->camera.zoom, 0.1, 4.95);

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        int y;
        y = (int) (GetMouseY());
        int x;
        x = (int) (GetMouseX());

        int cameraPositionX = (int) (data->camera.target.x);
        int cameraPositionY = (int) (data->camera.target.y);

        int tileX;
        tileX = (int) (((float) x - data->camera.offset.x) / data->camera.zoom + (float) cameraPositionX) / 32;
        int tileY;
        tileY = (int) (((float) y - data->camera.offset.y) / data->camera.zoom + (float) cameraPositionY) / 32;

        if (tileX != (int) data->previousTile.x || tileY != (int) data->previousTile.y) {
            if (tileX >= 0 && tileX < data->width && tileY >= 0 && tileY < data->height) {
                data->map[tileY * data->width + tileX] = !data->map[tileY * data->width + tileX];
            }
            data->previousTile = (Vector2) {(float) tileX, (float) tileY};
        }
    }

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        data->previousTile = (Vector2) {-1, -1};
    }

    if (IsKeyPressed(KEY_ENTER)) {
        Color* pixels = GenerateVoronoiTexture(data->map, data->width, data->height, data->textureScale);

        Image image = {
                .data = pixels,
                .width = data->width * data->textureScale,
                .height = data->height * data->textureScale,
                .mipmaps = 1,
                .format = UNCOMPRESSED_R8G8B8A8
        };

        ExportImage(image, "out.png");

        UnloadImage(image);
        ChangeScene(SCENE_MapViewer);
    }

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WorldPainter_Render() {
    SCENE_WORLD_PAINTER_Data *data = SceneData;

    BeginMode2D(data->camera);

    for (int y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++) {
            Color colour = data->map[y * data->width + x] ? GREEN : BLUE;
            DrawRectangle(x * 32, y * 32, 32, 32, colour);
        }
    }

    EndMode2D();

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WorldPainter_Close() {
    SCENE_WORLD_PAINTER_Data *data = SceneData;
    free(data->map);
    return RETURN_SUCCESS;
}