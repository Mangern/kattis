#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int i = 0;

    for (int j = 0; j < t.length() && i < s.length(); ++j) {
        if (s[i] == t[j]) {
            ++i;
        }
    }

    cout << (i >= s.length() ? "Ja":"Nej") << endl;
}
