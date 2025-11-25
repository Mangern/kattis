#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> taken;

    for (int i = 0; i < n; ++i) {
        queue<string> pos;
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            string s;
            cin >> s;
            pos.push(s);
        }

        while (taken.count(pos.front()))pos.pop();
        cout << pos.front() << " ";
        taken.insert(pos.front());
    }
    cout << endl;
}
