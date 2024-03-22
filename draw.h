//
// Created by marcs on 22.03.2024.
//

#ifndef GRAFIK_PROG1_DRAW_H
#define GRAFIK_PROG1_DRAW_H

#define WIDTH 1000
#define HEIGHT 1000
#define RADIUS  WIDTH / 2
#define FULL_CIRCLE_ANGLE 360

typedef struct {
    int x;
    int y;
} Point_t;

void printShape(char map[HEIGHT + 1][WIDTH + 1]);
void drawLine(int x1, int y1, int x2, int y2, char map[HEIGHT + 1][WIDTH + 1]);
void drawCircle(int xc, int yc, int r, char map[HEIGHT + 1][WIDTH + 1]);
void setPixel(int x, int y);

#endif //GRAFIK_PROG1_DRAW_H
