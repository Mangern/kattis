#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int p1 = -10;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;

        if (c == '1') {
            p1 = i;
            ++ans;
        } else {
            if (i - p1 <= 2) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
