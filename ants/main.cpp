#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        int l, n;
        cin >> l >> n;

        vector<int> a(n);
        for (auto& x : a)cin >> x;

        int mini = 0;
        int maxi = 0;

        for (int i = 0; i < n; ++i) {
            mini = max(mini, min(a[i],l-a[i]));
            maxi = max(maxi, max(a[i],l-a[i]));
        }
        cout << mini << " " << maxi << endl;
    }
}
