#include <bits/stdc++.h>
using namespace std;

char parent(char c) {
    switch(c) {
        case 'a':
        case 'b':
        case 'c':
            return 'a';
        case 'd':
        case 'e':
        case 'f':
            return 'd';
        case 'g':
        case 'h':
        case 'i':
            return 'g';
        case 'j':
        case 'k':
        case 'l':
            return 'j';
        case 'm':
        case 'n':
        case 'o':
            return 'm';
        case 'p':
        case 'q':
        case 'r':
        case 's':
            return 'p';
        case 't':
        case 'u':
        case 'v':
            return 't';
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            return 'w';
    }
    return 0;
}

char crep(int i) {
    switch(i) {
        case 2: return 'a';
        case 3: return 'd';
        case 4: return 'g';
        case 5: return 'j';
        case 6: return 'm';
        case 7: return 'p';
        case 8: return 't';
        case 9: return 'w';
    }
    return 0;
}

string repr(string s) {
    string res(s.length(), '?');
    for (int i = 0; i < s.length(); ++i) {
        res[i] = parent(s[i]);
    }
    return res;
}

int main() {

    int n, m;
    cin >> n >> m;

    unordered_map<string, vector<string>> ppl;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        string r = repr(s);
        ppl[r].push_back(s);
    }

    for (int i = 0; i < m; ++i) {
        string num;
        cin >> num;

        string r;
        for (char c : num) {
            r.push_back(crep(c-'0'));
        }
        auto &ans = ppl[r];

        cout << ans.size();

        for (auto s : ans)cout << ' ' << s;
        cout << endl;
    }
}
