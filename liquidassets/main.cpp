#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        string t;

        for (char c : s) {
            if (t.size() > 0 && t.back() == c) continue;
            t.push_back(c);
        }
        s.clear();
        for (int i = 0; i < t.length(); ++i) {
            char c = t[i];
            if (s.size()>0 && i<t.length()-1 && 
                (c == 'a'||c=='e'||c=='i'||c=='o'||c=='u')) {
                continue;
            }
            s.push_back(c);
        }
        cout << s << " \n"[i==n-1];
    }
}
