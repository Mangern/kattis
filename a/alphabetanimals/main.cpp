#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> a;

    vector<int> start(256, 0);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a.push_back(s);
        ++start[s[0]];
    }

    for (int i = 0; i < n; ++i) {
        if (s.back() != a[i][0]) continue;
        if (start[a[i].back()] == 0 
        || (start[a[i].back()] == 1 && a[i][0] == a[i].back())) {
            cout << a[i] << "!" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i][0] == s.back()) {
            cout << a[i] << endl;
            return 0;
        }
    }
    cout << "?" << endl;
}
