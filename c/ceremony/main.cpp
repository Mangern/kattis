#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;

    sort(begin(a), end(a));
    int ans = n;

    for (int i = 0; i < n; ++i) {
        ans = min(ans, a[i] + n - 1 - i);
    }
    cout << ans << endl;
}
