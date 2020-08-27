//
// Created by Bill on 21/08/2020.
//

#include "ProceduralGeneration.h"

Color *GenerateCellVoronoiTexture(const int *map, int width, int height, int scale, int* regionMap) {
    Vector2 *cellPositions = malloc(width * height * sizeof(Vector2));
    Color *cellColours = malloc(width * height * sizeof(Color));
    int textureWidth = width * scale;
    int textureHeight = height * scale;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cellPositions[y * width + x] =
                    (Vector2) {(float) (x * scale + rand() % scale),
                               (float) (y * scale + rand() % scale)};
            //cellColours[y * data->width + x] = data->map[y * data->width + x] ? GREEN : BLUE;
            cellColours[y * width + x] = map[y * width + x] ? GREEN : BLUE;
        }
    }

    Color *pixels = malloc(textureWidth * textureHeight * sizeof(Color));

    for (int y = 0; y < textureHeight; y++) {
        for (int x = 0; x < textureWidth; x++) {
            int closestDistance = 999;
            int cellIndex = 0;
            for (int i = 0; i < width * height; i++) {
                int distanceX = //abs((x - cellPositions[i].x) * (x - cellPositions[i].x))
                        abs(x - (int) cellPositions[i].x);
                int distanceY = //abs((y - cellPositions[i].y) * (y - cellPositions[i].y))
                        abs(y - (int) cellPositions[i].y);

                int dist = distanceX + distanceY;
                if (closestDistance > dist) {
                    closestDistance = dist;
                    cellIndex = i;
                }
            }

            if (map[cellIndex])
                regionMap[y * textureWidth + x] = cellIndex;
            else
                regionMap[y * textureWidth + x] = -1;



            Color colour = cellColours[cellIndex];
            pixels[y * textureWidth + x] = colour;
        }
    }

    for (int y = 0; y < textureHeight; y++) {
        for (int x = 0; x < textureWidth; x++) {
            //if (regionMap[y * textureWidth + (x - 1)] < 0)
                //continue;
            bool border = false;
            if (x > 0 && regionMap[y * textureWidth + (x - 1)] > 0)
                border += regionMap[y * textureWidth + (x - 1)] != regionMap[y * textureWidth + x];
            if (y > 0 && regionMap[(y - 1) * textureWidth + x] > 0)
                border += regionMap[(y - 1) * textureWidth + x] != regionMap[y * textureWidth + x];
            if (x < textureWidth && regionMap[y * textureWidth + (x + 1)] > 0)
                border += regionMap[y * textureWidth + (x + 1)] != regionMap[y * textureWidth + x];
            if (y < textureWidth && regionMap[(y + 1) * textureWidth + x] > 0)
                border += regionMap[(y + 1) * textureWidth + x] != regionMap[y * textureWidth + x];

            if (x > 0 && y > 0 && regionMap[(y - 1) * textureWidth + (x - 1)] > 0)
                border += regionMap[(y - 1) * textureWidth + (x - 1)] != regionMap[y * textureWidth + x];
            if (x < textureWidth && y > 0 && regionMap[(y - 1) * textureWidth + (x + 1)] > 0)
                border += regionMap[(y - 1) * textureWidth + (x + 1)] != regionMap[y * textureWidth + x];
            if (x > 0 && y < textureHeight && regionMap[(y + 1) * textureWidth + (x - 1)] > 0)
                border += regionMap[(y + 1) * textureWidth + (x - 1)] != regionMap[y * textureWidth + x];
            if (x < textureWidth && y < textureWidth && regionMap[(y + 1) * textureWidth + (x + 1)] > 0)
                border += regionMap[(y + 1) * textureWidth + (x + 1)] != regionMap[y * textureWidth + x];

            if (border) {
                pixels[y * textureWidth + x] = DARKGREEN;
                regionMap[y * textureWidth + x] = -1;
            }
        }
    }

    return pixels;
}

Color *GenerateRandomVoronoiTexture(const int *map, int width, int height, int pointCount, int scale) {
    Vector2 *cellPositions = malloc(pointCount * sizeof(Vector2));
    Color *cellColours = malloc(pointCount * sizeof(Color));
    for (int i = 0; i < pointCount; i++) {
        int x = rand() % width;
        int y = rand() % height;

        cellPositions[i] = (Vector2){x, y};
        int cell = map[(y / scale) * (width / scale) + (x / scale)];
        cellColours[i] = cell ? GREEN : BLUE;
    }

    Color *pixels = malloc(width * height * sizeof(Color));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int closestDistance = 999;
            int cellIndex = 0;
            for (int i = 0; i < pointCount; i++) {
                int distanceX = //abs((x - cellPositions[i].x) * (x - cellPositions[i].x))
                        abs(x - (int) cellPositions[i].x);
                int distanceY = //abs((y - cellPositions[i].y) * (y - cellPositions[i].y))
                        abs(y - (int) cellPositions[i].y);

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

    return pixels;
}

/*
void ExportGeneratedMap(const char *filename, const int *inputMap, int width, int height, int scale) {
    Vector2 cellPositions[width * height];
    int cellValues[width * height];
    int mapWidth = width * scale;
    int mapHeight = width * height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cellPositions[y * width + x] = (Vector2){
                x * scale + rand() % scale,
                y * scale + rand() % scale
            };

            cellValues[y * width + x] = inputMap[y * width + x];
        }
    }

    int map[mapWidth * mapHeight];
    for (int x = 0; x < mapWidth; x++) {
        for (int y = 0; y < mapHeight; y++) {
            int closestDistance = 999;
            int cellIndex = 0;
            for (int i = 0; i < width * height; i++) {
                int distanceX = //abs((x - cellPositions[i].x) * (x - cellPositions[i].x))
                        abs(x - (int) cellPositions[i].x);
                int distanceY = //abs((y - cellPositions[i].y) * (y - cellPositions[i].y))
                        abs(y - (int) cellPositions[i].y);

                int dist = distanceX + distanceY;
                if (closestDistance > dist) {
                    closestDistance = dist;
                    cellIndex = i;
                }
            }

            map[x * y] = cellIndex;
        }
    }
}
 */
