//
// Created by Bill on 27/08/2020.
//

#include "SCENE_WorldViewer.h"

void LoadMapFile(const char* filename);
void GetNextValue(FILE *file, char* string);

SCENE_METHOD SCENE_WORLD_VIEWER_Start() {
    SCENE_WORLD_VIEWER_Data *data = malloc(sizeof(SCENE_WORLD_VIEWER_Data));
    SceneData = data;

    data->camera = (Camera2D) {0};
    data->camera.zoom = 1;

    LoadMapFile("MAP DATA");

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_VIEWER_Update() {
    SCENE_WORLD_VIEWER_Data *data = SceneData;

    if (IsKeyPressed(KEY_ESCAPE)) {
        ChangeScene(SCENE_NewWorldMenu);
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

SCENE_METHOD SCENE_WORLD_VIEWER_Render() {
    SCENE_WORLD_VIEWER_Data *data = SceneData;
    ClearBackground(SKYBLUE);

    BeginMode2D(data->camera);

        DrawRectangleLines(0, 0, (int)data->mapSize.x, (int)data->mapSize.y, WHITE);

        for (int i = 0; i < data->cellCount; i++) {
            DrawTexture(data->cells[i].texture, data->cells[i].x, data->cells[i].y, WHITE);
        }

    EndMode2D();

    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_VIEWER_Close() {
    SCENE_WORLD_VIEWER_Data *data = SceneData;
    if (data->cells)
        free(data->cells);
    return RETURN_SUCCESS;
}

void LoadMapFile(const char* filename) {
    SCENE_WORLD_VIEWER_Data *data = SceneData;
    FILE *file;
    fopen_s(&file, filename, "r");

    char* string = "";

    GetNextValue(file, string);
    data->mapSize.x = (float)atoi(string);

    GetNextValue(file, string);
    data->mapSize.y = (float)atoi(string);

    GetNextValue(file, string);
    printf("%s\n", string);
    int x = atoi(string);
    GetNextValue(file, string);
    printf("%s\n", string);
    int y = atoi(string);
    GetNextValue(file, string);
    printf("%s\n", string);
    int width = atoi(string) + 1;
    GetNextValue(file, string);
    printf("%s\n", string);
    int height = atoi(string) + 1;

    printf("\n\n");
    int i = 0;

    data->cellCount = 1;
    data->cells = malloc(i * sizeof(GameCell));

    Color *pixels = malloc(width * height * sizeof(Color));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            GetNextValue(file, string);
            pixels[y * width + x] = atoi(string) ? GREEN : BLANK;
            printf("%s", string);
        }
        printf("\n");
    }

    /*
    while(string[0] != '\0') {
        GetNextValue(file, string);
        printf("%d ", i);
        if (i <= width * height) {
            pixels[i] = atoi(string) ? WHITE : BLACK;
        }
        i++;
    }
     */

    Image image = (Image) {
        .width = width,
        .height = height,
        .format = UNCOMPRESSED_R8G8B8A8,
        .mipmaps = 1,
        .data = pixels
    };

    //ImageToPOT(&image, BLANK);

    data->cells->texture = LoadTextureFromImage(image);
    data->cells->x = x;
    data->cells->y = y;


    fclose(file);
}

void GetNextValue(FILE *file, char* string) {
    char ch;
    string[0] = '\0';
    while ((ch = (char)getc(file)) != EOF) {
        if (ch == CLAMP(ch, 48, 57)) {
            strncat(string, &ch, 1);
        }
        else if ((ch == ',' || ch == '\n') && ch > 32) {
            return;
        }
        else if (ch == '-') {
            string[0] = '\0';
            return;
        }
    }
    string[0] = -1;
}
