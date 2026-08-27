#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;
    string s;
    cin >> s;
    s = " "+s;
    int n = s.length();

    vector<int> nxt(n);
    int idx[256];
    idx['R'] = -1;
    idx['G'] = -1;
    idx['B'] = -1;
    idx[s.back()] = n - 1;

    for (int i = n - 2; i >= 0; --i) {
        int j = max(idx['R'], max(idx['G'], idx['B']));
        nxt[i] = j;
        idx[s[i]] = i;
    }

    string ans;
    int ptr = 0;
    for (int i = 0; i < m; ++i) {
        ans.push_back(s[nxt[ptr]]);
        ptr = nxt[ptr];
    }
    cout << ans << endl;
}
