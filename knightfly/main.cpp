#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,3>;
using vii = vector<ii>;

#define all(v) begin(v), end(v)

const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (unsigned ll)rng() % B;
}
template<typename t>
istream& operator >> (istream& in, vector<t>& vec) {
    for (t& x : vec)in >> x;
    return in;
}

template<typename t>
ostream& operator << (ostream& out, vector<t>& vec) {
    int n = (int)vec.size();
    for (int i = 0; i < n; ++i) {
        out << vec[i];
        if (i < n - 1)out << " ";
    }
    return out;
}

// t should support min-function (operator <)
template<typename t>
t min(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = min(ans, el);
    }
    return ans;
}

// t should support max-function (operator <)
template<typename t>
t max(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = max(ans, el);
    }
    return ans;
}
const int mxN = 2e5+3;

int n;

void testCase() {
    cin >> n;


    ii start;
    cin >> start[0] >> start[1];
    ii goal;
    cin >> goal[0] >> goal[1];

    int s = -1, t;

    vii pos;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;

        pos.push_back({x,y,i});

        if (x == start[0] && y == start[1])s = i;
        if (x == goal[0] &&  y == goal[1])t = i;
    }
    assert(s != -1);

    vector<vi> nxt(n, vi(4,-1)); //lrud

    vii tpos = pos;
    sort(all(tpos));

    //cout << endl;
    for (int i = 1; i < n; ++i) {
        if (tpos[i-1][0] == tpos[i][0]) {
            nxt[tpos[i][2]][3] = tpos[i-1][2]; // i is above i-1
            nxt[tpos[i-1][2]][2] = tpos[i][2];
        }
    }

    sort(all(tpos), [&] (auto a, auto b) {
        if (a[1] == b[1])return a[0] < b[0];
        return a[1] < b[1];
    });

    //for (auto pp : tpos)cout << pp[0] << " " << pp[1] << " " << pp[2] << endl;

    //cout << endl;
    for (int i = 1; i < n; ++i) {
        //cout << tpos[i-1][2] << " " << tpos[i][2] << endl;
        if (tpos[i-1][1] == tpos[i][1]) {
            nxt[tpos[i][2]][0] = tpos[i-1][2];
            nxt[tpos[i-1][2]][1] = tpos[i][2];
        }
    }


    vector<vi> adj(n, vi());

    for (int i = 0; i < n; ++i) {
        for (int dub = 0; dub < 4; ++dub) {
            if (nxt[i][dub] == -1 || nxt[nxt[i][dub]][dub] == -1)continue;
            for (int sin = 0; sin < 4; ++sin) {
                if (max(dub,sin) <= 1)continue;
                if (min(dub,sin) >= 2)continue;
                int j = nxt[i][dub];
                j = nxt[j][dub];
                j = nxt[j][sin];
                if (j == -1)continue;
                adj[i].push_back(j);
            }
        }
    }

    queue<int> q;
    vi dist(n, INF);
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) if (dist[v] == INF) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    if (dist[t] == INF) {
        dist[t] = -1;
    }
    cout << dist[t] << endl;
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}

int main() {
    setIO();
    pre();
    int t = 1;
    //cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
