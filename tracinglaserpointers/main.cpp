#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;

    cin >> n;

    vector<pair<double, string>> hit;

    for (int i = 0; i < n; ++i) {
        double x, y, m;
        cin >> x >> y >> m;
        string s;
        cin >> s;

        if (y < 0) {
            y = -y;
            m = -m;
        }

        if (m >= 0) continue;

        // f(x) = mx+b
        // f(x)=y
        // mx+b=y
        // b=y-mx
        // f(x) = 0 => mx = -b
        //          => x = -b/m
        double b = y - m * x;
        hit.push_back({-b/m, s});
    }

    sort(begin(hit), end(hit));

    for (auto [_, s] : hit)cout << s << endl;
}
