#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ld = long double;

const ld EPS = 1e-10;

ld x[3];
ld y[3];

ld evalxy(ld xv, ld yv) {
    return hypot(xv - x[0], yv - y[0])
        +  hypot(xv - x[1], yv - y[1])
        +  hypot(xv - x[2], yv - y[2]);
}

ld xl, xh;
ld evalx(ld yv) {
    xl = *min_element(x,x+3);
    xh = *max_element(x,x+3);

    while (xh - xl > EPS) {
        ld lft = (2 * xl + xh) / 3.0;
        ld rgt = (xl + 2 * xh) / 3.0;

        if (evalxy(lft, yv) > evalxy(rgt, yv)) {
            xl = lft;
        } else {
            xh = rgt;
        }
    }
    return evalxy(xl, yv);
}

int main() {
    cin >> x[0] >> y[0];
    cin >> x[1] >> y[1];
    cin >> x[2] >> y[2];

    ld yl = *min_element(y,y+3);
    ld yh = *max_element(y,y+3);

    while (yh - yl > EPS) {
        ld lft = (2 * yl + yh) / 3.0;
        ld rgt = (yl + 2 * yh) / 3.0;

        if (evalx(lft) > evalx(rgt)) {
            yl = lft;
        } else {
            yh = rgt;
        }
    }

    cout << setprecision(9) << fixed << xl << " " << yl << endl;
}
