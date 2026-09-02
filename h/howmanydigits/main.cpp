#include <bits/stdc++.h>
using namespace std;
using ld = long double;

const int mxN = 1e6+5;
ld ans[mxN];

int main() {
    ans[0] = 0.0;
    for (int i = 1; i < mxN; ++i) {
        ans[i] = ans[i-1] + log10((ld)i);
    }
    ans[0] = 1.0;
    ans[1] = 1.0;
    int n;
    while (cin >> n) {
        long long ret = ceil(ans[n]);
        cout << ret << endl;
    }
}
