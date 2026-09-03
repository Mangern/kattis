#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, d;
    cin >> n >> p >> d;

    string s;
    cin >> s;
    s += s;

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < p; ++i) {
        cnt += (s[n-p+i] == 'Z');
    }
    for (int i = 0; i < n; ++i) {
        cnt -= (s[n+i-p] == 'Z');
        cnt += (s[n+i] == 'Z');
        if (cnt<d)++ans;
    }
    cout << ans << endl;
}
