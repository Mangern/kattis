#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    map<string, int> idx;
    vector<string> nm(n);
    for (int i = 0; i < n; ++i) {
        string &s = nm[i];
        cin >> s;
        idx[s] = i;
    }

    vector<bool> tag(n, 0);
    tag[0] = 1;

    set<int> cheat;

    for (int i = 0; i < m; ++i) {
        string a, b, t;
        cin >> a;
        cin >> t;
        cin >> b;
        int u = idx[a];
        int v = idx[b];

        if (!tag[u]) {
            cheat.insert(u);
        }

        tag[u] = 0;
        tag[v] = 1;
    }
    vector<string> ans;
    for (int k : cheat)ans.push_back(nm[k]);
    sort(begin(ans),end(ans));
    cout << ans.size() << endl;
    for (string s : ans)cout << s << " ";
    cout << endl;
}
