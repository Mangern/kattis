#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    int ans = n;
    for (auto [_, v] : cnt) {
        ans -= v - min(v, k);
    }
    cout <<ans << endl;
}
