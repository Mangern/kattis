#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <array>
#include <cmath>

using namespace std;

float rd(float x) {
    int val = round(x * 100);
    return (float)val / 100.0;
}

void test_case() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    if (x1 == x2 && x3 == x4) {
        // Both vertical
        if (x1 != x3) {
            printf("none\n");
            return;
        }
        if (y2 < y1)swap(y1, y2);
        if (y4 < y3)swap(y3, y4);

        if (y4 < y1 || y2 < y3) {
            printf("none\n");
            return;
        }

        if (y4 == y1) {
            printf("%.2f %.2f\n", rd(x1), rd(y1));
            return;
        }

        if (y2 == y3) {
            printf("%.2f %.2f\n", rd(x2), rd(y2));
            return;
        }

        vector<float> ys = {(float)y1, (float)y2, (float)y3, (float)y4};
        sort(begin(ys), end(ys));

        printf("%.2f %.2f %.2f %.2f\n", rd(x1), rd(ys[1]), rd(x1), rd(ys[2]));
        return;
    }

    if (x1 == x2 || x3 == x4) {
        if (x3 == x4) {
            swap(x1, x3);
            swap(x2, x4);
            swap(y1, y3);
            swap(y2, y4);
        }
        // first seg is vertical
        if (min(x3, x4) > x1 || max(x3, x4) < x1) {
            printf("none\n");
            return;
        }

        if (y1 > y2)swap(y1, y2);

        // Translate to origin
        x3 -= x1;
        x4 -= x1;

        y3 -= y1;
        y4 -= y1;
        y2 -= y1;

        float a = (float)(y4 - y3) / ((float)x4 - x3);
        float b = - a * (float)x3 + (float)y3;

        if (b < -1e-6 || b - (float)y2 > 1e-6) {
            printf("none\n");
            return;
        }

        printf("%.2f %.2f\n", rd(x1), rd(b+y1));
        return;
    }

    if (x2 < x1) {
        swap(x1, x2);
        swap(y1, y2);
    }

    if (x4 < x3) {
        swap(x3, x4);
        swap(y3, y4);
    }

    if (x3 < x1) {
        swap(x1, x3);
        swap(x2, x4);
        swap(y1, y3);
        swap(y2, y4);
    }

    if (x2 < x3) {
        printf("none\n");
        return;
    }

    // Assume no vertical lines

    float a1 = (float)(y2 - y1) / ((float)x2 - x1);
    float b1 = - a1 * (float)x1 + (float)y1;

    float a2 = (float)(y4 - y3) / ((float)x4 - x3);
    float b2 = - a2 * (float)x3 + (float)y3;

    if ((y2 - y1) * (x4 - x3) == (y4 - y3) * (x2 - x1)) {
        // parallell

        if (b1 != b2) {
            printf("none\n");
            return;
        }

        if (x2 == x3) {
            printf("%.2f %.2f\n", rd(x3), rd(y3));
            return;
        }

        vector<array<float, 2>> pts = {
            {(float)x1, (float)y1},
            {(float)x2, (float)y2},
            {(float)x3, (float)y3},
            {(float)x4, (float)y4},
        };

        sort(begin(pts), end(pts));

        printf("%.2f %.2f %.2f %.2f\n", rd(pts[1][0]), rd(pts[1][1]), rd(pts[2][0]), rd(pts[2][1]));
        return;
    }

    float x_inter = (b2 - b1) / (a1 - a2);
    float y_inter = a1 * x_inter + b1;

    if (x_inter == -0.0)x_inter = 0.0;
    if (y_inter == -0.0)y_inter = 0.0;


    if ((x2 == x3 && y2 == y3) || (x2 == x4 && y2 == y4)) {
        printf("%.2f %.2f\n", rd(x2), rd(y2));
        return;
    }

    if ((x1 == x3 && y1 == y3) || (x1 == x4 && y1 == y4)) {
        printf("%.2f %.2f\n", rd(x1), rd(y1));
        return;
    }


    constexpr float PREC = 1e-6;
    if ((float)x1 - x_inter > PREC || x_inter - (float)x2 > PREC 
    || (float)x3 - x_inter > PREC || x_inter - (float)x4 > PREC) {
        printf("none\n");
        return;
    }

    //printf("%.8f\n", rd(x_inter));
    printf("%.2f %.2f\n", rd(x_inter), rd(y_inter));

    //printf("%.2f %.2f\n", x_inter + 0.000001, y_inter + 0.000001);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while (t-->0)test_case();
}
