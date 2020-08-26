#include "Engine/Engine.h"

int main() {
    Initialise();

    ChangeScene(SCENE_SplashScreen);
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }


    Close();
    return 0;
}