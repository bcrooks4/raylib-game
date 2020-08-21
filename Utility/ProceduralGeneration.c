//
// Created by Bill on 21/08/2020.
//

#include "ProceduralGeneration.h"

Color *GenerateVoronoiTexture(const int *map, int width, int height, int scale) {
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

            Color colour = cellColours[cellIndex];
            pixels[y * textureWidth + x] = colour;
        }
    }
    return pixels;
}
