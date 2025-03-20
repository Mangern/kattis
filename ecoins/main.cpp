#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <limits>
using namespace std;
using ii = array<int, 2>;
using tup = array<int, 3>;

int n;
int target;

vector<ii> vecs;
vector<bool> vis;
vector<int> mini;

inline int getid(tup state) {
    auto [cnt, u, v] = state;
    int id = (target + 1) * (target + 1) * cnt + (target + 1) * u + v;
    if (id >= vis.size())id = vis.size() - 1;
    return id;
}

inline int getid2(int u, int v) {
    int ret = (target + 1) * u + v;
    if (ret >= mini.size())ret = mini.size() - 1;
    return ret;
}

void testCase() {
    cin >> n >> target;
    int ans = numeric_limits<int>::max();
    vecs.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> vecs[i][0] >> vecs[i][1];
    }

    queue<tup> q;
    // idx, cnt, u, v
    q.push({0, 0, 0});

    mini = vector<int>((target + 1) * (target + 1) + 1, numeric_limits<int>::max());
    vis = vector<bool>((target+1)*(target+1)*(target+1) + 1, 0);
    vis[getid({0,0,0})] = 1;

    while (q.size()) {
        auto [cnt, u, v] = q.front();
        q.pop();

        if (u * u + v * v == target * target) {
            ans = cnt;
            break;
        }
        if (u * u + v * v > target * target) continue;
        if (cnt > target) continue;
        
        assert(cnt <= target && max(u, v) <= target);

        for (int i = 0; i < n; ++i) {
            if (vecs[i] == (ii){0, 0}) continue;
            int nu = u + vecs[i][0];
            int nv = v + vecs[i][1];
            if (nu * nu + nv * nv > target * target) continue;
            if (mini[getid2(nu,nv)] <= cnt + 1) continue;
            mini[getid2(nu,nv)] = cnt + 1;
            tup nxt = {cnt + 1, nu, nv};
            if (!vis[getid(nxt)]) {
                q.push(nxt);
                vis[getid(nxt)] = 1;
            }
        }
    }

    if (ans == numeric_limits<int>::max())cout << "not possible" << endl;
    else 
        cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T-->0)testCase();
    return 0;
}
