#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 50;

ll dp[mxN];

int main() {
    dp[0] = 1;
    for (int i = 1; i < mxN; ++i) {
        for (int j = 1; j <= 3; ++j) if (i - j>= 0)dp[i] += dp[i-j];
    }
    int n;
    cin >> n;
    cout << dp[n] << endl;
}
