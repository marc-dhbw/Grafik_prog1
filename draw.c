//
// Created by marcs on 22.03.2024.
//
#include <stdio.h>
#include <math.h>
#include "draw.h"

void printShape(char map[Y_SIZE][X_SIZE]){
    for (int i = 0; i < Y_PIXEL + 1; ++i) {
        for (int j = 0; j < X_PIXEL + 1; ++j) {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

void setPixel(int x, int y, char map[Y_SIZE][X_SIZE]){
    map[y][x] = '#';
}

void drawLine(int x1, int y1, int x2, int y2,char map[Y_SIZE][X_SIZE]) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (1) {
        // Draw the current point (x1, y1)
        setPixel(x1,y1,map);
        //printf("(%d, %d)\n", x1, y1);
        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}
void drawCircle(int x0, int y0, int radius,char map[Y_SIZE][X_SIZE]){
    int f = 1 - radius;
    int ddF_x = 0;
    int ddF_y = -2 * radius;
    int x = 0;
    int y = radius;

    setPixel(x0, y0 + radius,map);
    setPixel(x0, y0 - radius,map);
    setPixel(x0 + radius, y0,map);
    setPixel(x0 - radius, y0,map);

    while(x < y)
    {
        if (f >= 0)
        {
            y -= 1;
            ddF_y += 2;
            f += ddF_y;
        }
        x += 1;
        ddF_x += 2;
        f += ddF_x + 1;

        setPixel(x0 + x, y0 + y,map);
        setPixel(x0 - x, y0 + y,map);
        setPixel(x0 + x, y0 - y,map);
        setPixel(x0 - x, y0 - y,map);
        setPixel(x0 + y, y0 + x,map);
        setPixel(x0 - y, y0 + x,map);
        setPixel(x0 + y, y0 - x,map);
        setPixel(x0 - y, y0 - x,map);
    }
}