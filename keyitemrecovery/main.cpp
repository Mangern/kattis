#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (auto &r : a) {
        for (auto &x : r)cin >> x;
    }

    vector<int> par(n+1);

    for (int i = 2; i <= n; ++i) {
        int mx = 0;
        for (int j = 0; j < i-1; ++j) {
            mx = max(mx, a[i-1][j]);
        }
        par[i-1] = mx;
    }

    for (int i = 2; i <= n; ++i) {
        cout << par[i-1] << " " << i << endl;
    }
}
