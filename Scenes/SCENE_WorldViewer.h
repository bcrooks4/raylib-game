//
// Created by Bill on 27/08/2020.
//

#ifndef RAYLIB_GAME_SCENE_WORLDVIEWER_H
#define RAYLIB_GAME_SCENE_WORLDVIEWER_H

#include "../Engine/Engine.h"

SCENE_METHOD SCENE_WORLD_VIEWER_Start();
SCENE_METHOD SCENE_WORLD_VIEWER_Update();
SCENE_METHOD SCENE_WORLD_VIEWER_Render();
SCENE_METHOD SCENE_WORLD_VIEWER_Close();
typedef struct {
    Texture texture;
    int x;
    int y;
} GameCell;

typedef struct {
    Texture texture;
    Camera2D camera;
    Vector2 mapSize;
    GameCell *cells;
    int cellCount;
} SCENE_WORLD_VIEWER_Data;

#endif //RAYLIB_GAME_SCENE_WORLDVIEWER_H
