#include <bits/stdc++.h>
using namespace std;

const int mxN = 25;

int n;
int masks[mxN];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        for (char c : s) {
            masks[i] |= (1<<(c-'a'));
        }
    }

    int ans = 0;
    int goal = (1<<26)-1;
    for (int mask = 0; mask < (1<<n); ++mask) {
        int res = 0;
        int x = mask;
        while (x) {
            int l = (x&(-x));
            res |= masks[31 - __builtin_clz(l)];
            x -= l;
        }
        ans += (res == goal);
    }
    cout << ans << endl;
}
