//
// Created by Bill on 20/08/2020.
//

#ifndef RAYLIB_GAME_PROCEDURALGENERATION_H
#define RAYLIB_GAME_PROCEDURALGENERATION_H

#include "../Engine/Engine.h"

Color *GenerateCellVoronoiTexture(const int *map, int width, int height, int scale, int* regionMap);
Color *GenerateRandomVoronoiTexture(const int *map, int width, int height, int pointCount, int scale);
void ExportGeneratedMap(const char *filename, const int *inputMap, int width, int height, int scale);

#endif //RAYLIB_GAME_PROCEDURALGENERATION_H
