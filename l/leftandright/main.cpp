#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+5;

vector<int> adj[mxN];
int in[mxN];

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 1; i < n; ++i) {
        if (s[i-1] == 'L') {
            adj[i].push_back(i-1);
            ++in[i-1];
        } else {
            adj[i-1].push_back(i);
            ++in[i];
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i) {
        if (!in[i]) {
            pq.push(i);
        }
    }
    while (pq.size()) {
        int u = pq.top();
        pq.pop();

        cout << u + 1 << endl;

        for (int v : adj[u]) {
            if (!--in[v])pq.push(v);
        }
    }
}
