#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct trie {
    bool term;
    trie* nxt[256];

    trie() {
        memset(nxt, 0, sizeof nxt);
    }
};

const int mxN = 26000;
trie *root = new trie();

int n;
string a[mxN];
unordered_map<string, int> idx;
int cf[mxN];
int vis[mxN];
bool neicmp[mxN];
vector<int> neis[mxN];

void insert(const string& s) {
    trie *ptr = root;

    for (char c : s) {
        if (ptr->nxt[c] == 0) {
            ptr->nxt[c] = new trie();
        }
        ptr = ptr->nxt[c];
    }
    ptr->term = true;
}

string buf;
void gen_neis(int u, int i, trie* node, bool hassw = 0) {
    if (i == a[u].length()) {
        if (node->term && idx.count(buf)) {
            neis[u].push_back(idx.at(buf));
        }
        return;
    }

    if (hassw) {
        trie* nxt = node->nxt[a[u][i]];
        if (nxt != 0) {
            buf.push_back(a[u][i]);
            gen_neis(u, i + 1, nxt, 1);
            buf.pop_back();
        }
        return;
    }

    for (int c = 0; c < 256; ++c) {
        if (node->nxt[c] == 0) continue;
        buf.push_back((char)c);
        gen_neis(u, i + 1, node->nxt[c], (char)c != a[u][i]);
        buf.pop_back();
    }
}

void search(int s, int t) {
    memset(cf, -1, sizeof cf);
    memset(vis, 0, sizeof vis);
    vis[s] = 1;
    queue<int> q({s});
    while (q.size()) {
        int u = q.front(); q.pop();

        if (!neicmp[u]) {
            gen_neis(u, 0, root);
            neicmp[u] = 1;
        }
        for (int v : neis[u]) {
            if (!vis[v]) {
                cf[v] = u;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.length() == 0) break;
        insert(line);
        idx[line] = n;
        a[n++] = line;
    }
    bool hasf = 0;
    while (getline(cin, line), line.length()) {
        stringstream ss{line};
        string s, t;
        ss >> s >> t;

        if (hasf) {
            cout << endl;
        }
        hasf = 1;

        if (!idx.count(s) || !idx.count(t)) {
            cout << "No solution." << endl;
            continue;
        }

        int u = idx[s];
        int v = idx[t];
        search(u,v);
        if (cf[v] == -1) {
            cout << "No solution." << endl;
            continue;
        }
        vector<int> path;

        int ptr = v;
        while (ptr != -1) {
            path.push_back(ptr);
            ptr = cf[ptr];
        }
        while (path.size()) {
            cout << a[path.back()] << endl;
            path.pop_back();
        }
    }
    return 0;
}
