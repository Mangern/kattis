#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e5+5;

int n, c,b;
int ans[mxN];
int broken[mxN];

int main() {
    cin >> n >> c >> b;

    for (int i = 0; i < b; ++i) {
        int j;
        cin >> j, --j;
        broken[j] = 1;
    }

    int start = 1;
    if (c & 1) {
        ans[0] = 1;
        ans[1] = 0;
        start = 2;
        c -= 1;
    }

    for (int i = start; i < n; ++i) {
        if (!broken[i] && c > 0) {
            ans[i] = 1;
            ans[i+1] = 0;
            ++i;
            c -= 2;
        }
    }

    for (int i = 0 ; i < n; ++i)cout << ans[i];
    cout << endl;
}
