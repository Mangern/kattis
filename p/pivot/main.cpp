#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a)cin >> x;

    multiset<int> left, right;

    for (int i = 0; i < n; ++i)right.insert(a[i]);

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        right.erase(right.find(a[i]));

        if ((i == 0 || *--left.end() <= a[i]) && (i == n - 1 || *right.begin() > a[i]))++ans;
        left.insert(a[i]);
    }
    cout << ans << endl;
}
