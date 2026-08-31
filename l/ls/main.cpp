#include <bits/stdc++.h>
using namespace std;

bool starts_with(const string& s, const string& pref) {
    for (int i = 0; i < pref.length(); ++i) {
        if (i >= s.length() || s[i] != pref[i]) return false;
    }
    return true;
}

bool ends_with(const string& s, const string& suff) {
    int base = (int)s.length() - (int)suff.length();
    for (int i = base; i < s.length(); ++i) {
        if (i < 0 || s[i] != suff[i-base]) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string pat;
    cin >> pat;

    int first_star = -1;
    int last_star = -1;

    for (int i = 0; i < pat.length(); ++i) {
        if (pat[i] == '*') {
            if (first_star == -1) first_star = i;
            last_star = i;
        }
    }

    string pref;
    string suff;
    vector<string> mid;

    if (first_star == -1) {
        pref = pat;
        suff = "";
    } else {
        pref = pat.substr(0, first_star);
        suff = pat.substr(last_star+1, pat.length());

        for (int i = first_star; i < last_star;) {
            if (pat[i] == '*') {
                ++i;
                continue;
            }
            int j;
            for (j = i; j < last_star && pat[j] != '*'; ++j);
            mid.push_back(pat.substr(i, j - i));
            i = j;
        }
    }

    int n;
    cin >> n;
    while (n-->0) {
        string s;
        cin >> s;

        if (!starts_with(s, pref)) {
            continue;
        }
        if (!ends_with(s, suff)) {
            continue;
        }

        int ptr = pref.length();
        bool fail=0;
        for (const auto& part : mid) {
            if (part.empty()) continue;
            auto pos = s.find(part, ptr);
            if (pos == string::npos) {
                fail=1;
                break;
            }
            if (pos + part.length() > s.length() - suff.length()) {
                fail=1;
                break;
            }
            ptr = pos + 1;
        }

        if (!fail) {
            cout << s << '\n';
        }
    }
}
