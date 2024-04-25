#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "draw.h"

#define MYFILENAME "graphic.ppm"

void fillArr(char map[Y_SIZE][X_SIZE]) {
    for (int i = 0; i < Y_SIZE; ++i) {
        for (int j = 0; j < X_SIZE; ++j) {
            map[i][j] = '.';
        }
    }
}
void saveToFile(char map[Y_SIZE][X_SIZE]) {
    FILE *fp;
    fp = fopen(MYFILENAME, "w");
    if (fp) {
        fprintf(fp, "P3\n%d %d\n255\n", Y_SIZE , X_SIZE );
        for (int i = 0; i < Y_SIZE; ++i) {
            for (int j = 0; j < X_SIZE; ++j) {
                if (map[i][j] == '#') {
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
    assert(Y_SIZE == X_SIZE);
    char map[Y_SIZE][X_SIZE];
    fillArr(map);

    int N = 0;
    printf("N eingeben:");
    scanf_s("%d", &N);
    if (N <= 0) {
        printf("N sollte groesser als 0 sein");
        return 0;
    }

    Point_t *points = malloc(N * sizeof(Point_t));
    drawShape(N,points,map);
    free(points);
    saveToFile(map);

    printf("Grafik wurde erfolgreich erstellt mit N=%d", N);
    return 0;
}
