#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t, l;
    getline(cin,s);
    getline(cin,t);
    getline(cin,l);


    string ans;

    for (int i = 0, j = 0, k = 0; i < s.length() || j < t.length(); ) {
        if (i == s.length()) {
            ans.push_back(t[j]);
            ++j;
            continue;
        }
        if (j == t.length()) {
            ans.push_back(s[i]);
            ++i;
            continue;
        }
        if (s[i] == t[j]) {
            assert(s[i] == l[k]);
            ans.push_back(s[i]);
            ++i;
            ++j;
            ++k;
            continue;
        }
        if (k < l.length() && s[i] == l[k]) {
            ans.push_back(t[j]);
            ++j;
            continue;
        }
        if (k < l.length() && t[j] == l[k]) {
            ans.push_back(s[i]);
            ++i;
            continue;
        }
        ans.push_back(s[i]);
        ++i;
        continue;
    }

    cout << ans << endl;
}
