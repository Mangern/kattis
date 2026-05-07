#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

string ans;
int vis[26];
vector<int> adj[26];

bool dfs(int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (vis[v]  == 1) {
            return false;
        } else if (vis[v] == 2) continue;
        if (!dfs(v))return false;
    }

    ans.push_back('a'+u);
    vis[u] = 2;
    return true;
}

int main() {
    int n;
    cin >> n;


    vector<string> a(n);
    for (auto &s : a)cin >> s;
    for (int i = 1; i < n; ++i) {
        bool ok = 0;
        for (int j = 0; j < min(a[i-1].length(), a[i].length()); ++j) {
            if (a[i-1][j] != a[i][j]) {
                adj[a[i][j]-'a'].push_back(a[i-1][j]-'a');
                ok = 1;
                break;
            }
        }
        if (!ok) {
            if (a[i-1].length() > a[i].length()) {
                goto impossible;
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (!vis[i]) {
            if (!dfs(i)) {
                goto impossible;
                return 0;
            }
        }
    }

    cout << ans << endl;
    return 0;

impossible:
    cout << "impossible" << endl;
}
