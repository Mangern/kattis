#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int i = 0;
    int n = s.length();

    for (char c : t) {
        if (i < n && s[i] == c)++i;
    }
    cout << (i == n ? "Infected" : "Not infected") << endl;
}
