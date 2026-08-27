#include <iostream>
#include <iterator>
#include <map>

using namespace std;

const int mxN = 50005;
const int K = 16;

int n;
map<int, int> idx;

int r[mxN];
int rmq[K][mxN];

int query(int i, int j) {
    if (i == j)return r[i];
    int len = j + 1 - i;
    int p2 = __lg(len);
    if ((1<<p2) == len)--p2;

    return max(rmq[p2][i], rmq[p2][j+1-(1<<p2)]);
}

void solve(int n) {

    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;

        idx[y] = i;
        cin >> r[i];
        rmq[0][i] = r[i];
    }

    for (int k = 1; k < K; ++k) { for (int i = 0; i + (1<<k) <= n; ++i) {
        rmq[k][i] = max(rmq[k-1][i], rmq[k-1][i+(1<<(k-1))]);
    }}

    int q;
    cin >> q;

    while (q-->0) {
        int y, x;
        cin >> y >> x;

        auto ity = idx.find(y);
        auto itx = idx.find(x);

        if (ity == idx.end() && itx == idx.end()) {
            cout << "maybe" << endl;
        } else if (ity == idx.end()) {
            ity = idx.upper_bound(y);
            if (ity == itx || query(ity->second, itx->second - 1) < r[itx->second]) {
                cout << "maybe" << endl;
            } else {
                cout << "false" << endl;
            }
        } else if (itx == idx.end()) {
            itx = --idx.upper_bound(x);
            if (itx == ity || query(ity->second + 1, itx->second) < r[ity->second]) {
                cout << "maybe" << endl;
            } else {
                cout << "false" << endl;
            }
        } else {
            if (r[itx->second] <= r[ity->second] && 
                (next(ity) == itx || 
                 query(ity->second + 1, itx->second -1) < r[itx->second])) 
            {
                if (itx->second - ity->second == x - y) {
                    cout << "true" << endl;
                } else {
                    cout << "maybe" << endl;
                }
            } 
            else 
            {
                cout << "false" << endl;
            }
        }
    }
}

int main() {
    bool f= 0;
    while (true) {
        int n;
        cin >> n;
        if (!n) {
            cin >> n;
            break;
        }
        if (f)cout << endl;
        else f = 1;
        solve(n);
    }
}
