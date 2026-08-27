#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-->0) {
        string s;
        cin >> s;
        reverse(begin(s), end(s));
        int num = 0;

        int ans = 0;
        while (s.size()) {
            num *= 10;
            num += (s.back() - '0');
            s.pop_back();
            ans = max(ans, __builtin_popcount(num));
        }
        cout << ans << endl;
    }
}
