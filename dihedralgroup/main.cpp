#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ,m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto & x : b) cin >> x;

    int cut = find(begin(a), end(a), b[0]) - begin(a);
    vector<int> rot;
    for (int i = cut; i < n; ++i)rot.push_back(a[i]);
    for (int i = 0; i < cut; ++i)rot.push_back(a[i]);
    a = rot;

    bool good=1;
    for (int i = 0; i < m; ++i) {
        if (b[i] != a[i]) {
            good=0;
            break;
        }
    }
    if (good) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        if (i >= n-i) break;
        swap(a[i], a[n-i]);
    }
    good=1;
    for (int i = 0; i < m; ++i) {
        if (b[i] != a[i]) {
            good=0;
            break;
        }
    }
    cout << good << endl;
}
