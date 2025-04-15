#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool check(const string& s, int d) {
    unordered_map<string, int> cnt;
    for (int i = 0; i <= s.length() - d; ++i) {
        ++cnt[s.substr(i, d)];
    }

    for (auto &[k,v] : cnt) {
        if (v == 1) return false;
    }
    return true;
}

int main() {
    string s;
    while (cin >> s) {
        for (int d = 1; d <= s.length(); ++d) {
            if (!check(s, d)) {
                cout << d-1 << endl;
                break;
            }
        }
    }
}
