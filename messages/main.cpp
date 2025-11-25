#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> dic;

    for (;;) {
        string s;
        cin >> s;
        if (s[0] == '#')break;
        dic.push_back(s);
    }

    for (;;) {
        string s;
        bool fin=0;
        for (;;) {
            char c;
            cin >> c;
            if (c == '\n')continue;
            if (c == '|')break;
            if (c == '#') {
                fin = 1;
                break;
            }
            s.push_back(c);
        }
        if (fin) break;

        vector<pair<int,int>> ints;

        for (const string& t: dic) {
            int prv = 0;
            for (;;) {
                auto idx = s.find(t, prv);
                if (idx == string::npos) break;
                ints.push_back({idx, idx + t.length() - 1});
                prv = idx + 1;
            }
        }

        sort(begin(ints), end(ints), [](auto a, auto b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        int cnt = 0;
        int hi = -1;
        for (auto [l, r] : ints) {
            if (l > hi) {
                ++cnt;
                hi = r;
            }
        }
        cout << cnt << endl;
    }
}
