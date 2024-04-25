#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using ld = long double;

int main() {
    while (true) {
        ld w, h, x, y, s, r;
        cin >> w >> h >> x >> y >> s >> r;

        if (!w)break;

        s /= 100.0;

        r /= 360.0;
        r *= 2 * M_PI;

        ld a11 = 1 - s * cos(r);
        ld a12 = s * sin(r);
        ld a21 = - s * sin(r);
        ld a22 = 1 - s * cos(r);

        ld d = (a11 * a22 - a12 * a21);

        ld ai11 = a22 / d;
        ld ai12 = -a12 / d;
        ld ai21 = -a21 / d;
        ld ai22 = a11 / d;

        ld ax = ai11 * x + ai12 * y;
        ld ay = ai21 * x + ai22 * y;

        cout << setprecision(2) << fixed << ax << " " << ay << endl;

    }
    return 0;
}
