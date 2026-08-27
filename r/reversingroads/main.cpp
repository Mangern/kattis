#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,2>;
using vii = vector<ii>;

#define all(v) begin(v), end(v)

const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (unsigned ll)rng() % B;
}
template<typename t>
istream& operator >> (istream& in, vector<t>& vec) {
    for (t& x : vec)in >> x;
    return in;
}

template<typename t>
ostream& operator << (ostream& out, vector<t>& vec) {
    int n = (int)vec.size();
    for (int i = 0; i < n; ++i) {
        out << vec[i];
        if (i < n - 1)out << " ";
    }
    return out;
}

// t should support min-function (operator <)
template<typename t>
t min(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = min(ans, el);
    }
    return ans;
}

// t should support max-function (operator <)
template<typename t>
t max(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = max(ans, el);
    }
    return ans;
}
const int mxN = 3e4+3;


bool scc(vector<vi>& adj) {
    int n = adj.size();

    vector<vi> radj(n, vi());
    for (int i = 0; i < n; ++i)for (int j : adj[i])radj[j].push_back(i);

    vector<bool> vis(n, 0);
    stack<int> stk;

    function<void(int)> dfs1 = [&] (int u) {
        vis[u] = 1;
        for (int v : adj[u]) if (!vis[v])dfs1(v);
        stk.push(u);
    };

    function<void(int)> dfs2 = [&] (int u) {
        vis[u] = 1;
        for (int v : radj[u]) if (!vis[v]) {
            dfs2(v);
        }
    };

    dfs1(0);
    if (stk.size() < n)return false;
    vis = vector<bool>(n, 0);
    int cnt = 0;
    while (!stk.empty()) {
        int tp = stk.top();
        stk.pop();
        if (!cnt) {
            ++cnt;
            dfs2(tp);
        } else if (!vis[tp])return false;
    }

    return true;
}

ii read_pair() {
    string line;
    if (!getline(cin,line))return {-1,-1};
    int a = stoi(line.substr(0,line.find(" ")));
    int b = stoi(line.substr(line.find(" ") + 1, line.length()));
    return {a,b};
}

void testCase(int tc) {
    auto [n,m] = read_pair();
    if (n == -1) {
        exit(0);
        return;
    }

    vector<vi> adj(n, vi());
    vector<ii> edge(m);

    for (int i = 0; i < m; ++i) {
        edge[i] = read_pair();
        adj[edge[i][0]].push_back(edge[i][1]);
    }

    string ans = "invalid";

    if (scc(adj))ans = "valid";
    else {

        for (int i = 0; i < m; ++i) {
            auto [u,v] = edge[i];

            for (int j = 0; j < adj[u].size(); ++j) {
                if (adj[u][j] == v) {
                    adj[u].erase(adj[u].begin()+j);
                    break;
                }
            }
            adj[v].push_back(u);
            if (scc(adj)) {
                ans = to_string(u) + " " + to_string(v);
                break;
            }
            adj[v].pop_back();
            adj[u].push_back(v);
        }
    }

    cout << "Case " << tc << ": " << ans << endl;

}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}

int main() {
    setIO();
    pre();
    int t = 5;
//    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase(tc);
    }
    return 0;
}
