#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int mxN = 51;


const int INF = 10000000;

int r, n, a, b, x;
int grid[2*mxN][2*mxN];
int dist[2 * mxN * 2*mxN];
pair<int,int> idx[2 * mxN * 2 * mxN];

vector<int> neis(int id) {
    auto [i, j] = idx[id];
    vector<int> ret;
    for (auto [ni, nj] : vector<pair<int,int>>{{i-1,j},{i,j+1},{i+1,j+1},{i+1,j},{i,j-1},{i-1,j-1}}) {
        if (ni < 0 || ni >= 2 * mxN || nj < 0 || nj >= 2 * mxN) continue;
        if (grid[ni][nj] == -1) continue;
        ret.push_back(grid[ni][nj]);
    }
    return ret;
}

int main() {

    for (int i = 0; i < 2 * mxN; ++i) {
        for (int j = 0; j < 2 * mxN; ++j) {
            grid[i][j] = -1;
            dist[i* 2 * mxN + j] = INF;
        }
    }

    scanf("%d%d%d%d%d",&r,&n, &a, &b, &x);

    int tim = 1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < r + i; ++j) {
            grid[i][j] = tim;
            idx[tim] = {i, j};
            ++tim;
        }
    }
    for (int i = 0; i < r - 1; ++i) {
        for (int j = i+1; j < 2 * r - 1; ++j) {
            grid[r+i][j] = tim;
            idx[tim] = {r+i, j};
            ++tim;
        }
    }

    for (int i = 0; i < x; ++i) {
        int y; 
        cin >> y;
        dist[y] = -1;
    }

    if (dist[a] == -1) {
        printf("No\n");
        return 0;
    }

    dist[a] = 0;

    queue<int> q;
    q.push(a);

    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : neis(u)) {
            if (dist[v] != INF) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    if (dist[b] > n || dist[b] == -1) {
        printf("No\n");
    } else printf("%d\n", dist[b]);
}
