#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const int mxN = 100;

int n;
vector<int> adj[mxN];
map<string, int> id;
map<int, string> rid;
int t;
bool vis[mxN];
int p[mxN];

int main() {
    string line;
    getline(cin, line);
    n = stoi(line);

    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        stringstream ss(line);
        string s;
        ss >> s;

        if (!id.count(s)) {
            id[s] = t++;
            rid[id[s]] = s;
        }
        int u = id[s];

        while (ss >> s) {
            if (!id.count(s)) {
                id[s] = t++;
                rid[id[s]] = s;
            }
            adj[u].push_back(id[s]);
            adj[id[s]].push_back(u);
        }

    }
    string s,t;
    getline(cin, line);
    stringstream ss(line);
    ss >> s >> t;

    int start = id[s];
    int goal = id[t];

    queue<int> q;
    q.push(start);
    vis[start] = 1;
    memset(p, -1, sizeof p);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                p[v] = u;
                q.push(v);
            }
        }
    }

    if (p[goal] == -1) {
        cout << "no route found" << endl;
        return 0;
    }

    vector<int> path;

    int ptr = goal;
    while (ptr != start) {
        path.push_back(ptr);
        ptr = p[ptr];
    }
    path.push_back(start);

    while (path.size()) {
        cout << rid[path.back()] << " \n"[path.size() == 1];
        path.pop_back();
    }
}
