#include <bits/stdc++.h>
using namespace std;

struct vec {
    double x;
    double y;

    vec operator-(const vec& other) {
        return {x-other.x, y-other.y};
    }

    vec operator+(const vec& other) {
        return {x+other.x, y+other.y};
    }

    void operator*=(const double& s) {
        x *= s;
        y *= s;
    }

    double norm() {
        return hypot(x,y);
    }

    void normalize() {
        double len = hypot(x,y);
        x /= len;
        y /= len;
    }

    void rotate(double alpha) {
        double rx = cos(alpha) * x - sin(alpha) * y;
        double ry = sin(alpha) * x + cos(alpha) * y;
        x = rx;
        y = ry;
    }
};

int main() {
    int n;
    cin >> n;

    double t;
    cin >> t;

    vector<vec> row;
    row.push_back({0,0});

    for (int i = 0; i < n - 1; ++i) {
        double a;
        cin >> a;

        row.push_back({row.back().x + a, 0});
    }

    while (row.size() > 1) {
        vector<vec> nrow;

        for (int i = 0; i < row.size() - 1; ++i) {
            auto v1 = row[i];
            auto v2 = row[i+1];

            auto dv = v2 - v1;

            double d = dv.norm();

            double alpha = acos(d / (2 * t));

            dv.normalize();
            dv.rotate(alpha);
            dv *= t;
            nrow.push_back(v1 + dv);
        }
        swap(row,nrow);
    }

    cout << setprecision(15) << fixed << row[0].y << endl;
}
