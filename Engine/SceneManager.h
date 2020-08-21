//
// Created by Bill on 20/08/2020.
//

#ifndef RAYLIB_GAME_SCENEMANAGER_H
#define RAYLIB_GAME_SCENEMANAGER_H

#include "Engine.h"
#include "../Scenes/SCENE_MainMenu.h"
#include "../Scenes/SCENE_SplashScreen.h"
#include "../Scenes/SCENE_Credits.h"
#include "../Scenes/SCENE_WorldPainter.h"
#include "../Scenes/SCENE_MapViewer.h"
#include "../Scenes/SCENE_NewWorldMenu.h"
#include "../Scenes/SCENE_WorldPainterMenu.h"
#include "../Scenes/SCENE_ProceduralWorldMenu.h"
#include "../Scenes/SCENE_BattleMap.h"

RESULT ChangeScene();

extern bool contextData;
extern void *SceneData;
SCENE_METHOD (*START_SCENE)     ();
SCENE_METHOD (*UPDATE_SCENE)    ();
SCENE_METHOD (*RENDER_SCENE)    ();
SCENE_METHOD (*CLOSE_SCENE)     ();

enum Scenes {
    SCENE_SplashScreen,
    SCENE_MainMenu,
    SCENE_Credits,
    SCENE_WorldPainter,
    SCENE_MapViewer,
    SCENE_NewWorldMenu,
    SCENE_WorldPainterMenu,
    SCENE_ProceduralWorldMenu,
    SCENE_BattleMap,
};

#endif //RAYLIB_GAME_SCENEMANAGER_H
