//
// Created by Bill on 26/08/2020.
//

#include "SCENE_WorldCreation.h"


SCENE_METHOD SCENE_WORLD_CREATION_START() {
    SCENE_WORLD_CREATION_Data* data;
    SceneData = data = malloc(sizeof(SCENE_NEW_WORLD_MENU_Data));

    const int map[] = {
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,1,0,0,0,
            0,0,0,1,1,1,0,0,
            0,0,1,1,1,1,1,0,
            0,0,0,1,0,1,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
    };

    ExportGeneratedMap("map.md", map, 8, 8, 16);
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_CREATION_UPDATE() {
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_CREATION_RENDER() {
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_CREATION_CLOSE() {
    return RETURN_SUCCESS;
}

