//
// Created by Bill on 26/08/2020.
//

#include "SCENE_WorldCreation.h"


SCENE_METHOD SCENE_WORLD_CREATION_START() {
    SceneData = malloc(sizeof(char));

    const int inputMap[] = {
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,1,0,0,0,
            0,0,0,1,1,1,0,0,
            0,0,1,1,1,1,1,0,
            0,0,0,1,0,1,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
    };

    int scale = 8;
    int width = 8;
    int height = 8;
    int mapWidth = width * scale;
    int mapHeight = height * scale;


    Cell *cells = malloc(width * height * sizeof(Cell));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cells[y * width + x].position =
                    (Vector2) {(float) (x * scale + rand() % scale),
                               (float) (y * scale + rand() % scale)};
            cells[y * width + x].value = inputMap[y * width + x];
        }
    }

    int *map = malloc(mapWidth * mapHeight * sizeof(int));
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            int nearestDistance = 99999;
            int cellIndex = 0;
            map[y * mapWidth + x] = rand() % 10;


            for (int i = 0; i < width * height; i++) {
                int distX = abs(x - (int) cells[i].position.x);
                int distY = abs(y - (int) cells[i].position.y);
                int dist = distX + distY;
                if (nearestDistance > dist) {
                    nearestDistance = dist;
                    cellIndex = i;
                }
            }
            map[y * mapWidth + x] = cellIndex;
        }
    }

    Rectangle *regions = malloc(width * height * sizeof(Rectangle));
    for (int i = 0; i < width * height; i++) {
        regions[i].x = 999999;
        regions[i].y = 999999;
        regions[i].width = 0;
        regions[i].height = 0;
    }

    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            int index = map[y * mapWidth + x];
            if ((int)regions[index].x > x) regions[index].x = x;
            if ((int)regions[index].y > y) regions[index].y = y;
            if ((int)regions[index].width < x) regions[index].width = x;
            if ((int)regions[index].height < y) regions[index].height = y;
        }
    }

    FILE *file;
    fopen_s(&file, "MAP DATA", "w");

    fprintf(file, "width: %d, height: %d, scale: %d\n", mapWidth, mapHeight, scale);

    for (int i = 0; i < width * height; i++) {
        fprintf_s(file, "%d, %d, %d, %d, ", (int)regions[i].x, (int)regions[i].y, (int)regions[i].width, (int)regions[i].height);
        for (int y = (int)regions[i].y; y <= (int)regions[i].height; y++) {
            for (int x = (int)regions[i].x; x <= (int)regions[i].width; x++) {
                fprintf_s(file, "%d, ", map[y * mapWidth + x] ? 1 : 0);
            }
        }
        fputc('\n', file);
    }

    if (cells)
        free(cells);
    if (map)
        free(map);
    fclose(file);
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_CREATION_UPDATE() {
    ChangeScene(SCENE_WorldViewer);
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_CREATION_RENDER() {
    return RETURN_SUCCESS;
}

SCENE_METHOD SCENE_WORLD_CREATION_CLOSE() {
    return RETURN_SUCCESS;
}

