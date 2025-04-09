#include <bits/stdc++.h>
using namespace std;

struct sol {
    int cnt;
    double mx;

    bool operator!=(const sol& other) const { 
        return cnt != other.cnt;
    }
};

const int mxN = 1005;
sol empt = {-1,0};

int n;
sol dp[mxN][2];
int root;
unordered_map<string, int> id;
vector<int> child[mxN];
int par[mxN];
double speed[mxN];

sol solve(int i, int pmatch) {
    sol& ret = dp[i][pmatch];
    if (ret != empt) return ret;

    ret = {0, 0.0};

    // don't match any of my children
    for (int j : child[i]) {
        auto [c, val] = solve(j, 0);
        ret.cnt += c;
        ret.mx += val;
    }
    if (!pmatch) {
        for (int ci = 0; ci < child[i].size(); ++ci) {
            // match me with child ci
            int u = child[i][ci];
            sol alt = {1, min(speed[i], speed[u])};

            for (int cj = 0; cj < child[i].size(); ++cj) {
                int v = child[i][cj];
                if (ci == cj) {
                    auto [c, val] = solve(v, 1);
                    alt.cnt += c;
                    alt.mx += val;
                } else {
                    auto [c, val] = solve(v, 0);
                    alt.cnt += c;
                    alt.mx += val;
                }
            }

            if (alt.cnt > ret.cnt || (alt.cnt == ret.cnt && alt.mx > ret.mx))
                ret = alt;
        }

    }
    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        dp[i][0] = dp[i][1] = empt;
    }

    int p = 0;
    for (int i = 0; i < n; ++i) {
        string s, t;
        double d;
        cin >> s >> d >> t;

        if (!id.count(s))id[s] = p++;

        speed[id[s]] = d;
        if (t != "CEO") {
            if (!id.count(t))id[t] = p++;

            child[id[t]].push_back(id[s]);
            par[id[s]] = id[t];
        } else {
            root = id[s];
        }
    }

    auto [cnt, mx] = solve(root, 0);
    cout << cnt << " " << setprecision(7) << fixed << (mx / (double)cnt) << endl;
}
