#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using ii = array<int,2>;

// (r, c, dir, ice_mask)
using tup = array<ll, 4>;

const int N = 8;

string grid[N];

ii dmap[4] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

inline bool iceat(ll ice, ll r, ll c) {
    return (ice >> (r * N + c))&1;
}

int main() {
    ll ice_start = 0;
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];

        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 'I') {
                ice_start |= (1ULL<<(i * N + j));
            }
        }
    }

    // FLFRXFLFRFLFRF
    // FLFRXFLFRFXFFFLFFLF
    map<tup, int> cf;
    queue<tup> q;
    tup start = {N - 1, 0, 0, ice_start};
    cf[start] = -1;
    q.push(start);
    while (q.size()) {
        tup u = q.front();
        q.pop();
        auto [r, c, dir, ice] = u;

        if (grid[r][c] == 'D') {
            tup ptr = u;
            string ans;
            string mmp = "FRLX";
            while (cf[ptr] != -1) {
                int move = cf[ptr];
                ans.push_back(mmp[move]);

                switch (move) {
                    case 0: // F
                        {
                            ptr[0] -= dmap[ptr[2]][0];
                            ptr[1] -= dmap[ptr[2]][1];
                        }
                        break;
                    case 1: // R
                        {
                            ptr[2] = (ptr[2] + 3) % 4;
                        }
                        break;
                    case 2:
                        {
                            ptr[2] = (ptr[2] + 1) % 4;
                        }
                        break;
                    case 3:
                        {
                            ll nr = ptr[0] + dmap[ptr[2]][0];
                            ll nc = ptr[1] + dmap[ptr[2]][1];
                            ptr[3] |= (1ULL << (nr * N + nc));
                        }
                        break;
                    default:
                        break;
                }
            }
            reverse(begin(ans), end(ans));
            cout << ans << endl;
            return 0;
        }

        // F
        {
            ll nr = r + dmap[dir][0];
            ll nc = c + dmap[dir][1];
            if (0 <= nr && nr < N && 0 <= nc && nc < N && grid[nr][nc] != 'C' && !iceat(ice, nr, nc)) {
                tup nxt = {nr, nc, dir, ice};
                if (!cf.count(nxt)) {
                    cf[nxt] = 0;
                    q.push(nxt);
                }
            }
        }

        // R
        {
            tup nxt = {r, c, (dir + 1) % 4, ice};
            if (!cf.count(nxt)) {
                cf[nxt] = 1;
                q.push(nxt);
            }
        }

        // L
        {
            tup nxt = {r, c, (dir + 4 - 1) % 4, ice};
            if (!cf.count(nxt)) {
                cf[nxt] = 2;
                q.push(nxt);
            }
        }

        // X
        {
            ll nr = r + dmap[dir][0];
            ll nc = c + dmap[dir][1];
            if (0 <= nr && nr < N && 0 <= nc && nc < N && grid[nr][nc] != 'C' && iceat(ice, nr, nc)) {
                ll nice = ice ^ (1ULL << (nr * N + nc));
                tup nxt = {r, c, dir, nice};
                if (!cf.count(nxt)) {
                    cf[nxt] = 3;
                    q.push(nxt);
                }
            }
        }
    }

    cout << "no solution" << endl;
}
