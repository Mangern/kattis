#include <bits/stdc++.h>
using namespace std;

bool is_subseq(const string& s, const string& target) {
    // is s a subsequence of target?

    int i = 0;
    for (int j = 0; i < s.length() && j < target.length(); ++j) {
        if (s[i] == target[j])++i;
    }

    return i == s.length();
}

int main() {
    while (true) {
        string s, l;
        cin >> s;
        if (s == "0")break;
        cin >> l;
        int a = 0, b = 0, c = 0;

        for (int i = 0; i + s.length()-1 <= l.length(); ++i) {
            if (i+s.length() <= l.length() && l.substr(i,s.length()) == s)++a;
            if (i+s.length()-1 <= l.length() && is_subseq(l.substr(i, s.length()-1), s))++b;
            if (i+s.length()+1 <= l.length() && is_subseq(s, l.substr(i, s.length()+1)))++c;
        }
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}
