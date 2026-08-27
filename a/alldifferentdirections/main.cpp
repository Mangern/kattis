#include <bits/stdc++.h>
using namespace std;

struct point {
    double x;
    double y;
};

int main() {
    string line;
    for (;;) {
        getline(cin, line);
        int n = stoi(line);
        if (!n) break;

        vector<point> dirs;


        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            stringstream ss(line);
            point p;
            double dir;
            ss >> p.x >> p.y;
            string instr;
            double param;

            while (ss >> instr) {
                ss >> param;

                if (instr == "start") {
                    dir = param * M_PI / 180;
                } else if (instr == "walk") {
                    p.x += param * cos(dir);
                    p.y += param * sin(dir);
                } else if (instr == "turn") {
                    dir += param * M_PI / 180;
                }
            }
            dirs.push_back(p);
        }

        point avg{0,0};

        for (auto [x, y] : dirs) {
            avg.x+=x;
            avg.y+=y;
        }
        avg.x /= n;
        avg.y /= n;

        double far =0.0;
        for (auto [x, y] : dirs) {
            far = max(far, hypot(x-avg.x,y-avg.y));
        }
        cout << setprecision(5) << fixed << avg.x << " " << avg.y << " " << far << endl;
    }
}
