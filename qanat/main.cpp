#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define double long double

double err = 0.00000004;

unordered_map<double,double> dp[1004];
unordered_map<double,double> dpx[1004];

double save[1004];


double calculate(double h, double x) {
    double l = h+1-x+x*h;
    double l1 = l / 2;
    double l2 = x*h;
    return (l1*l1 - l2*l2*0.5);
}

double solve(double w, double h, int n) {
    double f = w;
    w /= f;
    h /= f;

    if (dp[n].count(h)) {
        save[n-1] = dpx[n][h] * f;
        return dp[n][h] * f * f;
    }

    if (n == 0) {
        double ans = ((1.0+h)/2) * ((1.0+h)/2);
        dp[n][h] = ans;

        return ans * f * f;
    }

    double lo = 0.0;
    double hi = 1.0;

    double sres;

    while (hi - lo > err) {
        double x1 = (2*lo+hi)/3;
        double hx1 = (h*x1);
        double res1 = solve(x1, hx1, n-1) + calculate(h, x1);

        double x2 = (lo+2*hi)/3;
        double hx2 = (h*x2);
        double res2 = solve(x2, hx2, n-1) + calculate(h, x2);

        if (res1 > res2) {
            lo = x1;
        } else {
            hi = x2;
        }
    }
    double mid = (lo+hi)/2;
    sres = solve(mid, mid*h, n-1)+calculate(h, mid);

    dp[n][h] = sres;
    dpx[n][h] = mid;
    save[n-1] = mid * f;
    return sres * f * f;
}

int main() {
    double w, h;
    int n;
    cin >> w >> h >> n;

    cout << setprecision(6) << fixed << solve(w, h, n) << endl;

    if (n >= 2) {
        save[n] = w;
        for (int i = n - 2; i >= 0; --i)save[i] *= save[i+2];
    }

    for (int i = 0; i < min(10, n); ++i) {
        cout << setprecision(6) << fixed << save[i] << endl;
    }
    return 0;
}
