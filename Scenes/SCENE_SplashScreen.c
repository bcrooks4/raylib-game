//
// Created by Bill on 20/08/2020.
//

#include "SCENE_SplashScreen.h"
#include "../Engine/SceneManager.h"

SCENE_METHOD SCENE_SPLASH_Start() {
    SCENE_SPLASH_Data* data = (SCENE_SPLASH_Data*)malloc(sizeof(SCENE_SPLASH_Data));
    SceneData = data;
    data->logoPositionX = GetScreenWidth() / 2 - 128;
    data->logoPositionY = GetScreenHeight() / 2 - 128;

    data->framesCounter = 0;
    data->lettersCount = 0;

    data->topSideRecWidth = 16;
    data->leftSideRecHeight = 16;

    data->bottomSideRecWidth = 16;
    data->rightSideRecHeight = 16;

    data->state = 0;
    data->alpha = 1.0f;

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_SPLASH_Update() {
    SCENE_SPLASH_Data *data = (SCENE_SPLASH_Data *) SceneData;
    data->logoPositionX = GetScreenWidth() / 2 - 128;
    data->logoPositionY = GetScreenHeight() / 2 - 128;

    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_SPACE)) {
        ChangeScene(SCENE_MainMenu);
    }

    if (data->state == 0) {
        data->framesCounter++;

        if (data->framesCounter == 120) {
            data->state = 1;
            data->framesCounter = 0;
        }
    } else if (data->state == 1) {
        data->topSideRecWidth += 4;
        data->leftSideRecHeight += 4;

        if (data->topSideRecWidth == 256) data->state = 2;
    } else if (data->state == 2) {
        data->bottomSideRecWidth += 4;
        data->rightSideRecHeight += 4;

        if (data->bottomSideRecWidth == 256) data->state = 3;
    } else if (data->state == 3) {
        data->framesCounter++;

        if (data->framesCounter / 12) {
            data->lettersCount++;
            data->framesCounter = 0;
        }

        if (data->lettersCount >= 10) {
            data->alpha -= 0.02f;

            if (data->alpha <= 0.0f) {
                data->alpha = 0.0f;
                data->state = 4;
                data->framesCounter = 0;
            }
        }
    } else if (data->state == 4) {
        data->framesCounter++;
        if (data->framesCounter > 120) {
            ChangeScene(SCENE_MainMenu);
        }
    }

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_SPLASH_Render() {
    SCENE_SPLASH_Data *data = (SCENE_SPLASH_Data *) SceneData;
    data->logoPositionX = GetScreenWidth() / 2 - 128;
    data->logoPositionY = GetScreenHeight() / 2 - 128;

    ClearBackground(BLACK);

    if (data->state == 0) {
        if ((data->framesCounter / 15) % 2) DrawRectangle(data->logoPositionX, data->logoPositionY, 16, 16, RAYWHITE);
    } else if (data->state == 1) {
        DrawRectangle(data->logoPositionX, data->logoPositionY, data->topSideRecWidth, 16, RAYWHITE);
        DrawRectangle(data->logoPositionX, data->logoPositionY, 16, data->leftSideRecHeight, RAYWHITE);
    } else if (data->state == 2) {
        DrawRectangle(data->logoPositionX, data->logoPositionY, data->topSideRecWidth, 16, RAYWHITE);
        DrawRectangle(data->logoPositionX, data->logoPositionY, 16, data->leftSideRecHeight, RAYWHITE);

        DrawRectangle(data->logoPositionX + 240, data->logoPositionY, 16, data->rightSideRecHeight, RAYWHITE);
        DrawRectangle(data->logoPositionX, data->logoPositionY + 240, data->bottomSideRecWidth, 16, RAYWHITE);
    } else if (data->state == 3) {
        DrawRectangle(data->logoPositionX, data->logoPositionY, data->topSideRecWidth, 16, Fade(RAYWHITE, data->alpha));
        DrawRectangle(data->logoPositionX, data->logoPositionY + 16, 16, data->leftSideRecHeight - 32,
                      Fade(RAYWHITE, data->alpha));

        DrawRectangle(data->logoPositionX + 240, data->logoPositionY + 16, 16, data->rightSideRecHeight - 32,
                      Fade(RAYWHITE, data->alpha));
        DrawRectangle(data->logoPositionX, data->logoPositionY + 240, data->bottomSideRecWidth, 16,
                      Fade(RAYWHITE, data->alpha));

        DrawRectangle(GetScreenWidth() / 2 - 112, GetScreenHeight() / 2 - 112, 224, 224, Fade(RAYWHITE, data->alpha));

        DrawText(TextSubtext("raylib", 0, data->lettersCount), GetScreenWidth() / 2 - 44, GetScreenHeight() / 2 + 48,
                 50, Fade(BLACK, data->alpha));
    } else if (data->state == 4) {
        ClearBackground(BLACK);
        DrawText("A WORLD_PAINTER by Bill Crooks", 0, GetScreenHeight() - 32, 32, RAYWHITE);
    }

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_SPLASH_Close() {
    return RETURN_SUCCESS;
}

