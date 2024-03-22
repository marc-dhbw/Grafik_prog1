//
// Created by marcs on 22.03.2024.
//
#include <stdio.h>
#include <math.h>
#include "draw.h"

void setPixel(int x, int y){

}
void printShape(char map[HEIGHT+1][WIDTH+1]){
    for (int i = 0; i < HEIGHT+1; ++i) {
        for (int j = 0; j < WIDTH+1; ++j) {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

void drawLine(int x1, int y1, int x2, int y2,char map[HEIGHT+1][WIDTH+1]) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (1) {
        // Draw the current point (x1, y1)
        map[y1][x1] = '#';
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

void drawCircle(int xc, int yc, int r,char map[HEIGHT+1][WIDTH+1]) {
}