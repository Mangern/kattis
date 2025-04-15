#include <bits/stdc++.h>
using namespace std;
#define FORMASK(i, mask) for (int _x = (mask), i; i = 31-__builtin_clz(_x&(-_x)), _x; _x -= (_x&-_x)) 

const int n = 7;
int mask[n];

string name[7] = {
    "Twilight Sparkle",
    "Applejack", 
    "Rarity", 
    "Pinkie Pie", 
    "Fluttershy", 
    "Rainbow Dash",
    "Spike"
};

int idx[7];
vector<int> who[1<<7];
int dp[1<<7];
int choice[1<<7];

int solve(int msk) {
    int &r = dp[msk];
    if (r != -1) return r;
    if (msk == 0) return r = 0;

    r = 10;
    for (int ss = msk; ss; ss = (ss - 1) & msk) if (who[ss].size()) {
        int alt = 1 + solve(msk ^ ss);
        if (alt < r) {
            r = alt;
            choice[msk] = ss;
        }
    }
    return r;
}

int main() {
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            int x;
            cin >> x;

            mask[i] |= (x<<j);
        }
    }

    for (idx[0] = 0; idx[0] <= 7; ++idx[0]) {
    for (idx[1] = 0; idx[1] <= 7; ++idx[1]) {
    for (idx[2] = 0; idx[2] <= 7; ++idx[2]) {
    for (idx[3] = 0; idx[3] <= 7; ++idx[3]) {
    for (idx[4] = 0; idx[4] <= 7; ++idx[4]) {
    for (idx[5] = 0; idx[5] <= 7; ++idx[5]) {
    for (idx[6] = 0; idx[6] <= 7; ++idx[6]) {
        bool bad = 0;
        for (int i = 0; i < 7 && !bad; ++i) {
            if (idx[i] < 7 && !((mask[i]>>idx[i])&1)) {
                bad = 1;
                break;
            }
            for (int j = i + 1; j < 7 && !bad; ++j) {
                if (idx[i]<7 && idx[j]<7 && idx[i]==idx[j]) {
                    bad = 1;
                    break;
                }
            }
        }
        if (bad) continue;
        int msk = 0;

        vector<int> wh(7, 0);
        for (int i = 0; i < 7; ++i) if (idx[i] < 7) {
            msk |= (1<<idx[i]);
            wh[idx[i]] = i;
        }
        if (who[msk].size()) continue;
        who[msk] = wh;
    }
    }
    }
    }
    }
    }
    }

    int r = solve((1<<7)-1);
    if (r == 10) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int ptr = (1<<7)-1;

    vector<vector<pair<string, int>>> ans;
    while (ptr) {
        int ss = choice[ptr];


        vector<pair<string, int>> cur;
        int p = 0;
        FORMASK(i, ss) {
            cur.push_back({name[who[ss][i]], i+1});
        }
        ans.push_back(cur);
        ptr ^= choice[ptr];
    }
    cout << ans.size() << endl;
    for (auto &v : ans) {
        cout << v.size() << endl;
        for (auto [s, c] : v) {
            cout << s << " " << c << endl;
        }
    }
}
