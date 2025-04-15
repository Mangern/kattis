#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> cnt;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cout << cnt[s] << endl;
        string sub;
        for (char c : s) {
            sub.push_back(c);
            ++cnt[sub];
        }
    }
}
