//
// Created by Bill on 20/08/2020.
//
#include "Engine.h"

bool contextData = false;
bool sceneChanged = false;
SCENE currentScene = -1;
void* SceneData = 0;

RESULT ChangeScene(SCENE scene) {
    if (CLOSE_SCENE) {
        if ((*CLOSE_SCENE)()) {
            Close();
        }
    }

    sceneChanged = true;
    currentScene = scene;

    switch (scene) {
        case SCENE_SplashScreen:
            START_SCENE = SCENE_SPLASH_Start;
            UPDATE_SCENE = SCENE_SPLASH_Update;
            RENDER_SCENE = SCENE_SPLASH_Render;
            CLOSE_SCENE = SCENE_SPLASH_Close;
            break;
        case SCENE_MainMenu:
            START_SCENE = SCENE_MAIN_MENU_Start;
            UPDATE_SCENE = SCENE_MAIN_MENU_Update;
            RENDER_SCENE = SCENE_MAIN_MENU_Render;
            CLOSE_SCENE = SCENE_MAIN_MENU_Close;
            break;
        case SCENE_Credits:
            START_SCENE = SCENE_CREDITS_Start;
            UPDATE_SCENE = SCENE_CREDITS_Update;
            RENDER_SCENE = SCENE_CREDITS_Render;
            CLOSE_SCENE = SCENE_CREDITS_Close;
            break;
        case SCENE_WorldPainter:
            START_SCENE = SCENE_WorldPainter_Start;
            UPDATE_SCENE = SCENE_WorldPainter_Update;
            RENDER_SCENE = SCENE_WorldPainter_Render;
            CLOSE_SCENE = SCENE_WorldPainter_Close;
            break;
        case SCENE_MapViewer:
            START_SCENE = SCENE_MAP_VIEWER_Start;
            UPDATE_SCENE = SCENE_MAP_VIEWER_Update;
            RENDER_SCENE = SCENE_MAP_VIEWER_Render;
            CLOSE_SCENE = SCENE_MAP_VIEWER_Close;
            break;
        case SCENE_NewWorldMenu:
            START_SCENE = SCENE_NEW_WORLD_MENU_START;
            UPDATE_SCENE = SCENE_NEW_WORLD_MENU_UPDATE;
            RENDER_SCENE = SCENE_NEW_WORLD_MENU_RENDER;
            CLOSE_SCENE = SCENE_NEW_WORLD_MENU_CLOSE;
            break;
        case SCENE_WorldPainterMenu:
            START_SCENE = SCENE_WORLD_PAINTER_MENU_START;
            UPDATE_SCENE = SCENE_WORLD_PAINTER_MENU_UPDATE;
            RENDER_SCENE = SCENE_WORLD_PAINTER_MENU_RENDER;
            CLOSE_SCENE = SCENE_WORLD_PAINTER_MENU_CLOSE;
            break;
        case SCENE_ProceduralWorldMenu:
            START_SCENE = SCENE_PROCEDURAL_WORLD_MENU_START;
            UPDATE_SCENE = SCENE_PROCEDURAL_WORLD_MENU_UPDATE;
            RENDER_SCENE = SCENE_PROCEDURAL_WORLD_MENU_RENDER;
            CLOSE_SCENE = SCENE_PROCEDURAL_WORLD_MENU_CLOSE;
            break;
        case SCENE_BattleMap:
            START_SCENE = SCENE_BATTLE_MAP_Start;
            UPDATE_SCENE = SCENE_BATTLE_MAP_Update;
            RENDER_SCENE = SCENE_BATTLE_MAP_Render;
            CLOSE_SCENE = SCENE_BATTLE_MAP_Close;
            break;
        case SCENE_WorldCreation:
            START_SCENE = SCENE_WORLD_CREATION_START;
            UPDATE_SCENE = SCENE_WORLD_CREATION_UPDATE;
            RENDER_SCENE = SCENE_WORLD_CREATION_RENDER;
            CLOSE_SCENE = SCENE_WORLD_CREATION_CLOSE;
            break;
        default:
            return RETURN_ERROR;
    }

    if (!contextData) {
        free(SceneData);
    } else {
        contextData = false;
    }

    if (START_SCENE) {
        (*START_SCENE)();
    }
    else {

    }
    return RETURN_SUCCESS;
}