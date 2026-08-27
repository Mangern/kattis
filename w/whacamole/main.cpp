#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;

const int T = 10;

vector<array<int,2>> reach(int x, int y, int d, int n) {
    vector<array<int,2>> ret;

    for (int nx = x - d; nx <= x + d; ++nx) {
        for (int ny = y - d; ny <= y + d; ++ny) {
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
            if ((x-nx)*(x-nx)+(y-ny)*(y-ny)>d*d)continue;
            ret.push_back({nx, ny});
        }
    }
    return ret;
}

vector<array<int,2>> line(int x1, int y1, int x2, int y2) {
    vector<array<int,2>> ret;

    if (x1 == x2 && y1 == y2) {
        ret.push_back({x1,y1});
        return ret;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;

    int g;

    if (dx * dy) {
        g = gcd(abs(dx), abs(dy));
    } else g = abs(dx)+abs(dy);


    dx /= g;
    dy /= g;

    while (true) {
        ret.push_back({x1, y1});
        if (x1 == x2 && y1 == y2)break;
        x1 += dx;
        y1 += dy;

    }

    return ret;
}

void solve(int n, int d, int m) {
    n += 2*d;
    vector<vector<vi>> mole(T, vector<vi>(n, vi(n, 0)));
    // dp[t][x][y] = max score achievable at time t, with hammer 
    // ending at (x, y)
    vector<vector<vi>> dp(T, vector<vi>(n, vi(n, 0)));
    for (int i = 0; i < m; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        --t;
        x += d;
        y += d;
        mole[t][x][y] = 1;
    }

    for (int t = 0; t < T; ++t) {
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                for (auto [sx, sy] : reach(x, y, d, n)) {
                    ll curr = t == 0 ? 0 : dp[t-1][sx][sy];
                    for (auto [lx, ly] : line(x, y, sx, sy)) {
                        curr += mole[t][lx][ly];
                    }
                    dp[t][x][y] = max(dp[t][x][y], curr);
               }
            }
        }
    }

    ll ans = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            ans = max(ans, dp[T-1][x][y]);
        }
    }
    cout << ans << endl;
}

int main() {
    while (true) {
        int n, d, m;
        cin >> n >> d >> m;
        if (n+d+m)solve(n,d,m);
        else break;
    }
}
