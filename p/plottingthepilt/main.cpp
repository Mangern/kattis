#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m, d;
    cin >> n >> m >> d;

    vector<vector<ll>> a(n, vector<ll>(m, 0));
    vector<vector<ll>> k(n, vector<ll>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];

            ll &kv = k[i][j];
            while ((kv+1)*d<=a[i][j])++kv;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll mk = 100000;
            if (i>0)mk=min(mk,k[i-1][j]);
            if (j>0)mk=min(mk,k[i][j-1]);
            if (i<n-1)mk=min(mk,k[i+1][j]);
            if (j<m-1)mk=min(mk,k[i][j+1]);
            if (k[i][j]<=mk)cout << ' ';
            else if (k[i][j] == mk+1)cout << '+';
            else if (k[i][j] == mk+2)cout << 'X';
            else cout << '#';
        }
        cout << endl;
    }
}
