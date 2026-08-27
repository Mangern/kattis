#include <bits/stdc++.h>
using namespace std;

const int mxN = 17;

#define FORMASK(i, mask) for (int _x = (mask), i; i = 31-__builtin_clz(_x&(-_x)), _x; _x -= (_x&-_x)) 

int n, m, c;

map<string, int> id;
int adj[mxN];
bool good[1<<mxN];
string name[mxN];

int dp[1<<mxN];
int choice[1<<mxN];

int solve(int mask) {
    if (mask == 0) return 0;

    int &r = dp[mask];
    if (r != -1) return r;

    int ret = 20;
    for (int ss = mask; ss; ss = (ss-1) & mask) if (good[ss]) {
        int alt = 1 + solve(mask ^ ss);
        if (alt < ret) {
            ret = alt;
            choice[mask] = ss;
        }
    }
    return r = ret;
}

int main() {
    cin >> n >> m >> c;

    for (int i = 0; i < n; ++i) {
        cin >> name[i];
        id[name[i]] = i;

        adj[i] = (1<<n)-1;
    }

    for (int i = 0; i < m; ++i) {
        string s,t;
        cin >> s >> t;

        adj[id[s]] ^= (1<<id[t]);
        adj[id[t]] ^= (1<<id[s]);
    }

    for (int mask = 0; mask < (1<<n); ++mask) if (__builtin_popcount(mask) <= c) {
        int x = mask;

        bool succ=1;
        FORMASK(i, mask) {
            if (!succ) break;
            FORMASK(j, mask) {
                if (j >= i) break;
                if (!((adj[i]>>j)&1)) {
                    succ = 0;
                    break;
                }
            }
        }

        good[mask] = succ;
    }
    memset(dp, -1, sizeof dp);
    cout << solve((1<<n)-1) << endl;

    int ptr = (1<<n)-1;

    while (ptr) {
        FORMASK(i, choice[ptr])
            cout << name[i] << " ";
        cout << endl;
        ptr ^= choice[ptr];
    }
}
