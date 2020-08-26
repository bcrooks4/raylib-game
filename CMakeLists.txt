cmake_minimum_required(VERSION 3.17)
project(Raylib_Game C)

set(CMAKE_C_STANDARD 99)

INCLUDE_DIRECTORIES(
        C:/dev/vcpkg/installed/x64-windows/include
)
LINK_DIRECTORIES(
        C:/dev/vcpkg/installed/x64-windows/lib
)

add_executable(Raylib_Game main.c Engine/SceneManager.h Engine/SceneManager.c Engine/Engine.h Scenes/SCENE_SplashScreen.h Scenes/SCENE_SplashScreen.c Scenes/SCENE_MainMenu.h Scenes/SCENE_MainMenu.c Engine/Engine.c Scenes/SCENE_Credits.h Scenes/SCENE_Credits.c Scenes/SCENE_WorldPainter.h Scenes/SCENE_WorldPainter.c Utility/Macro.h Utility/ProceduralGeneration.h Scenes/SCENE_MapViewer.c Scenes/SCENE_MapViewer.h Scenes/SCENE_NewWorldMenu.h Scenes/SCENE_NewWorldMenu.c Scenes/SCENE_WorldPainterMenu.h Scenes/SCENE_WorldPainterMenu.c Scenes/SCENE_ProceduralWorldMenu.h Scenes/SCENE_ProceduralWorldMenu.c Utility/ProceduralGeneration.c Scenes/SCENE_BattleMap.h Scenes/SCENE_BattleMap.c Scenes/SCENE_WorldCreation.c Scenes/SCENE_WorldCreation.h)

TARGET_LINK_LIBRARIES(
        Raylib_Game
        raylib
)