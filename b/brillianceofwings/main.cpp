#include <bits/stdc++.h>
using namespace std;

int main() {
    set<pair<int,int>> e1;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        e1.insert({min(u,v),max(u,v)});
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        ans += !e1.count({min(u,v),max(u,v)});
    }
    cout << ans << endl;
}
