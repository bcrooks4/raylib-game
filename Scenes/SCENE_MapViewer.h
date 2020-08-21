//
// Created by Bill on 21/08/2020.
//

#ifndef RAYLIB_GAME_SCENE_MAPVIEWER_H
#define RAYLIB_GAME_SCENE_MAPVIEWER_H

#include "../Engine/Engine.h"

SCENE_METHOD SCENE_MAP_VIEWER_Start();
SCENE_METHOD SCENE_MAP_VIEWER_Update();
SCENE_METHOD SCENE_MAP_VIEWER_Render();
SCENE_METHOD SCENE_MAP_VIEWER_Close();
typedef struct {
    Texture texture;
    Camera2D camera;
} SCENE_MAP_VIEWER_Data;

#endif //RAYLIB_GAME_SCENE_MAPVIEWER_H
