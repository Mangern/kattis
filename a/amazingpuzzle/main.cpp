//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using arr = array<ll, 2>;
using arrr = array<ll, 3>;

const int mxN = 52;

const ll INF = 1e9;

int n, m, e;

int c1, r1, c2, r2, d1, d2;

vector<arr> hor, ver;

// NESW
int dr[4] = {
    1,
    0,
    -1,
    0
};

int dc[4] = {
    0,
    1,
    0,
    -1
};

int delta_d;

bool hasver[mxN][mxN];
bool hashor[mxN][mxN];

arr dist[mxN*mxN*mxN*mxN];

struct state {
    int r1, c1;
    int r2, c2;

    const bool operator<(const state& other) const {
        if (r1 != other.r1) return r1 < other.r1;
        if (c1 != other.c1) return c1 < other.c1;
        if (r2 != other.r2) return r2 < other.r2;
        return c2 < other.c2;
    }

    const int id() const {
        return r1 * mxN*mxN*mxN + r2*mxN*mxN + c1*mxN+c2;
    }
};

pair<state, int> next(state st, int dir) {
    if (st.r1 == 0) return {st, 0};

    int nc = st.c1 + dc[dir];
    int nr = st.r1 + dr[dir];

    int bump = 0;

    if (nc > st.c1 && hasver[st.r1][st.c1]) {
        nc = st.c1;
        ++bump;
    } else if (nc < st.c1 && hasver[st.r1][nc]) {
        nc = st.c1;
        ++bump;
    }

    if (nr > st.r1 && hashor[st.r1][st.c1]) {
        nr = st.r1;
        ++bump;
    } else if (nr < st.r1 && hashor[nr][st.c1]) {
        nr = st.r1;
        ++bump;
    }

    st.r1 = nr;
    st.c1 = nc;
    return {st, bump};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < mxN*mxN*mxN*mxN; ++i) {
        dist[i] = {INF, INF};
    }

    cin >> m >> n >> e;

    char d1c, d2c;

    cin >> c1 >> r1 >> d1c >> c2 >> r2 >> d2c;

    if (d1c == 'N')d1 = 0;
    if (d1c == 'E')d1 = 1;
    if (d1c == 'S')d1 = 2;
    if (d1c == 'W')d1 = 3;

    if (d2c == 'N')d2 = 0;
    if (d2c == 'E')d2 = 1;
    if (d2c == 'S')d2 = 2;
    if (d2c == 'W')d2 = 3;


    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> c >> r;

        hashor[r][c] = 1;
    }

    cin >> k;


    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> c >> r;

        hasver[r][c] = 1;
    }

    for (int r = 1; r <= n; ++r) {
        hasver[r][0] = 1;
        hasver[r][m] = 1;
    }

    for (int c = 1; c <= m; ++c) {
        hashor[n][c] = 1;
        if (c != e)hashor[0][c] = 1;
    }

    delta_d = (d2 - d1 + 4) % 4;

    state start = state{r1, c1, r2, c2};
    dist[start.id()] = {0, 0};

    using pqs = pair<arr, state>;

    priority_queue<pqs, vector<pqs>, greater<pqs>> pq;
    pq.push({{0,0}, start});

    while (pq.size()) {
        auto [d, st] = pq.top();
        pq.pop();
        if (dist[st.id()] < d) continue;

        //cout << st.r1 << " " << st.c1 << " " << st.r2 <<" " << st.c2 << " " << d[0] << " " << d[1] << endl;

        if (st.r1 == 0 && st.r2 == 0) {
            cout << d[0] << " " << d[1] << endl;
            cerr << clock()/static_cast<double>(CLOCKS_PER_SEC) << endl;
            return 0;
        }

        for (int r = 0; r < 4; ++r) {
            state nxt = st;

            state fake = nxt;
            fake.r1 = fake.r2;
            fake.c1 = fake.c2;

            auto [nnxt, bumpnxt] = next(nxt, r);
            auto [nfake, bumpfake] = next(fake, (r + delta_d) % 4);

            nnxt.r2 = nfake.r1;
            nnxt.c2 = nfake.c1;

            if (nnxt.r1 != 0 && nnxt.r1 == nnxt.r2 && nnxt.c1 == nnxt.c2) continue;

            arr ndist = {d[0] + 1, bumpnxt + bumpfake + d[1]};

            if (ndist < dist[nnxt.id()]) {
                dist[nnxt.id()] = ndist;
                pq.push({dist[nnxt.id()], nnxt});
            }
        }
    }

    assert(false);
}
