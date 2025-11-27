#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

const int mxN = 5e4+5;
const ll INF = numeric_limits<ll>::max() / 4;

int n, m;
vector<ii> adj[mxN];
// is interesting
bool isi[mxN];
// sum dist * f to interesting in subtree
ll sumi[mxN];
ll numi[mxN];
ll ans_val;
ll ans_num;
ll ans[mxN];

void dfs(int u, int cf = -1) {
    for (auto [v, w] : adj[u]) if (v != cf) {
        dfs(v, u);
        numi[u] += numi[v];
        sumi[u] += sumi[v] + w * numi[v];
    }
}

void dfs_ans(int u, int cf = -1, ll acc_num = 0, ll acc_sum = 0) {
    ll cur = sumi[u] + acc_sum;
    if (cur < ans_val) {
        ans_val = cur;
        ans_num = 0;
        ans[ans_num++] = u;
    } else if (cur == ans_val) {
        ans[ans_num++] = u;
    }

    for (auto [v, w] : adj[u]) if (v != cf) {
        ll new_num = acc_num + numi[u] - numi[v];
        ll new_sum = acc_sum + sumi[u] - sumi[v] - w * numi[v] + new_num * w;
        dfs_ans(v, u, new_num, new_sum);
    }
}

void test() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        numi[i] = 0;
        sumi[i] = 0;
    }

    ans_num = 0;
    ans_val = INF;

    for (int i = 0; i < n - 1; ++i) {
        ll u, v, w;
        cin >> u >> v >> w, --u, --v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cin >> m;

    for (int i = 0; i < m; ++i) {
        int u;
        cin >> u, --u;
        ll f;
        cin >> f;
        numi[u] = f;
    }

    dfs(0);
    dfs_ans(0);

    sort(ans,ans+ans_num);

    cout << 2*ans_val << endl;


    for (int i = 0; i < ans_num; ++i) {
        cout << ans[i]+1 << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-->0) {
        test();
    }
}
