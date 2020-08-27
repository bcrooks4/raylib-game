//
// Created by Bill on 20/08/2020.
//

#include "../Utility/Macro.h"
#include "../Utility/ProceduralGeneration.h"
#include "SceneManager.h"
#include <stdlib.h>
#include <raylib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#define RESULT          int
#define RETURN_SUCCESS  0
#define RETURN_ERROR    1

#define SCENE           int
#define SCENE_METHOD    int

RESULT Initialise();
RESULT Update();
RESULT Draw();
RESULT Close();
