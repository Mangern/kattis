#include <bits/stdc++.h>
using namespace std;

constexpr int H = 8;
constexpr int W = 6;
using Grid = array<array<bool, W>, H>;
using ll = long long;

Grid mask_to_grid(int mask) {
    Grid g = { 0 };

    for (int i = 0; i < 2 * W; ++i) {
        if ((mask >> i) & 1) {
            int r = i / W + H - 2;
            int c = i % W;
            g[r][c] = 1;
        }
    }
    return g;
}

int grid_to_mask(const Grid& g) {
    int mask = 0;
    for (int i = H-2; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int idx = (i - (H - 2)) * W + j;
            if (g[i][j]) {
                mask |= (1<<idx);
            }
        }
    }
    return mask;
}

bool grid_valid(const Grid& g) {
    for (int i = 0; i < H - 1; ++i) {
        for (int j = 0; j < W; ++j) {
            if (g[i][j] && !g[i+1][j]) return false;
        }
    }
    return true;
}

ll collapse(Grid& g) {
    ll ret = 0;
    for (int j = 0; j < W; ++j) {
        int cnt = 0;
        for (int i = 0; i < H; ++i) {
            if (g[i][j]) {
                ++cnt;
            }
            g[i][j] = 0;
        }

        if (cnt >= 3) ret += cnt;
        else {
            for (int i = 0; i < cnt; ++i) {
                g[H-1-i][j] = 1;
            }
        }
    }
    return ret;
}

array<int, 4> grid_measure(const Grid& g) {
    int minj = 100;
    int maxj = -100;
    int mini = 100;
    int maxi = -100;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (g[i][j]) {
                minj = min(minj, j);
                maxj = max(maxj, j);
                mini = min(mini, i);
                maxi = max(maxi, i);
            }
        }
    }
    if (maxj < 0) assert(false);
    return {mini, minj, maxi - mini + 1, maxj - minj + 1};
}

Grid rot90(const Grid& g) {
    Grid nw = { 0 };
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < W; ++j) {
            nw[j][W-1-i] = g[i][j];
        }
    }
    return nw;
}

void apply(Grid& g, int col, const array<int, 4>& meas, const Grid& gmov) {
    auto [offs_i, offs_j, height, width] = meas;
    for (int ii = 0; ii < height; ++ii) {
        for (int jj = 0; jj < width; ++jj) {
            g[ii][col+jj] = gmov[offs_i+ii][offs_j+jj];
        }
    }
}


const int mxN = 305;
const int mxK = 1<<12;

int n;

pair<Grid, ll> rounds[mxN];
ll dp[mxN][mxK];

void print(const Grid& g) {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (g[i][j])cout << '#';
            else cout << '_';
        }
        cout << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        auto &[g, s] = rounds[i];
        ll w, h;
        cin >> w >> h >> s;

        for (int j = 0; j < h; ++j) {
            string t;
            cin >> t;
            for (int k = 0; k < w; ++k) {
                if (t[k] == '#') {
                    g[j][k] = 1;
                }
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        memset(dp[i], -1, sizeof dp[i]);
    }
    dp[0][0] = 0;
    for (int r = 1; r <= n; ++r) {
        auto [gmov, s] = rounds[r];
        for (int mask = 0; mask < mxK; ++mask) {
            if (dp[r-1][mask] == -1) continue;
            Grid state = mask_to_grid(mask);
            if (!grid_valid(state)) continue;
            Grid cur = gmov;
            for (int t = 0; t < 4; ++t) {
                auto meas = grid_measure(cur);
                auto [offs_i, offs_j, height, width] = meas;
                for (int j = 0; j + width <= W; ++j) {
                    Grid curr_state = state;
                    apply(curr_state, j, meas, cur);
                    ll b = collapse(curr_state);
                    int nmask = grid_to_mask(curr_state);
                    dp[r][nmask] = max(dp[r][nmask], dp[r-1][mask] + b * s);
                }
                cur = rot90(cur);
            }
        }
    }

    cout << *max_element(dp[n], dp[n]+mxK) << endl;
}
