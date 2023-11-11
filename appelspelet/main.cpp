#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e5+1;

int dp[mxN];
bitset<mxN> st;

int main() {
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;

    int n = 1000000;
    cin >> n;

    if ((n+1)&1) {
        cout << "beata" << endl;
        return 0;
    }

    for (int i = 3; i <= ((n+1)>>1); ++i) {
        st.reset();
        for (int j = 0; j < i - 2; ++j) {
            int r = dp[j] ^ dp[i - j - 3];
            st.set(r);
        }
        st.flip();
        dp[i] = st._Find_first();
    }

    int e = (n >> 1);
    int o = ((n+1)>>1);

    int r = dp[e]^dp[o];
    if (r) {
        cout << "alf" << endl;
    } else {
        cout << "beata" << endl;
    }
}
