#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, K, I, T;
    cin >> h >> w >> K >> I >> T;

    vector<string> ans(h, string(w, '?'));
    ans[0][0] = 'K'; --K;
    ans[0][1] = 'I'; --I;
    ans[0][2] = 'T'; --T;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (ans[i][j] != '?') continue;
            if (K) {
                ans[i][j] = 'K';
                --K;
            } else if (T) {
                ans[i][j] = 'T';
                --T;
            } else {
                ans[i][j] = 'I';
                --I;
            }
        }
    }

    for (auto s : ans)cout << s << endl;
}
