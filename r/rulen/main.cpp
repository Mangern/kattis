#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    string s;
    cin >> s;
    s = string(r + 1, '0') + s + string(r + 1, '0');
    string t = s;

    for (int it = 0; it < r; ++it) {
        for (int i = 0; i < s.length(); ++i) {
            int key = (s[i] - '0')*2;
            if (i>0) {
                key |= (s[i-1]-'0')*4;
            }
            if (i+1<s.length()) {
                key |= (s[i+1]-'0');
            }
            t[i] = '0'+((n>>key)&1);
        }
        cout << t.substr(r + 1, l) << '\n';
        swap(s,t);
    }
}
