#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;

int n, m;
int graphn;
string grid[mxN];

int node[mxN][mxN];

vector<int> adj[mxN * mxN];
int col[mxN * mxN];

int rowp[mxN * mxN];
int colp[mxN * mxN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        memset(node[i], -1, sizeof(node[i]));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.' && node[i][j] == -1) {
                node[i][j] = graphn++;
                for (int di = 0; di < 3; ++di) for (int dj = 0; dj < 3; ++dj) {
                    node[i+di][j+dj] = node[i][j];
                }
                int rowp = (i / 3) % 2 + 1;
                int colp = ((j / 3) % 2) * 2;
                col[node[i][j]] = rowp + colp;
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*')cout << '*';
            else {
                cout << col[node[i][j]];
            }
        }
        cout << "\n";
    }
}
