// given a graph find the number of cycles of minimal length
// lesson: split problem into several steps instead of trying to handle everything at once
// i.e. in this problem, FIRST find min length cycle and THEN count the number of times it occurs
// that way there is a smaller probability of implementation errors / wrong handling of edge cases occuring (no pun intended:))
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ii = array<int,2>;
using tup = array<int,3>;
using ll = long long;

const int mxN = 3e3+5;
const int INF = 2e6;

int n, m;
vi adj[mxN];
ii edge[2*mxN];
int dist[mxN];
ll cnt_arr[mxN];

int m_len = INF;
ll ans = 0;

int get_min(int s) {
    // run bfs, remove all nodes with id < s
    memset(dist, -1, sizeof dist);
    queue<tup> q;
    q.push({s, -1, 0});


    while (q.size()) {
        auto [u, cf, d] = q.front();
        q.pop();

        ++d;
        for (int v : adj[u]) if (v != cf && v >= s) {
            if (dist[v] == -1) {
                dist[v] = d;
                q.push({v,u,d});
            } else {
                return dist[v] + d;
            }
        }
    }

    return INF;
}

void cnt_odd(int s) {
    ll k = (m_len - 1)/2;
    memset(dist, -1, sizeof dist);
    queue<ii> q;
    dist[s] = 0;
    q.push({s,-1});

    while (q.size()) {
        auto [u, cf] = q.front();
        q.pop();

        for (int v : adj[u]) if (v != cf && v >= s) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push({v,u});
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        auto [u,v] = edge[i];
        if (dist[u] == k && dist[v] == k) {
            ++ans;
        }
    }
}

void cnt_ev(int s) {
    memset(dist, 0, sizeof dist);
    memset(cnt_arr, 0, sizeof cnt_arr);
    queue<tup> q;
    q.push({s,-1,0});
    ll k = m_len / 2;
    dist[s] = 1;

    while (q.size()) {
        auto [u, cf, d] = q.front();
        q.pop();
        ++d;
        for (int v : adj[u]) if (v != cf && v >= s) {
            if (!dist[v]) {
                dist[v] = 1;
                q.push({v,u,d});
            }
            if (d == k) {
                ++cnt_arr[v];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        ans += (cnt_arr[i] * (cnt_arr[i] - 1))/2;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge[i] = {u,v};
    }

    for (int i = 0; i < n; ++i) {
        m_len = min(m_len, get_min(i));
    }

    for (int i = 0; i < n; ++i) {
        if (m_len & 1)cnt_odd(i);
        else cnt_ev(i);
    }
    cout << ans << endl;
    return 0;
}
