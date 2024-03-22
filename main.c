#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "draw.h"
#define MYFILENAME "graphic.ppm"

double toRadians(double angle) {
    return angle / 180 * M_PI;
}

void fillArr(char map[HEIGHT+1][WIDTH+1]){
    for (int i = 0; i < HEIGHT+1; ++i) {
        for (int j = 0; j < WIDTH+1; ++j) {
            map[i][j] = '.' ;
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
        printf("fraction angle: %lf\n", temp);
        printf("calc: %d %d\n", x, y);
    }
}

void transformCoordinates(int N, Point_t points[N], int distance) {
    for (int i = 0; i < N; ++i) {
        points[i].x += distance;
        points[i].y += distance;
    }
}

void connectAllPoints(int N, Point_t points[N], char map[HEIGHT + 1][WIDTH + 1]){
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            drawLine(points[i].x,points[i].y,points[j].x,points[j].y,map);
        }
    }
}

void saveToFile(char map[HEIGHT + 1][WIDTH + 1]){
    FILE *fp;
    fp = fopen(MYFILENAME,"w");
    if(fp){
        fprintf(fp,"P3\n%d %d\n255\n",HEIGHT,WIDTH);
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                if(map[i][j] == '#') {
                    fprintf(fp, "255 255 255 ");
                }else{
                    fprintf(fp,"  0   0   0   ");
                }
            }
            fprintf(fp,"\n");
        }
        rewind(fp);
    }
    fclose(fp);
}



int main() {
    char map[HEIGHT+1][WIDTH+1];
    fillArr(map);
    int N = 45;
    //scanf_s("%d", &N);
    Point_t points[N];
    calculatePointsOnCircle(N, points);
    transformCoordinates(N, points, RADIUS);
    for (int i = 0; i < N; ++i) {
        Point_t temp = points[i];
        printf("transformed %d %d\n", temp.x, temp.y);
        map[temp.y][temp.x] = '#';
        printf("%d\n",i);
    }
    connectAllPoints(N, points, map);
    saveToFile(map);


    printf("N=%d", N);
    return 0;
}
