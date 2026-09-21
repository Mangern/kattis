#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> d(n);
    for (auto & x: d) cin >> x;

    int l = 0;
    for (int i = n - 1; i >= 0; --i) {
        int need_children = d[i] - (i > 0);

        if (l < need_children) {
            cout << "NO" << endl;
            return 0;
        }
        l -= need_children;
        l += 1;
    }

    cout << (l == 1 ? "YES" : "NO") << endl;
}
