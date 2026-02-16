#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    list<string> colors;
    vector<list<string>::iterator> its;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        colors.push_back(s);
        its.push_back(--colors.end());
    }

    while (m-->0) {
        int i;
        cin >> i;

        string cmd;
        cin >> cmd;

        if (cmd == "L") {
            its[i]--;
        } else if (cmd == "R") {
            its[i]++;
        } else {
            its[i] = colors.insert(its[i], cmd);
        }
    }

    for (auto s : colors)cout << s << " ";
    cout <<endl;
}
