//
// Created by Bill on 20/08/2020.
//

#ifndef RAYLIB_GAME_SCENE_MAINMENU_H
#define RAYLIB_GAME_SCENE_MAINMENU_H

#include "../Engine/Engine.h"

SCENE_METHOD SCENE_MAIN_MENU_Start();
SCENE_METHOD SCENE_MAIN_MENU_Update();
SCENE_METHOD SCENE_MAIN_MENU_Render();
SCENE_METHOD SCENE_MAIN_MENU_Close();
typedef struct {
    int cursorHighlight;
    Vector2 mousePreviousPosition;
    bool mouseMoved;
    float alpha;
} SCENE_MAIN_MENU_Data;

#endif //RAYLIB_GAME_SCENE_MAINMENU_H
