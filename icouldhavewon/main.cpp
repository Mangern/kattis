#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    vector<int> ans;
    for (int k = 1; k <= n; ++k) {
        int score[2] = {0,0};
        int win[2] = {0,0};
        for (char c : s) {
            if (++score[c-'A'] == k) {
                ++win[c-'A'];
                score[0] = score[1] = 0;
            }
        }
        if (win[0]>win[1])ans.push_back(k);
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << ' ';
    cout << endl;
}
