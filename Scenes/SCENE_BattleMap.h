//
// Created by Bill on 21/08/2020.
//

#ifndef RAYLIB_GAME_SCENE_BATTLEMAP_H
#define RAYLIB_GAME_SCENE_BATTLEMAP_H

#include "../Engine/Engine.h"

SCENE_METHOD SCENE_BATTLE_MAP_Start();
SCENE_METHOD SCENE_BATTLE_MAP_Update();
SCENE_METHOD SCENE_BATTLE_MAP_Render();
SCENE_METHOD SCENE_BATTLE_MAP_Close();
typedef struct {
    int width;
    int height;
    Camera2D camera;
} SCENE_BATTLE_MAP_Data;

#endif //RAYLIB_GAME_SCENE_BATTLEMAP_H
