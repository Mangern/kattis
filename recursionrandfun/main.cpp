#include <bits/stdc++.h>
using namespace std;

const int mxN = 105;
const int mxK = 2050;

bitset<mxK> dp[mxN];

int a,b,c;

int main() {
    int im,k;
    dp[0].set(1);
    while (cin >> a) {
        cin >> b >> c >> im >> k;

        for (int i = 1; i <= im; ++i) {
            dp[i].reset();
            for (int rc = 0; rc < c; ++rc) {
                for (int x = 0; x < mxK; ++x) if (dp[max(0,i-1-rc)].test(x)) {
                    for (int rb = 0; rb < b; ++rb) {
                        dp[i].set(a + rb + x);
                    }
                }
            }
        }

        cout << ((k < mxK && dp[im].test(k)) ? "" : "im") << "possible" << endl;
    }
}
