#include <bits/stdc++.h>
using namespace std;

using tup = array<int,2>;

struct Edge {
    int v;
    int flow;
    int cap;
    int rev;
};

const int INF = numeric_limits<int>::max();
int adj_start[530];
int level[530];

using Graph = vector<vector<Edge>>;

int send_flow(Graph& adj, int u, int s, int t, int flow = INF) {
    if(u == t)return flow;

    while (adj_start[u] < (int)adj[u].size()) {
        Edge* edge = &adj[u][adj_start[u]];
        int v = edge->v;

        if (level[v] == level[u] + 1 && edge->flow < edge->cap) {
            int next_flow = min(flow, edge->cap - edge->flow);
            int result = send_flow(adj, v, s, t, next_flow);

            if (result > 0) {
                edge->flow += result;
                adj[v][edge->rev].flow -= result;
                return result;
            }
        }

        ++adj_start[u];
    }
    return 0;
}

bool bfs(Graph& adj, int s, int t) {
    memset(level, -1, sizeof level);

    level[s] = 0;
    queue<int> q;

    q.push(s);

    while (q.size()) {
        int u = q.front();
        q.pop();

        if (u == t)break;

        for (auto edge : adj[u]) {
            int v = edge.v;
            if (level[v] == -1 && edge.flow < edge.cap) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }

    }

    return level[t] >= 0;
}

int max_flow(Graph& adj, int s, int t) {
    int total_flow = 0;

    while (bfs(adj, s, t)) {
        memset(adj_start, 0, sizeof adj_start);
        while (true) {
            int result = send_flow(adj, s, s, t);

            if (!result)break;
            total_flow += result;
        }
    }
    return total_flow;
}

bool can(int u, vector<string> res) {
    int n = res.size();

    int max_score = 0;
    for (int i = 0; i < n; ++i) if (i != u) {
        if (res[u][i] == '1')max_score += 2;
        else if (res[u][i] == 'd')max_score += 1;
        else if (res[u][i] == '0')continue;
        else {
        // undecided

            res[u][i] = '1';
            max_score += 2;
            res[i][u] = '0';
        }
    }

    // score holds maximum possible score we can get

    // if anyone already achieved higher, we can't win
    vector<int> score(n, 0);
    vector<tup> matches;
    for (int i = 0; i < n; ++i) if (i != u) {
        bool has_left = 0;
        for (int j = 0; j < n; ++j) if (i != j) {
            if (res[i][j] == '1')score[i] += 2;
            if (res[i][j] == 'd')score[i] += 1;
            if (j > i && res[i][j] == '.') {
                matches.push_back({i, j});
            }
        }

        if (score[i] > max_score)return false;
    }

    vector<vector<Edge>> adj(1 + matches.size() + n + 1);
    int p_offset = 1 + matches.size();
    int t = 1 + matches.size() + n;

    int goal_flow = 0;
    for (int i = 0; i < matches.size(); ++i) {
        auto [u, v] = matches[i];
        adj[0].push_back({
            i+1,
            0,
            2,
            (int)adj[i+1].size()
        });
        adj[i+1].push_back({
            0,
            0,
            0,
            (int)adj[0].size() - 1
        });

        goal_flow += 2;

        adj[i+1].push_back({
            p_offset + u,
            0,
            2,
            (int)adj[p_offset+u].size()
        });
        adj[p_offset+u].push_back({
            i+1,
            0,
            0,
            (int)adj[i+1].size() - 1
        });

        adj[i+1].push_back({
            p_offset + v,
            0,
            2,
            (int)adj[p_offset+v].size()
        });
        adj[p_offset+v].push_back({
            i+1,
            0,
            0,
            (int)adj[i+1].size() - 1
        });
    }

    for(int i = 0; i < n; ++i) if (i != u) {
        adj[p_offset+i].push_back({
            t,
            0,
            max_score - score[i],
            (int)adj[t].size()
        });
        adj[t].push_back({
            p_offset+i,
            0,
            0,
            (int)adj[p_offset+i].size() - 1
        });
    }

    return (max_flow(adj, 0, t) == goal_flow);
}

void test_case() {
    int n;
    cin >> n;

    vector<string> res(n);
    for (auto& s : res)cin >> s;

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (can(i, res))ans.push_back(i+1);
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}

int main() {
    int t;
    cin >> t;
    while (t-->0)test_case();
    return 0;
}
