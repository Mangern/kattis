#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<ii> pts;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] != '.') {
                ii pt = {i, j};
                pts.push_back(pt);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < (int)pts.size(); ++i) {
        for (int j = i+1; j < (int)pts.size(); ++j) {
            for (int k = j + 1; k < (int)pts.size(); ++k) {
                auto [i1, j1] = pts[i];
                auto [i2, j2] = pts[j];
                auto [i3, j3] = pts[k];
                auto di1 = i2 - i1;
                auto dj1 = j2 - j1;
                auto di2 = i3 - i2;
                auto dj2 = j3 - j2;

                if (dj1 * di2 == dj2 * di1) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
}
