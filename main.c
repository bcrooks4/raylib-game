#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>

//region Declarations

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define CLAMP(a, b, c) (MIN(MAX(a, b), c))

#define RESULT          int
#define RETURN_SUCCESS  0
#define RETURN_ERROR    1

#define SCENE           int
#define SCENE_METHOD    int
enum Scenes {
    SCENE_SplashScreen,
    SCENE_MainMenu,
    SCENE_Credits,
    SCENE_Game,
};

RESULT Initialise();
RESULT Update();
RESULT Draw();
RESULT Close();

RESULT ChangeScene();

void* SceneData = 0;
SCENE_METHOD (*START_SCENE)     ();
SCENE_METHOD (*UPDATE_SCENE)    ();
SCENE_METHOD (*RENDER_SCENE)    ();
SCENE_METHOD (*CLOSE_SCENE)     ();

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

SCENE_METHOD SCENE_CREDITS_Start();
SCENE_METHOD SCENE_CREDITS_Update();
SCENE_METHOD SCENE_CREDITS_Render();
SCENE_METHOD SCENE_CREDITS_Close();

SCENE_METHOD SCENE_GAME_Start();
SCENE_METHOD SCENE_GAME_Update();
SCENE_METHOD SCENE_GAME_Render();
SCENE_METHOD SCENE_GAME_Close();
typedef struct {
    int* map;
    int width;
    int height;

    Camera2D camera;
} SCENE_GAME_Data;
//endregion


//region Main

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

//endregion

//region Engine

RESULT ChangeScene(SCENE scene) {
    if (CLOSE_SCENE) {
        (*CLOSE_SCENE)();
    }

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
        case SCENE_Game:
            START_SCENE = SCENE_GAME_Start;
            UPDATE_SCENE = SCENE_GAME_Update;
            RENDER_SCENE = SCENE_GAME_Render;
            CLOSE_SCENE = SCENE_GAME_Close;
            break;
        default:
            return RETURN_ERROR;
    }

    if (SceneData) {
        free(SceneData);
    }
    if (START_SCENE) {
        (*START_SCENE)();
    }
    return RETURN_SUCCESS;
}

RESULT Initialise() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1200, 800, "");
    SetTargetFPS(60);
    SetExitKey(NULL);
    return RETURN_SUCCESS;
}

RESULT Update() {
    if (UPDATE_SCENE) {
        (*UPDATE_SCENE)();
    }
    SetWindowTitle(TextFormat("%d FPS", GetFPS()));
    return RETURN_SUCCESS;
}

RESULT Draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    if (RENDER_SCENE) {
        (*RENDER_SCENE)();
    }
    EndDrawing();
    return RETURN_SUCCESS;
}

RESULT Close() {
    if (CLOSE_SCENE) {
        (*CLOSE_SCENE)();
    }
    CloseWindow();
    return RETURN_SUCCESS;
}

//endregion

//region Splash Screen

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
        DrawText("A game by Bill Crooks", 0, GetScreenHeight() - 32, 32, RAYWHITE);
    }
}

SCENE_METHOD SCENE_SPLASH_Close() {

}

//endregion

//region Main Menu

SCENE_METHOD SCENE_MAIN_MENU_Start() {
    SCENE_MAIN_MENU_Data* data = (SCENE_MAIN_MENU_Data *)malloc(sizeof(SCENE_MAIN_MENU_Data));
    SceneData = data;
    data->cursorHighlight = 0;
    data->alpha = 0.0f;
    data->mouseMoved = false;
    data->mousePreviousPosition = GetMousePosition();
}

SCENE_METHOD SCENE_MAIN_MENU_Update() {
    SCENE_MAIN_MENU_Data* data = SceneData;

    data->alpha += 0.025f;
    if (data->alpha > 1) data->alpha = 1;

    data->mouseMoved = GetMousePosition().x != data->mousePreviousPosition.x ||
            GetMousePosition().y != data->mousePreviousPosition.y;
    if (data->mouseMoved && GetScreenHeight() - GetMouseY() < 4 * 64 && (float)GetMouseX() / GetScreenWidth() > 0.75f) {
        data->cursorHighlight = 3 - (int)((GetScreenHeight() - GetMouseY()) / 64);
    }

    if (IsKeyPressed(KEY_DOWN)) {
        data->cursorHighlight++;
    }
    else if (IsKeyPressed(KEY_UP)) {
        data->cursorHighlight--;
    }

    if (data->cursorHighlight > 3) {
        data->cursorHighlight = 3;
    }
    else if (data->cursorHighlight < 0) {
        data->cursorHighlight = 0;
    }

    if (IsKeyPressed(KEY_R)) {
        ChangeScene(SCENE_SplashScreen);
    }

    if (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        switch (data->cursorHighlight) {
            case 0:         // Play
                ChangeScene(SCENE_Game);
                break;
            case 1:         // Options
                break;
            case 2:         // Credits
                ChangeScene(SCENE_Credits);
                break;
            case 3:         // Quit
                Close();
                break;
        }
    }

    data->mousePreviousPosition = GetMousePosition();
}

SCENE_METHOD SCENE_MAIN_MENU_Render() {
    SCENE_MAIN_MENU_Data* data = SceneData;

    for (int i = 0; i < 4; i++) {

        const char* text;
        int x, y;

        switch (i) {
            case 0:
                text = "Quit";
                y = GetScreenHeight() - 64 * 1;
                break;
            case 1:
                text = "Credits";
                y = GetScreenHeight() - 64 * 2;
                break;
            case 2:
                text = "Options";
                y = GetScreenHeight() - 64 * 3;
                break;
            case 3:
                text = "Play";
                y = GetScreenHeight() - 64 * 4;
                break;
        }

        x = GetScreenWidth() - MeasureText(text, 64);
        Color drawColour = 3 - data->cursorHighlight == i ? WHITE : (Color){50, 50, 50, 255};
        DrawText(text, x, y, 64, Fade(drawColour, data->alpha));
    }

    DrawText("v0.1a", 0, GetScreenHeight() - 32, 32, (Color){50, 50, 50, 255});
}

SCENE_METHOD SCENE_MAIN_MENU_Close() {

}

//endregion

//region Credits

SCENE_METHOD SCENE_CREDITS_Start() {
    SceneData = malloc(sizeof(char));
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_CREDITS_Update() {
    if (IsKeyPressed(KEY_ESCAPE)) {
        ChangeScene(SCENE_MainMenu);
    }
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_CREDITS_Render() {
    const char* text1 = "Made by Bill Crooks";
    int x1 = GetScreenWidth() / 2 - MeasureText(text1, 64) / 2;
    int y1 = GetScreenHeight() / 2 - 64;

    const char* text2 = "Using the Raylib Engine";
    int x2 = GetScreenWidth() / 2 - MeasureText(text2, 64) / 2;
    int y2 = GetScreenHeight() / 2 + 64;

    DrawText(text1, x1, y1, 64, WHITE);
    DrawText(text2, x2, y2, 64, WHITE);

    DrawText("Press escape to go back",
             0, GetScreenHeight() - 42,
             32,
             (Color){50, 50, 50, 255});

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_CREDITS_Close() {
    return RETURN_SUCCESS;
}

//endregion

//region Game

SCENE_METHOD SCENE_GAME_Start() {
    SCENE_GAME_Data* data = malloc(sizeof(SCENE_GAME_Data));
    SceneData = data;
    data->width     = 32;
    data->height    = 32;
    data->map = malloc(sizeof(int) * data->width * data->height);

    for (int y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++) {
            data->map[y * data->width + x] = 0;
        }
    }

    data->camera = (Camera2D){0};
    data->camera.zoom = 1;
    data->camera.target = (Vector2){0, 0};
}

SCENE_METHOD SCENE_GAME_Update() {
    SCENE_GAME_Data* data = SceneData;

    if (IsKeyDown(KEY_ESCAPE)) {
        ChangeScene(SCENE_MainMenu);
    }

    data->camera.offset.x = GetScreenWidth() / 2;
    data->camera.offset.y = GetScreenHeight() / 2;

    if (IsKeyDown(KEY_LEFT) || GetMouseX() < 20) {
        data->camera.target.x -= 5 * (6 - data->camera.zoom);
    }
    if (IsKeyDown(KEY_RIGHT) || GetMouseX() > GetScreenWidth() - 20) {
        data->camera.target.x += 5 * (6 - data->camera.zoom);
    }
    if (IsKeyDown(KEY_UP) || GetMouseY() < 20) {
        data->camera.target.y -= 5 * (6 - data->camera.zoom);
    }
    if (IsKeyDown(KEY_DOWN) || GetMouseY() > GetScreenHeight() - 20) {
        data->camera.target.y += 5 * (6 - data->camera.zoom);
    }

    if (GetMouseWheelMove() > 0) {
        data->camera.zoom += 0.05;
    }
    if (GetMouseWheelMove() < 0) {
        data->camera.zoom -= 0.05;
    }
    data->camera.zoom = CLAMP(data->camera.zoom, 0.1, 4.95);

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        int y;
        y = (int) (GetMouseY());
        int x;
        x = (int) (GetMouseX());

        int cameraPositionX = (int)(data->camera.target.x);
        int cameraPositionY = (int)(data->camera.target.y);

        int tileX;
        tileX = ((x - data->camera.offset.x) / data->camera.zoom + cameraPositionX) / 32;
        int tileY;
        tileY = ((y - data->camera.offset.y) / data->camera.zoom + cameraPositionY) / 32;

        if (tileX >= 0 && tileX < data->width && tileY >= 0 && tileY < data->height) {
            data->map[tileY * data->width + tileX] = !data->map[tileY * data->width + tileX];
        }
    }
}

SCENE_METHOD SCENE_GAME_Render() {
    SCENE_GAME_Data* data = SceneData;

    BeginMode2D(data->camera);

    for (int y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++) {
            Color colour = data->map[y * data->width + x] ? GREEN : BLUE;
            DrawRectangle(x * 32, y * 32, 32, 32, colour);
        }
    }

    EndMode2D();


}

SCENE_METHOD SCENE_GAME_Close() {

}

//endregion