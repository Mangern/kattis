#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    string s;
    cin >> s;

    vector<int> idx;
    string t;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i]>='1')t.push_back(s[i]);
        else idx.push_back(i);
    }


    int ans = 0;
    int ptr = 0;
    for (int i : idx) {
        ans += abs(i - ptr++);
    }

    ptr = 0;
    for (int i = 0; i < t.length(); ++i) {
        if (t[i] == '1')ans += abs(i - ptr++);
    }

    cout << ans << endl;
}
