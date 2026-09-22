#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(a.rbegin(), a.rend());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i + 1 >= a[i]) {
            ans = max(ans, a[i]);
        } else {
            ans = max(ans, i+1);
        }
    }
    cout << ans << endl;
}
