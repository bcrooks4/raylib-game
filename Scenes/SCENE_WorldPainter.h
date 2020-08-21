//
// Created by Bill on 20/08/2020.
//

#ifndef RAYLIB_GAME_SCENE_WORLDPAINTER_H
#define RAYLIB_GAME_SCENE_WORLDPAINTER_H

#include "../Engine/Engine.h"

SCENE_METHOD SCENE_WorldPainter_Start();
SCENE_METHOD SCENE_WorldPainter_Update();
SCENE_METHOD SCENE_WorldPainter_Render();
SCENE_METHOD SCENE_WorldPainter_Close();
typedef struct {
    int *map;
    int width;
    int height;
    int textureScale;
    Camera2D camera;
    Vector2 previousTile;
} SCENE_WORLD_PAINTER_Data;

#endif //RAYLIB_GAME_SCENE_WORLDPAINTER_H
