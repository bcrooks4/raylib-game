#include "Engine/Engine.h"

int main() {
    Initialise();

    ChangeScene(SCENE_SplashScreen);
    while (!WindowShouldClose()) {
        sceneChanged = false;

        if (!sceneChanged) Update();
        if (!sceneChanged) Draw();
        else {
            BeginDrawing();
                ClearBackground(BLACK);
            EndDrawing();
        }
    }


    Close();
    return 0;
}