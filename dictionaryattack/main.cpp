#include <bits/stdc++.h>
using namespace std;

const int mxN = 15;

int n;
vector<string> dicts[mxN];

bool poss[mxN][255];

bool check(string& s, int times = 3) {
    for (const string &t : dicts[s.length() - 1]) {
        int dif = 0;
        bool fl = 1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == t[i]) continue;
            if (!isdigit(s[i])) {
                fl = 0;
                break;
            }
            ++dif;
        }
        if (!fl) continue;
        if (dif <= times) return false;
    }
    if (times == 0) return true;

    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] != s[i+1]) {
            swap(s[i], s[i+1]);
            if (!check(s, times-1)) return false;
            swap(s[i], s[i+1]);
        }
    }
    return true;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        dicts[s.length() - 1].push_back(s);

        for (int j = 0; j < s.length(); ++j) {
            poss[j][s[j]] = 1;
        }
    }

    string pass;
    while (cin >> pass) {
        if (check(pass))cout << pass << endl;
    }
}
