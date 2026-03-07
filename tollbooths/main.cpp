#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0;

    long long cur = 0;

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        long long x;
        cin >> x;

        if (c == 'T') {
            cur -= x;
            if (cur < 0) {
                ans += -cur;
                cur = 0;
            }
        } else {
            cur += x;
        }
    }
    cout << ans << endl;
}
