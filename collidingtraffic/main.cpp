#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;
const double inf = numeric_limits<double>::infinity();
const double EPS = 1e-8;

int n;
double r;
double x[mxN];
double y[mxN];
double d[mxN];
double s[mxN];
double vx[mxN];
double vy[mxN];

double coll(int i, int j) {
    if ((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]) <= r * r) return 0.0;
    double b = ((x[j] - x[i]) * (vx[j] - vx[i]) + (y[j] - y[i]) * (vy[j] - vy[i]));
    double a = (vx[j] - vx[i]) * (vx[j] - vx[i]) + (vy[j] - vy[i]) * (vy[j] - vy[i]);
    if (a < EPS) return inf;

    double t = -b / a;

    if (t < 0) return inf;

    double D = (x[j] - x[i] + (vx[j] - vx[i])*t)*(x[j] - x[i] + (vx[j] - vx[i])*t)
             + (y[j] - y[i] + (vy[j] - vy[i])*t)*(y[j] - y[i] + (vy[j] - vy[i])*t);

    if (D > r * r + EPS) return inf;

    double lo = 0;
    double hi = t;

    while (hi - lo > EPS) {
        double mid = (hi + lo) / 2.0;

        double x1 = x[j] + vx[j] * mid;
        double y1 = y[j] + vy[j] * mid;
        double x0 = x[i] + vx[i] * mid;
        double y0 = y[i] + vy[i] * mid;

        if ((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) <= r * r + EPS) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return lo;
}

void test() {
    cin >> n >> r;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> d[i] >> s[i];

        double theta = (90 - d[i]) / 180.0 * M_PI;
        vx[i] = s[i] * cos(theta);
        vy[i] = s[i] * sin(theta);
    }

    double mint = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            mint = min(mint, coll(i, j));
        }
    }

    if (mint == inf) {
        cout << "No collision." << endl;
        return;
    }
    cout << roundl(mint+EPS) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-->0)test();
}
