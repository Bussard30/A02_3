#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Unteraufgabe 3a)
int contained(double x, double a, double b) {
    return (x >= a && x <= b) ? 1 : 0;
}

// Unteraufgabe 3b)
int line(double x, double y, double x1, double y1, double x2, double y2) {

    return (((fabs((x2 - x1) * (y1 - y) - (x1 - x) * (y2 - y1)) /
              sqrt(pow(x2 - x1, 2) + sqrt(pow(y2 - y1, 2)))) < 0.5)
              && (x >= x1 && x <= x2 && y >= y1 && y <= y2) ? 1 : 0);
}

int line_right_to_left(double x, double y, double x1, double y1, double x2, double y2) {

    return (((fabs((x2 - x1) * (y1 - y) - (x1 - x) * (y2 - y1)) /
              sqrt(pow(x2 - x1, 2) + sqrt(pow(y2 - y1, 2)))) < 0.5)
            && (x >= x2 && x <= x1 && y >= y1 && y <= y2) ? 1 : 0);
}

int rectangle(double x, double y, double lx, double rx, double uy, double oy) {
    // p0 = lx, uy;p1 = lx, oy;p2 = rx, uy;p3 = rx, oy
    // l1 = p0-p1; l2 = p0-p2; l3 = p1-p3; l4 = p2-p3
    //printf("%d", x >= lx ? 1 : 0);
    //printf("%d", x <= rx ? 1 : 0);
    //printf("%d", y >= uy ? 1 : 0);
    //printf("%d", y <= oy ? 1 : 0);
    return ((line(x, y, lx, uy, lx, oy) == 1) ||
            (line(x, y, lx, uy, rx, uy) == 1) ||
            (line(x, y, lx, oy, rx, oy) == 1) ||
            (line(x, y, rx, uy, rx, oy) == 1)) && (x >= lx && x <= rx && y >= uy && y <= oy) ? 1 : 0;
}

int checkAllRects(double x, double y) {
    // base rect
    return (rectangle(x, y, 0, 30, 0, 15) == 1 ||
            // door
            rectangle(x, y, 12, 18, 0, 10) == 1 ||
            // left window
            rectangle(x, y, 3, 9, 5, 12) == 1 ||
            // right window
            rectangle(x, y, 21, 27, 5, 12) == 1 ||
            // rect on top
            rectangle(x, y, 9, 13, 20, 24) == 1)
           ? 1 : 0;
}

int checkAllLines(double x, double y) {
    return (line(x, y, 0, 15, 5, 20) == 1 ||
            line_right_to_left(x, y, 30, 15, 25, 20) == 1 ||
            line(x, y, 5, 20, 25, 20) == 1
           ) ? 1 : 0;
}

int draw() {
    int display[31][25];
    for (int y = 24; y >= 0; y--) {
        for (int x = 0; x < 31; x++) {
            bool draw = false;
            if (checkAllRects(x, y) == 1) draw = true;
            if (checkAllLines(x, y) == 1) draw = true;

            printf(draw ? "*" : " ");
        }
        printf("\n");
    }
}

int main() {
    printf("Starting drawing process... !\n");
    draw();
    return 0;
}
