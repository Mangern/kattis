#include <bits/stdc++.h>
using namespace std;

#define int long long
 
 
int solve(int n, int k, int start = 0, int mult = 1, int add = 0) {
    int tot = (n>>1) + (n & start & 1);
    if (k <= tot)return (k + k - start) * mult + add;
    return solve((n + 1 - start)>>1, k - tot, start ^ (n & 1), mult<<1, add + mult * (start - 1)); 
}
 
signed main() {
    int n;
    cin >> n;
    cout << solve(n, n) << endl;
    return 0;
}
