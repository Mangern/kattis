#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;

    vector<double> w(n);
    double b;
    for (auto &x : w) cin >> x;
    cin >> b;

    double wlen = 0;

    for (auto x : w)wlen += x * x;
    wlen = sqrt(wlen);

    vector<double> x(n);
    for (;;) {
        if (!(cin >> x[0])) break;

        for (int i = 1; i < n; ++i) cin >> x[i];

        double dot = 0.0;
        for (int i = 0; i < n; ++i) {
            dot += x[i] * w[i];
        }
        dot += b;

        dot /= wlen;

        cout << setprecision(8) << fixed << dot << '\n';
    }
}
