#include <bits/stdc++.h>
using namespace std;

// p_win[n][m]: Probability of winning using an n-sided dice against an m-sided dice
double p_win[31][31];

void pre() {
    for (int n = 1; n <= 30; ++n) {
        for (int m = 1; m <= 30; ++m) {
            double s_win = 0.0;
            double s_tot = 0.0;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (i > j)s_win += 1.0;
                    s_tot += 1.0;
                }
            }
            p_win[n][m] = s_win / s_tot;
        }
    }
}

int main() {
    pre();
    int n, m;
    cin >> n >> m;

    const int chain[] = {3,4,5,6,7,8,10,12,14,16,20,24,30};
    const int N = sizeof(chain) / sizeof(int);
    int ni;

    for (int i = 0; i < N; ++i) {
        if (chain[i] == n)ni = i;
    }

    double p;
    cin >> p;
    p /= 100.0;

    for (int k = 0; ni + k < N; ++k) {
        if (p_win[chain[ni+k]][m] >= p) {
            cout << k << endl;
            return 0;
        }
    }
    cout << "Vonlaust!" << endl;
}
