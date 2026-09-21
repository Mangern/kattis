#include <algorithm>
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

ii str_to_state(string s) {
    int idx;
    for (int i = 0; i < 25; ++i) if (s[i] == ' ')idx = i;
    int st = 0;
    while (s.size()) {
        if (s.back() != ' ') {
            st <<= 1;
            st += (s.back() - '0');
        }
        s.pop_back();
    }
    return {idx, st};
}

int ti;
int t = 0b00001000011001111011111;

int dist[25][mxN];

vector<ii> all_offsets = {
    {-2, -1},
    {-2,  1},
    {-1, -2},
    {-1,  2},
    { 1, -2},
    { 1,  2},
    { 2, -1},
    { 2,  1}
};

vector<int> offsets[25];

vector<ii> neighs(int idx, int val) {
    string s;

    for (int i = 0; i < 25; ++i) {
        if (i == idx)s.push_back(' ');
        else {
            s.push_back('0' + (val & 1));
            val >>= 1;
        }
    }

    int hole_i = idx / 5;
    int hole_j = idx % 5;

    vector<ii> ret;
    for (auto o_idx : offsets[idx]) {
        swap(s[idx], s[o_idx]);
        ret.push_back(str_to_state(s));
        swap(s[idx], s[o_idx]);
    }

    return ret;
}

void solve() {
    string inp;
    int si;
    for (int i = 0; i < W; ++i) {
        string tmp;
        getline(cin, tmp);
        for (int j = 0; j < 5; ++j) {
            if (tmp[j] == ' ') {
                si = cti(i, j);
            } else {
                inp.push_back(tmp[j]);
            }
        }
    }

    int s = 0;
    while (inp.size()) {
        s <<= 1;
        s += (int)(inp.back() - '0');
        inp.pop_back();
    }

    if (dist[si][s]) {
        cout << "Solvable in " << dist[si][s]-1 << " move(s)." << endl;
    } else {
        cout << "Unsolvable in less than 11 move(s)." << endl;
    }
}

void search() {
    ti = cti(2,2);
    dist[ti][t] = 1;

    queue<ii> q;
    q.push({ti,t});

    while (!q.empty()) {
        auto [idx, val] = q.front();
        q.pop();

        for (auto [ni, nv] : neighs(idx, val)) {
            if (!dist[ni][nv]) {
                if (dist[idx][val] + 1 < 12) {
                    dist[ni][nv] = dist[idx][val] + 1;
                    q.push({ni,nv});
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);

    for (int hole_idx = 0; hole_idx < 25; ++hole_idx) {
        int hole_i = hole_idx / 5;
        int hole_j = hole_idx % 5;

        for (auto [oi, oj] : all_offsets) {
            int ni = hole_i + oi;
            int nj = hole_j + oj;
            if (ni < 0 || 5 <= ni || nj < 0 || 5 <= nj) continue;
            int o_idx = ni * 5 + nj;
            offsets[hole_idx].push_back(o_idx);
        }
    }
    search();

    while (n-->0)solve();
}
