#include <array>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;


// x, y, theta
array<double, 3> sim(const vector<ii>& prog, float init_t) {
    double x = 0;
    double y = 0;
    double t = init_t;

    for (auto [typ, arg] : prog) {
        if (typ == 0) {
            x += cos(t * M_PI / 180.0) * arg;
            y += sin(t * M_PI / 180.0) * arg;
        } else if (typ == 1) {
            t += arg;
        } else if (typ == 2) {
            x -= cos(t * M_PI / 180.0) * arg;
            y -= sin(t * M_PI / 180.0) * arg;
        } else {
            t -= arg;
        }
    }
    return {x, y, t};
}

void test_case() {
    int n;
    cin >> n;

    vector<ii> prog;
    // fd = 0, lt = 1
    int unk_i = 0;
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;

        int t = (a == "fd" ? 0 : (a == "lt" ? 1 : (a == "bk" ? 2 : 3)));

        if (b == "?") {
            prog.push_back({t, 0});
            unk_i = i;
            continue;
        }
        prog.push_back({t, stoll(b)});
    }

    if (prog[unk_i][0] == 0 || prog[unk_i][0] == 2) {
        auto [x, y, t] = sim(prog, 0);
        printf("%.0lf\n", sqrt(x * x + y * y));
    } else {
        for (int d = 0; d < 360; ++d) {
            prog[unk_i][1] = d;
            auto [x, y, t] = sim(prog, 0);
            if (x * x + y * y < 1e-6) {
                cout << d << endl;
                break;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t-->0)test_case();
}
