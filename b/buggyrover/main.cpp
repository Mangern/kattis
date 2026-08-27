#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

int main() {
    ll rows, cols;
    cin >> rows >> cols;
    vector<string> grid(rows);
    for (auto & s : grid) cin >> s;
    string mov;
    cin >> mov;
    ll n = mov.length();
    // min changes for [i..n] given that the starting ordering is s
    vector<map<string, ll>> dp(n+1);
    vector<pair<int,int>> pos;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 'S')pos.push_back({i, j});
        }
    }

    for (char c : mov) {
        auto [i, j] = pos.back();
        switch (c) {
            case 'N':
                pos.push_back({i-1, j});
                break;
            case 'S':
                pos.push_back({i+1, j});
                break;
            case 'E':
                pos.push_back({i, j+1});
                break;
            case 'W':
                pos.push_back({i, j-1});
                break;
        }
    }

    vector<string> perms;
    string perm = "ENSW";
    do {
        perms.push_back(perm);
    } while (next_permutation(begin(perm), end(perm)));


    auto cons = [&] (const string &perm, ii pos, ii nxt) {
        auto [i, j] = pos;

        int ni,nj;
        for (char c : perm) {
            ni=i,nj=j;
            switch(c) {
                case 'N':
                    ni=i-1;
                    break;
                case 'S':
                    ni=i+1;
                    break;
                case 'E':
                    nj=j+1;
                    break;
                case 'W':
                    nj=j-1;
                    break;
            }

            if (ni <0 || ni >= rows || nj <0 || nj >= cols) continue;
            if (grid[ni][nj] == '#') continue;
            break;
        }

        if (nxt != ii{ni,nj}) return false;

        return true;
    };

    for (const auto &p : perms) {
        dp[n][p] = 0;
    }

    for (int i = n - 1; i >= 0; --i) {
        ll minnxt = 1e10;

        for (auto &[k, v] : dp[i+1]) {
            if (cons(k, pos[i], pos[i+1])) {
                minnxt=min(minnxt, v);
            }
        }
        for (auto &perm : perms) {
            // two cases:
            //    it is consistent with the next position -> 0 + dp[i+1][perm]
            //    it flips to any other consistent perm -> 1 + min(dp[i+1])
            dp[i][perm] = 1 + minnxt;
            if (cons(perm, pos[i], pos[i+1])) {
                dp[i][perm] = min(dp[i][perm], dp[i+1][perm]);
            }
        }
    }

    ll ans = 1e10;

    for (auto &[k, v] : dp[0]) {
        ans = min(ans,v);
    }
    cout << ans << endl;
}
