#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;

    string s;cin >> s;

    ll rep = 1;
    ll pr = n;

    while (k>0 && pr % 2 == 0) {
        rep <<= 1;
        pr /= 2;
        --k;
    }

    string sub;
    ll ptr = 0;
    for (int i = 0; ptr < n && i < n; ++i) {
        sub.push_back(s[ptr]);
        ptr += rep;
    }

    if (!k || sub.length() == 1) {
        for (int i = 0; i < rep; ++i) {
            cout << sub;
        }
        cout << endl;
        return 0;
    }

    ll LG = 64 - __builtin_clzll(k);

    vector<vector<int>> send(LG, vector<int>(sub.length()));

    ptr = 0;
    for (int i = 0; i < sub.length(); ++i) {
        send[0][i] = ptr;
        ptr = (ptr + 2) % sub.length();
    }

    for (int l = 1; l < LG; ++l) {
        for (int i = 0; i < sub.length(); ++i) {
            send[l][i] = send[l-1][send[l-1][i]];
        }
    }
    string ans(sub.length(), '?');

    for (int i = 0; i < sub.length(); ++i) {
        ll d = k;

        int ptr = i;
        for (int l = 0; l < LG; ++l) {
            if ((k>>l)&1) {
                ptr = send[l][ptr];
            }
        }

        ans[i] = sub[ptr];
    }

    for (int i = 0; i < rep; ++i) {
        cout << ans;
    }
    cout << endl;
}
