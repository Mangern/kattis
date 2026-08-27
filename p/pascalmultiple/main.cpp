#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e3+5;

ll grid[mxN][mxN];

int main() {
    ll n, k;
    cin >> n >> k;


    ll ans = 0;
    for (ll i = 0; i <= n; ++i) {
        for (ll j = 0; j <= i; ++j) {
            if (j == 0 || i == 0) {
                grid[i][j] = 1 % k;
            }
            else {
                grid[i][j] = (grid[i-1][j-1] + grid[i-1][j]) % k;
            }
            ans += (grid[i][j] == 0);
        }
    }
    cout << ans << endl;
}
