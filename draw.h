//
// Created by marcs on 22.03.2024.
//

#ifndef GRAFIK_PROG1_DRAW_H
#define GRAFIK_PROG1_DRAW_H

#define X_SIZE 400
#define Y_SIZE 400
#define RADIUS  ((X_SIZE-1) / 2)
#define FULL_CIRCLE_ANGLE 360

typedef struct {
    int x;
    int y;
} Point_t;

void printShape(char map[Y_SIZE][X_SIZE]);
void drawLine(int x1, int y1, int x2, int y2, char map[Y_SIZE][X_SIZE]);
void drawCircle(int xc, int yc, int r, char map[Y_SIZE][X_SIZE]);
void drawShape(int N, Point_t points[N], char map[Y_SIZE][X_SIZE]);
void setPixel(int x, int y, char map[Y_SIZE][X_SIZE]);

#endif //GRAFIK_PROG1_DRAW_H
