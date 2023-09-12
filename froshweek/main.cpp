#include <bits/stdc++.h>
using namespace std;
using ii = array<int,2>;

const int mxN = 1e6+4;

int ft[mxN];

void inc(int i) {
    for (; i < mxN; i += (i & (-i)))ft[i] += 1;
}

int below(int i) {
    int ret = 0;
    for (; i; i -= (i & (-i)))ret += ft[i];
    return ret;
}

int above(int i) {
    return below(mxN - 1) - below(i);
}

int main() {
    int n;
    cin >> n;
    vector<ii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i;
    }

    sort(begin(a), end(a));

    for (int i = 0; i < n; ++i) {
        a[i][0] = i+1;
        swap(a[i][0], a[i][1]);
    }

    sort(begin(a), end(a));

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += above(a[i][1]);
        inc(a[i][1]);
    }
    cout << ans << endl;
    return 0;
}
