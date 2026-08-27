#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, m;
    cin >> n >> s >> m;
    --s;

    vector<int> a(n);
    for (auto &x : a)cin >> x;

    vector<bool> vis(n, false);

    int h = 0;
    while (true) {
        if (s < 0) {
            cout << "left\n" << h << endl;
            return 0;
        }
        if (s >= n) {
            cout << "right\n" << h << endl;
            return 0;
        }
        if (a[s] == m) {
            cout << "magic\n" << h << endl;
            return 0;
        }
        if (vis[s]) {
            cout << "cycle\n" << h << endl;
            return 0;
        }

        vis[s] = 1;
        s += a[s];
        ++h;
    }
}
