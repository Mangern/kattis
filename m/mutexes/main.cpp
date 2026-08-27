#include <bits/stdc++.h>
using namespace std;
const int mxN = 50005;
using bs = bitset<mxN>;
enum class I { AQ, R, AC, C };
enum class R { O, D, E, C, };
int nfunc, nmut;
unordered_map<string, int> fid;
unordered_map<string, int> mid;
vector<pair<I, int>> fc[mxN];
bool dp[mxN];
bs fifh[mxN]; 
bs fifnh[mxN];
bs fl[mxN];
int getmut(const string& arg) {
    if (mid.count(arg)) return mid[arg];
    return mid[arg] = nmut++;
}
bs muts;
R go_func(int f) {
    bs vis;
    for (auto [i, a] : fc[f]) {
        switch (i) {
            case I::AQ:
                if (!dp[f] && !vis.test(a)) {
                    vis.set(a);
                    fifh[f].set(a);
                }

                if (muts.test(a)) {
                    return R::D;
                }

                muts.set(a);
                fl[f].flip(a);
                break;
            case I::R:
                if (!dp[f] && !vis.test(a)) {
                    vis.set(a);
                    fifnh[f].set(a);
                }

                if (!muts.test(a)) {
                    return R::E;
                }
                muts.reset(a);
                fl[f].flip(a);
                break;
            case I::AC:
                if (!dp[f] && !vis.test(a)) {
                    vis.set(a);
                    fifnh[f].set(a);
                }

                if (!muts.test(a)) {
                    return R::C;
                }
                break;
            case I::C:
                if (dp[a]) {
                    if ((fifh[a] & muts).count() > 0) { return go_func(a); }
                    if ((fifnh[a] & (~muts)).count() > 0) { return go_func(a); }

                    muts ^= fl[a];
                } else {
                    auto sub = go_func(a);
                    if (sub != R::O) {
                        return sub;
                    }
                }
                if (!dp[f]) {
                    fl[f] ^= fl[a];
                    fifh[f] |= ((~vis)&fifh[a]);
                    fifnh[f] |= ((~vis)&fifnh[a]);
                    vis |= (fifh[a] | fifnh[a]);
                }
                break;
        }
    }
    if (!dp[f]) {
        dp[f] = true;
    }
    return R::O;
}

int main() {
    cin >> nfunc;

    vector<tuple<string, int, int>> unres;
    for (int i = 0; i < nfunc; ++i) {
        int k;
        string s,t;
        cin >> k >> s;
        fid[s] = i;
        for (int j = 0; j < k; ++j) {
            cin >> s >> t;

            I in = I::AQ;
            if (s == "access")in = I::AC;
            else if (s == "release")in = I::R;
            else if (s == "call")in = I::C;

            int a;

            switch (in) {
                case I::AQ:
                case I::AC:
                case I::R:
                    a = getmut(t);
                    break;
                case I::C:
                    a = -1;
                    unres.push_back({t, i, j});
                    break;
            }

            fc[i].push_back({in, a});
        }
    }

    for (const auto &[s, i, j] : unres) {
        fc[i][j].second = fid[s];
    }
    auto res = go_func(fid["main"]);
    switch (res) {
        case R::O:
            puts("a-ok");
            break;
        case R::E:
            puts("error");
            break;
        case R::C:
            puts("corruption");
            break;
        case R::D:
            puts("deadlock");
            break;
    }
}
