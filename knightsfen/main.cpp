#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ii = array<int,2>;


const int INF = numeric_limits<int>::max();

const int mxN = (1<<24);
const int W = 5;

int cti(int i, int j) {
    return i * W + j;
}

ii itc(int i) {
    return {i / W, i % W};
}

int ti;
int t = 0b00001000011001111011111;

int dist[25][mxN];

vector<ii> neighs(int idx, int val) {
    cout << "call" << endl;
    string s;

    for (int i = 0; i < 25; ++i) {
        if (i == idx)s.push_back(' ');
        else {
            s.push_back('0' + (val & 1));
            val >>= 1;
        }
    }

    cout << s << endl;
    exit(0);
    return {};
}

void solve() {
    ti = cti(2,2);
    string inp;
    int si;
    for (int i = 0; i < W; ++i) {
        string tmp;
        cin >> tmp;
        inp += tmp;
        if (tmp.size() < 5) {
            si = cti(i, tmp.size());
            cin >> tmp;
            inp += tmp;
        }
    }



    int s = 0;
    while (inp.size()) {
        s <<= 1;
        s += (int)(inp.back() - '0');
        inp.pop_back();
    }

    dist[si][s] = 0;

    queue<ii> q;
    q.push({si,s});

    while (!q.empty()) {
        auto [idx, val] = q.front();
        q.pop();
        if (idx == ti && val == t) {
            cout << "Solvable in " << dist[ti][t] << " move(s)." << endl;
            return;
        }

        if (dist[idx][val] >= 11) {
            cout << "Unsolvable in less than 11 move(s)." << endl;
            return;
        }

        for (auto [ni, nv] : neighs(idx, val)) {
            if (dist[ni][nv] == -1) {
                dist[ni][nv] = dist[idx][val] + 1;
                q.push({ni,nv});
            }
        }
    }
    assert(false);
}

int main() {
    int n;
    cin >> n;

    while (n-->0)solve();
}
