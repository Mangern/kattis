#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+5;

int p[mxN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        ++p[l];
        --p[r+1];
    }

    int cnt = 0;
    int cur = 0;
    int lo = -1;
    for (int i = 0; i < mxN; ++i) {
        cur += p[i];
        if (cur == n) {
            ++cnt;
            if (lo == -1)lo = i;
        }
    }

    if (cnt) {
        cout << cnt << " " << lo << endl;
    } else {
        cout << "bad news" << endl;
    }
}
