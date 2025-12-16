#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 105;

ll a[mxN][mxN];

int main() {
    ll n;
    cin >> n;

    array<ll, 3> ans;
    ll ansp = 0;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (a[i][j] * a[i][k] * a[k][j] > ansp) {
                    ansp = a[i][j] * a[i][k] * a[k][j];
                    ans = {i, j, k};
                }
            }
        }
    }

    cout << ans[0]+1 << " " << ans[1]+1 << " " << ans[2]+1 << endl;

}
