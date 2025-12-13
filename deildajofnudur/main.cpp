#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int maxl = 0;

    for (int i = 0; i < n; ++i) {
        map<char, int> cnt;

        for (int j = i; j < n; ++j) {
            ++cnt[s[j]];
            int minv = 1000000;
            int maxv = 0;
            for (auto [k,v] : cnt) {
                minv = min(minv,v);
                maxv = max(maxv,v);
            }
            if (minv == maxv) {
                maxl = max(maxl, j - i + 1);
            }
        }
    }
    cout << maxl << endl;
}
