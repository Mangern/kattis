#include <bits/stdc++.h>
using namespace std;

int n;
string_view s;
int cost[13];

bool starts_with(string_view str, string_view pref) {
    str = str.substr(0, pref.length());
    return str == pref;
}

vector<string_view> have;
int search(int i) {
    if (i >= n) return 0;

    int ret = 1e9;

    string_view cur = s.substr(i);

    // Use one of the ones we have
    for (auto pat : have) {
        if (starts_with(cur, pat)) {
            ret = min(ret, search(i + pat.length()));
        }
    }

    // Make a new one
    for (int l = 1; l <= cur.length(); ++l) {
        string_view nw = cur.substr(0, l);
        have.push_back(nw);
        ret = min(ret, cost[l] + search(i + l));
        have.pop_back();
    }

    return ret;
}

int main() {
    string backing;
    cin >> backing;
    s = backing;
    n = s.length();

    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }

    cout << search(0) << endl;
}
