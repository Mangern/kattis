#include <bits/stdc++.h>
using namespace std;

int dist[8*8][8*8];
vector<int> par[8*8][8*8];

int main() {
    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 64; ++j) {
            dist[i][j] = 500;
        }
        dist[i][i] = 0;
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (auto [ni, nj] : vector<pair<int,int>>{
                {i-2,j-1},
                {i-2,j+1},
                {i-1,j-2},
                {i-1,j+2},
                {i+1,j-2},
                {i+1,j+2},
                {i+2,j-1},
                {i+2,j+1}}
            ) {
                if (ni < 0 || ni >= 8 || nj < 0 || nj >= 8) continue;
                int u = i * 8 + j;
                int v = ni * 8 + nj;
                dist[u][v] = 1;
                par[u][v].push_back(u);
            }
        }
    }

    for (int k = 0; k < 64; ++k) {
        for (int i = 0; i < 64; ++i) {
            for (int j = 0; j < 64; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    par[i][j].clear();
                } 
                if (dist[i][k] + dist[k][j] <= dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    for (auto p : par[k][j]) {
                        if (find(begin(par[i][j]), end(par[i][j]), p) == end(par[i][j])) {
                            par[i][j].push_back(p);
                        }
                    }
                }
            }
        }
    }

    string ps, pe;
    cin >> ps >> pe;
    pair<int,int> spos = {ps[0] - 'a', ps[1] - '1'};
    pair<int,int> tpos = {pe[0] - 'a', pe[1] - '1'};

    int s = spos.first * 8 + spos.second;
    int t = tpos.first * 8 + tpos.second;

    queue<deque<int>> paths;
    paths.push({t});
    vector<deque<int>> ans;
    while (paths.size()) {
        auto path = paths.front();
        paths.pop();
        if (path.front() == s) {
            ans.push_back(path);
            continue;
        }

        for (auto p : par[s][path.front()]) {
            auto npath = path;
            npath.push_front(p);
            paths.push(npath);
        }
    }

    vector<string> res;

    for (auto &path : ans) {
        string prep;
        for (int i = 0; i < path.size(); ++i) {
            if (i > 0) {
                prep.push_back(' ');
                prep.push_back('-');
                prep.push_back('>');
                prep.push_back(' ');
            }
            int u = path[i];
            int r = u / 8;
            int c = u % 8;
            prep.push_back('a'+r);
            prep.push_back('1'+c);
        }
        res.push_back(prep);
    }
    sort(begin(res),end(res));
    for (auto p : res)cout << p << endl;
}
