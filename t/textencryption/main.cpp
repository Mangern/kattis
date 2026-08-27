#include <bits/stdc++.h>
using namespace std;

void testCase() {
    string s;
    getline(cin, s);
    int n = stoi(s);
    if (!n) exit(0);

    getline(cin, s);
    string t;
    for (char c : s) if (c != ' ') t.push_back(toupper(c));

    string ans(t.length(), '0');
    set<int> rem;
    for (int i = 0; i < t.length(); ++i)rem.insert(i);

    int pos = 0;

    for (char c : t) {
        ans[pos] = c;
        rem.erase(pos);
        pos += n;
        if (pos >= ans.length() && rem.size()) {
            pos = *rem.begin();
        }
    }
    cout << ans << endl;
}

int main() {
    for (;;)testCase();
}
