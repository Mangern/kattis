#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    int n = s.length();

    int p = n - k;
    string t;
    for (int i = 0; i < p; ++i) {
        t.push_back(s[i]);
    }

    for (int i = n - p; i < n; ++i) {
        if (i >= p) {
            t.push_back(s[i]);
        }
    }
    sort(begin(t), end(t));

    int ptr = 0;
    string cmp = s;

    for (int i = 0; i < p; ++i) {
        cmp[i] = t[ptr++];
    }
    for (int i = n - p; i < n; ++i) {
        if (i >= p) {
            cmp[i] = t[ptr++];
        }
    }

    sort(begin(s), end(s));

    if (cmp == s) cout << "Yes" << endl;
    else cout << "No" << endl;
}
