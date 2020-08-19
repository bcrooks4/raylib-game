#include <stdlib.h>
#include <raylib.h>
#include <math.h>
#include <stdio.h>

//region Declarations

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define CLAMP(a, b, c) (MIN(MAX((a), (b)), (c)))

#define RESULT          int
#define RETURN_SUCCESS  0
#define RETURN_ERROR    1

#define SCENE           int
#define SCENE_METHOD    int
enum Scenes {
    SCENE_SplashScreen,
    SCENE_MainMenu,
    SCENE_Credits,
    SCENE_WorldPainter,
    SCENE_MapViewer,
    SCENE_NewWorldMenu,
    SCENE_WorldPainterMenu,
};

RESULT Initialise();
RESULT Update();
RESULT Draw();
RESULT Close();

RESULT ChangeScene();

bool contextData = false;
void *SceneData = 0;
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

SCENE_METHOD SCENE_WorldPainter_Start();
SCENE_METHOD SCENE_WorldPainter_Update();
SCENE_METHOD SCENE_WorldPainter_Render();
SCENE_METHOD SCENE_WorldPainter_Close();
typedef struct {
    int *map;
    int width;
    int height;
    int textureScale;
    Camera2D camera;
    Vector2 previousTile;
} SCENE_WORLD_PAINTER_Data;

SCENE_METHOD SCENE_MAP_VIEWER_Start();
SCENE_METHOD SCENE_MAP_VIEWER_Update();
SCENE_METHOD SCENE_MAP_VIEWER_Render();
SCENE_METHOD SCENE_MAP_VIEWER_Close();
typedef struct {
    Texture texture;
    Camera2D camera;
} SCENE_MAP_VIEWER_Data;

SCENE_METHOD SCENE_NEW_WORLD_MENU_START();
SCENE_METHOD SCENE_NEW_WORLD_MENU_UPDATE();
SCENE_METHOD SCENE_NEW_WORLD_MENU_RENDER();
SCENE_METHOD SCENE_NEW_WORLD_MENU_CLOSE();
typedef struct {
    int cursorHighlight;
} SCENE_NEW_WORLD_MENU_Data;

SCENE_METHOD SCENE_WORLD_PAINTER_MENU_START();
SCENE_METHOD SCENE_WORLD_PAINTER_MENU_UPDATE();
SCENE_METHOD SCENE_WORLD_PAINTER_MENU_RENDER();
SCENE_METHOD SCENE_WORLD_PAINTER_MENU_CLOSE();
typedef struct {
    int cursorHighlight;
    int size;
} SCENE_WORLD_PAINTER_MENU_Data;

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
        if ((*CLOSE_SCENE)()) {
            Close();
        }
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

RESULT Initialise() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1200, 800, "");
    SetTargetFPS(60);
    SetExitKey(0);
    return RETURN_SUCCESS;
}

RESULT Update() {
    if (UPDATE_SCENE) {
        if ((*UPDATE_SCENE)()) {
            Close();
        }
    }
    SetWindowTitle(TextFormat("%d FPS", GetFPS()));
    if (IsKeyPressed(KEY_F)) {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_UNDECORATED);
        CloseWindow();
        InitWindow(GetMonitorWidth(0), GetMonitorWidth(0), "");
        SetExitKey(0);
        SetTargetFPS(60);
    }
    return RETURN_SUCCESS;
}

RESULT Draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    if (RENDER_SCENE) {
        if ((*RENDER_SCENE)()) {
            Close();
        }
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

//endregion

//region Main Menu

SCENE_METHOD SCENE_MAIN_MENU_Start() {
    SCENE_MAIN_MENU_Data *data = (SCENE_MAIN_MENU_Data *) malloc(sizeof(SCENE_MAIN_MENU_Data));
    SceneData = data;
    data->cursorHighlight = 0;
    data->alpha = 0.0f;
    data->mouseMoved = false;
    data->mousePreviousPosition = GetMousePosition();

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_MAIN_MENU_Update() {
    SCENE_MAIN_MENU_Data* data = SceneData;

    data->alpha += 0.025f;
    if (data->alpha > 1) data->alpha = 1;

    data->mouseMoved = GetMousePosition().x != data->mousePreviousPosition.x ||
            GetMousePosition().y != data->mousePreviousPosition.y;
    if (data->mouseMoved && GetScreenHeight() - GetMouseY() < 4 * 64 &&
        (float) GetMouseX() / (float) GetScreenWidth() > 0.75f) {
        data->cursorHighlight = 3 - (int) ((GetScreenHeight() - GetMouseY()) / 64);
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
                ChangeScene(SCENE_NewWorldMenu);
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
    return RETURN_SUCCESS;
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
        Color drawColour = 3 - data->cursorHighlight == i ? WHITE : (Color) {50, 50, 50, 255};
        if (3 - data->cursorHighlight == i) {
            x -= 32;
        }
        DrawText(text, x, y, 64, Fade(drawColour, data->alpha));
    }

    DrawText("v0.1a", 0, GetScreenHeight() - 32, 32, (Color){50, 50, 50, 255});
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_MAIN_MENU_Close() {
    return RETURN_SUCCESS;
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

//region World Painter

SCENE_METHOD SCENE_WorldPainter_Start() {
    SCENE_WORLD_PAINTER_Data *data = SceneData;

    for (int y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++) {
            data->map[y * data->width + x] = 0;
        }
    }

    data->camera = (Camera2D) {0};
    data->camera.zoom = 1;
    data->camera.target = (Vector2) {0, 0};
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WorldPainter_Update() {
    SCENE_WORLD_PAINTER_Data *data = SceneData;

    if (IsKeyDown(KEY_ESCAPE)) {
        ChangeScene(SCENE_WorldPainterMenu);
    }

    data->camera.offset.x = (float) GetScreenWidth() / 2;
    data->camera.offset.y = (float) GetScreenHeight() / 2;

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
        data->camera.zoom += 0.05f;
    }
    if (GetMouseWheelMove() < 0) {
        data->camera.zoom -= 0.05f;
    }
    data->camera.zoom = CLAMP(data->camera.zoom, 0.1, 4.95);

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        int y;
        y = (int) (GetMouseY());
        int x;
        x = (int) (GetMouseX());

        int cameraPositionX = (int) (data->camera.target.x);
        int cameraPositionY = (int) (data->camera.target.y);

        int tileX;
        tileX = (int) (((float) x - data->camera.offset.x) / data->camera.zoom + (float) cameraPositionX) / 32;
        int tileY;
        tileY = (int) (((float) y - data->camera.offset.y) / data->camera.zoom + (float) cameraPositionY) / 32;

        if (tileX != (int) data->previousTile.x || tileY != (int) data->previousTile.y) {
            if (tileX >= 0 && tileX < data->width && tileY >= 0 && tileY < data->height) {
                data->map[tileY * data->width + tileX] = !data->map[tileY * data->width + tileX];
            }
            data->previousTile = (Vector2) {(float) tileX, (float) tileY};
        }
    }

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        data->previousTile = (Vector2) {-1, -1};
    }

    if (IsKeyPressed(KEY_ENTER)) {
        int width = data->width * data->textureScale;
        int height = data->height * data->textureScale;
        Vector2 *cellPositions = malloc(data->width * data->height * sizeof(Vector2));
        Color *cellColours = malloc(data->width * data->height * sizeof(Color));
        for (int y = 0; y < data->height; y++) {
            for (int x = 0; x < data->width; x++) {
                cellPositions[y * data->width + x] =
                        (Vector2) {(float) (x * data->textureScale + rand() % data->textureScale),
                                   (float) (y * data->textureScale + rand() % data->textureScale)};
                //cellColours[y * data->width + x] = data->map[y * data->width + x] ? GREEN : BLUE;
                cellColours[y * data->width + x] = data->map[y * data->width + x] ? GREEN : BLUE;
            }
        }

        Color *pixels = malloc(width * height * sizeof(Color));
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int closestDistance = 999;
                int cellIndex = 0;
                for (int i = 0; i < data->width * data->height; i++) {
                    //int distanceX = abs((x - cellPositions[i].x) * (x - cellPositions[i].x));
                    //int distanceY = abs((y - cellPositions[i].y) * (y - cellPositions[i].y));

                    int distanceX = abs(x - (int) cellPositions[i].x);
                    int distanceY = abs(y - (int) cellPositions[i].y);

                    int dist = distanceX + distanceY;
                    if (closestDistance > dist) {
                        closestDistance = dist;
                        cellIndex = i;
                    }
                }

                Color colour = cellColours[cellIndex];
                pixels[y * width + x] = colour;
            }
        }


        Image image = {
                .data = pixels,
                .width = width,
                .height = height,
                .format = UNCOMPRESSED_R8G8B8A8,
                .mipmaps = 1
        };

        ExportImage(image, "out.png");
        UnloadImage(image);

        ChangeScene(SCENE_MapViewer);
    }

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WorldPainter_Render() {
    SCENE_WORLD_PAINTER_Data *data = SceneData;

    BeginMode2D(data->camera);

    for (int y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++) {
            Color colour = data->map[y * data->width + x] ? GREEN : BLUE;
            DrawRectangle(x * 32, y * 32, 32, 32, colour);
        }
    }

    EndMode2D();

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WorldPainter_Close() {
    SCENE_WORLD_PAINTER_Data *data = SceneData;
    free(data->map);
    return RETURN_SUCCESS;
}

//endregion

//region View Map Scene

SCENE_METHOD SCENE_MAP_VIEWER_Start() {
    SCENE_MAP_VIEWER_Data *data = malloc(sizeof(SCENE_MAP_VIEWER_Data));
    SceneData = data;

    data->texture = LoadTexture("out.png");
    data->camera = (Camera2D) {0};
    data->camera.zoom = 1;
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_MAP_VIEWER_Update() {
    SCENE_MAP_VIEWER_Data *data = SceneData;

    if (IsKeyPressed(KEY_ESCAPE)) {
        ChangeScene(SCENE_MainMenu);
    }

    data->camera.offset.x = (float) GetScreenWidth() / 2;
    data->camera.offset.y = (float) GetScreenHeight() / 2;

    if (IsKeyDown(KEY_LEFT)) {
        data->camera.target.x -= 5 * (6 - data->camera.zoom);
    }
    if (IsKeyDown(KEY_RIGHT)) {
        data->camera.target.x += 5 * (6 - data->camera.zoom);
    }
    if (IsKeyDown(KEY_UP)) {
        data->camera.target.y -= 5 * (6 - data->camera.zoom);
    }
    if (IsKeyDown(KEY_DOWN)) {
        data->camera.target.y += 5 * (6 - data->camera.zoom);
    }

    if (GetMouseWheelMove() > 0) {
        data->camera.zoom += 0.05f;
    }
    if (GetMouseWheelMove() < 0) {
        data->camera.zoom -= 0.05f;
    }
    data->camera.zoom = CLAMP(data->camera.zoom, 0.1, 4.95);
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_MAP_VIEWER_Render() {
    SCENE_MAP_VIEWER_Data *data = SceneData;
    BeginMode2D(data->camera);
    DrawTexture(data->texture, 0, 0, WHITE);
    EndMode2D();
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_MAP_VIEWER_Close() {
    SCENE_MAP_VIEWER_Data *data = SceneData;
    UnloadTexture(data->texture);
    return RETURN_SUCCESS;
}

//endregion

//region New World Menu

SCENE_METHOD SCENE_NEW_WORLD_MENU_START() {
    SceneData = malloc(sizeof(SCENE_NEW_WORLD_MENU_Data));
    SCENE_NEW_WORLD_MENU_Data *data = SceneData;
    data->cursorHighlight = 0;
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_NEW_WORLD_MENU_UPDATE() {
    SCENE_NEW_WORLD_MENU_Data *data = SceneData;

    if (IsKeyPressed(KEY_ESCAPE)) {
        ChangeScene(SCENE_MainMenu);
    }

    if (IsKeyPressed(KEY_ENTER)) {
        switch (data->cursorHighlight) {
            case 0:
                ChangeScene(SCENE_WorldPainterMenu);
                break;
            case 1:
                //TODO: Add procedural generation option
                break;
                //TODO: Add load world option
        }
    }

    if (IsKeyPressed(KEY_DOWN)) {
        data->cursorHighlight++;
    } else if (IsKeyPressed(KEY_UP)) {
        data->cursorHighlight--;
    }
    data->cursorHighlight = CLAMP(data->cursorHighlight, 0, 1);

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_NEW_WORLD_MENU_RENDER() {
    SCENE_NEW_WORLD_MENU_Data *data = SceneData;
    DrawRectangleLinesEx((Rectangle) {
                                 16,
                                 120,
                                 (float) GetScreenWidth() - 32,
                                 (float) GetScreenHeight() - (120 + 16)
                         }, 2, WHITE
    );
    DrawText("NEW WORLD", 16, 32, 64, WHITE);

    for (int i = 0; i < 2; i++) {
        Color textColour = data->cursorHighlight == i ? WHITE : (Color) {50, 50, 50, 255};
        switch (i) {
            case 0:
                DrawText("World Painter", 32, 128, 32, textColour);
                break;
            case 1:
                DrawText("Procedural", 32, 128 + 32, 32, textColour);
                break;
        }
    }
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_NEW_WORLD_MENU_CLOSE() {
    return RETURN_SUCCESS;
}

//endregion

//region World Painter Menu

SCENE_METHOD SCENE_WORLD_PAINTER_MENU_START() {
    SceneData = malloc(sizeof(SCENE_WORLD_PAINTER_MENU_Data));
    SCENE_WORLD_PAINTER_MENU_Data *data = SceneData;
    data->cursorHighlight = 0;
    data->size = 1;
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_PAINTER_MENU_UPDATE() {
    SCENE_WORLD_PAINTER_MENU_Data *data = SceneData;

    if (IsKeyPressed(KEY_ESCAPE)) {
        ChangeScene(SCENE_NewWorldMenu);
    }

    if (IsKeyPressed(KEY_ENTER)) {
        switch (data->cursorHighlight) {
            case 0:
                data->size++;
                if (data->size > 2) {
                    data->size = 0;
                }
                break;
            //TODO: Add load world option
            case 1:
                int size = data->size;
                free(data);

                SCENE_WORLD_PAINTER_Data *cData = malloc(sizeof(SCENE_WORLD_PAINTER_Data));
                SceneData = cData;

                switch (size) {
                    case 0:
                        cData->width = 8;
                        cData->height = 8;
                        break;
                    case 1:
                        cData->width = 16;
                        cData->height = 16;
                        break;
                    case 2:
                        cData->width = 32;
                        cData->height = 32;
                        break;
                    default:
                        cData->width = 16;
                        cData->height = 16;
                        break;
                }

                cData->textureScale = 8;
                cData->map = malloc(sizeof(int) * cData->width * cData->height);

                contextData = true;
                ChangeScene(SCENE_WorldPainter);
                return RETURN_SUCCESS;
            default:
                break;
        }
    }

    if (IsKeyPressed(KEY_DOWN)) {
        data->cursorHighlight++;
    } else if (IsKeyPressed(KEY_UP)) {
        data->cursorHighlight--;
    }
    data->cursorHighlight = CLAMP(data->cursorHighlight, 0, 1);

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_PAINTER_MENU_RENDER() {
    SCENE_WORLD_PAINTER_MENU_Data *data = SceneData;
    DrawRectangleLinesEx((Rectangle) {
                                 16,
                                 120,
                                 (float) GetScreenWidth() - 32,
                                 (float) GetScreenHeight() - (120 + 16)
                         }, 2, WHITE
    );
    DrawText("WORLD PAINTER", 16, 32, 64, WHITE);

    for (int i = 0; i < 2; i++) {
        Color textColour = data->cursorHighlight == i ? WHITE : (Color) {50, 50, 50, 255};
        switch (i) {
            case 0:
                const char* text;
                switch (data->size) {
                    case 0:
                        text = "Size small";
                        break;
                    case 1:
                        text = "Size medium";
                        break;
                    case 2:
                        text = "Size large";
                        break;
                }
                DrawText(text, 32, 128, 32, textColour);
                break;
            case 1:
                DrawText("Finish", 32, 128 + 32, 32, textColour);
                break;
        }
    }
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_PAINTER_MENU_CLOSE() {
    return RETURN_SUCCESS;
}

//endregion
