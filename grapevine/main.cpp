#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+5;

int n,m,d;
vector<int> adj[mxN];
int scep[mxN];
map<string,int> id;

int main() {
    cin >> n >> m >> d;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        id[s] = i;
        cin >> scep[i];
    }

    for (int i = 0; i < m; ++i) {
        string su, sv; cin >> su >> sv;
        adj[id[su]].push_back(id[sv]);
        adj[id[sv]].push_back(id[su]);
    }

    vector<int> q;
    string s;
    cin >> s;
    q.push_back(id[s]);
    int ans = 0;
    vector<int> vis(n,0);
    vis[id[s]]=1;

    for (int i = 0; i < d; ++i) {
        vector<int> nq;

        for (int u : q) {
            for (int v : adj[u]) {
                vis[v]=1;
                if (!--scep[v]) {
                    nq.push_back(v);
                    ++ans;
                }
            }
        }
        swap(q,nq);
    }
    cout << accumulate(begin(vis),end(vis),0)-1 << endl;
}
