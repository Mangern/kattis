#include <bits/stdc++.h>
using namespace std;

int main() {
    int  n, m;
    cin >> n >> m;

    vector<int> t(1000, 0);

    vector<int> pos(n);

    for (int i = 0; i < n; ++i) {
        cin >> pos[i], --pos[i];
    }
    for (int i = 0; i < m; ++i) {
        int tr;
        cin >> tr;
        t[tr-1] = 1;
    }

    for (int p : pos) {
        int dl = 2000;
        for (int l = p; l >= 0; --l) {
            if (t[l]) {
                dl = p - l;
                break;
            }
        }
        int dr = 2000;
        for (int r = p+1; r < t.size(); ++r) {
            if (r - p >= dl)break;
            if (t[r]) {
                dr = r - p;
                break;
            }
        }
        if (dl < dr) {
            ++t[p-dl];
        } else if (dr < dl) {
            ++t[p+dr];
        }
    }

    int g=0;
    for (int tr : t)g+=(tr>1);

    cout << n - g << endl;
}
