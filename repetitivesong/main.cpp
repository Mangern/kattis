#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;

    unordered_map<string, int> idx;
    int oo = n;
    int ans = oo;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (idx.count(s)) {
            ans = min(ans, i - idx[s]);
        }
        idx[s] = i;
    }
    cout << n - ans << endl;
}
