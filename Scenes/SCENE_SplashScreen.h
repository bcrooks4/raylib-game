//
// Created by Bill on 20/08/2020.
//

#ifndef RAYLIB_GAME_SCENE_SPLASHSCREEN_H
#define RAYLIB_GAME_SCENE_SPLASHSCREEN_H

#include "../Engine/Engine.h"

SCENE_METHOD SCENE_SPLASH_Start();
SCENE_METHOD SCENE_SPLASH_Update();
SCENE_METHOD SCENE_SPLASH_Render();
SCENE_METHOD SCENE_SPLASH_Close();
typedef struct {
    int logoPositionX;
    int logoPositionY;
    int framesCounter;
    int lettersCount;
    int topSideRecWidth;
    int leftSideRecHeight;
    int bottomSideRecWidth;
    int rightSideRecHeight;
    int state;
    float alpha;
} SCENE_SPLASH_Data;

#endif //RAYLIB_GAME_SCENE_SPLASHSCREEN_H
