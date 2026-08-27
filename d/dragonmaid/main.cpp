#include <bits/stdc++.h>
using namespace std;

using ii = array<int,2>;
using tup = array<int,3>;

const int mxN = 2e5+4;

int n, q;
int p[mxN];
int v[mxN];
vector<int> ans[mxN];

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; ++i)cin >> p[i] >> v[i];
    cin >> q;

    vector<int> idxs(n);
    iota(begin(idxs), end(idxs), 0);

    sort(begin(idxs), end(idxs), [] (auto a, auto b) { return v[a] < v[b]; });

    vector<tup> qrs(q);

    for (int i = 0; i < q; ++i) {
        cin >> qrs[i][0] >> qrs[i][1];
        qrs[i][2] = i;
    }
    set<ii> pi;
    sort(begin(qrs), end(qrs));

    int j = 0;

    for (int i = 0; i < q; ++i) {
        auto [x, k, q_idx] = qrs[i];

        while (j < n && v[idxs[j]] <= x) {
            pi.insert({p[idxs[j]], -idxs[j]});
            ++j;
        }

        if (pi.empty()) {
            continue;
        }

        auto it = --pi.end();

        while (k-->0) {
            ans[q_idx].push_back(-(*it)[1]+1);
            if (it == pi.begin())break;
            --it;
        }
    }

    for (int i = 0; i < q; ++i) {
        if (ans[i].empty()) {
            cout << -1 << endl;
            continue;
        }
        for (auto v : ans[i])cout << v << " ";
        cout << endl;
    }

    return 0;
}
