#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "draw.h"

#define MYFILENAME "graphic.ppm"

double toRadians(double angle) {
    return angle / 180 * M_PI;
}

void fillArr(char map[Y_SIZE][X_SIZE]) {
    for (int i = 0; i < Y_PIXEL + 1; ++i) {
        for (int j = 0; j < X_PIXEL + 1; ++j) {
            map[i][j] = '.';
        }
    }
}

void calculatePointsOnCircle(int N, Point_t points[N]) {
    double fractionAngle = (double) FULL_CIRCLE_ANGLE / N;
    for (int i = 0; i < N; i++) {
        double temp = fractionAngle * i;
        int x = (int) ((double) RADIUS * cos(toRadians(temp)));
        int y = (int) ((double) RADIUS * sin(toRadians(temp)));
        Point_t p = {x, y};
        points[i] = p;
    }
}

void transformCoordinates(int N, Point_t points[N], int distance) {
    for (int i = 0; i < N; ++i) {
        points[i].x += distance;
        points[i].y += distance;
    }
}

void connectAllPoints(int N, Point_t *points, char map[Y_SIZE][X_SIZE]) {
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            drawLine(points[i].x, points[i].y, points[j].x, points[j].y, map);
        }
    }
}

void saveToFile(char map[Y_SIZE][X_SIZE]) {
    FILE *fp;
    fp = fopen(MYFILENAME, "w");
    if (fp) {
        fprintf(fp, "P3\n%d %d\n255\n", Y_PIXEL, X_PIXEL);
        for (int i = 0; i < Y_PIXEL; ++i) {
            for (int j = 0; j < X_PIXEL; ++j) {
                if (map[i][j] == '#') {
                    char x[100];
                    //sprintf(x, "%d %d %d ", rand(), rand(), rand());
                    fprintf(fp, "255 255 255 ");
                } else {
                    fprintf(fp, "  0   0   0   ");
                }
            }
            fprintf(fp, "\n");
        }
        rewind(fp);
    }
    fclose(fp);
}


int main() {

    assert(Y_PIXEL == X_PIXEL);
    char map[Y_SIZE][X_SIZE];
    fillArr(map);

    int N = 0;
    scanf_s("%d", &N);
    if (N <= 0) {
        printf("N sollte groesser als 0 sein");
        return 0;
    }

    Point_t *points = malloc(N * sizeof(Point_t));
    calculatePointsOnCircle(N, points);
    transformCoordinates(N, points,RADIUS); // Koordinaten werden um den Vektor(W/2,W/2) verschoben, sodass die Grafik im sichbaren bereich liegt
    for (int i = 0; i < N; ++i) {
        Point_t temp = points[i];
        setPixel(temp.x, temp.y, map);
    }
    drawCircle(RADIUS, RADIUS, RADIUS, map);
    connectAllPoints(N, points, map);
    saveToFile(map);

    free(points);
    printf("File successfully created with N=%d", N);
    return 0;
}
