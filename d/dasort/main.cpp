#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        int tc, n;
        cin >> tc >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;
        vector<int> b = a;
        sort(begin(b), end(b));
        int ptr = 0;
        int ans = n;
        for (auto x : a) {
            if (x == b[ptr]) {
                ++ptr;
                --ans;
            }
        }
        cout << tc << ' ' << ans << endl;
    }
}
