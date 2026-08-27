#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const ll INF = numeric_limits<ll>::max() / 8;

#define all(v) begin(v), end(v)

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
    T man() const { return abs(x) + abs(y); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

template<class P>
P lineProj(P a, P b, P p, bool refl=false) {
	P v = b - a;
	return p - v.perp()*(1+refl)*v.cross(p-a)/v.dist2();
}

using P = Point<ll>;

ll dx[4] = {1,0,-1, 0};
ll dy[4] = {0,1, 0,-1};

const int mxN = 1e6;

vector<ii> adj[mxN];
ll dist[mxN];
ll p[mxN];

int main() {
    int n;
    cin >> n;
    string instr;

    vector<P> pts = {P{0,0}};
    int dir = 0;
    for (int i = 0; i < n; ++i) {
        cin >> instr;

        if (instr == "<") {
            dir = (dir + 1) % 4;
        } else if (instr == ">") {
            dir = (dir + 3) % 4;
        } else if (instr == "U") {
            dir = (dir + 2) % 4;
        } else {
            ll len = stoll(instr);
            auto [px, py] = pts.back();
            pts.push_back(P{px + dx[dir] * len, py + dy[dir] * len});
        }
    }

    map<P, int> idx;
    vector<P> inters;

    for (auto p : pts) {
        if (!idx.count(p)) {
            idx[p] = inters.size();
            inters.push_back(p);
        }
    }

    vector<vector<P>> onseg(pts.size());
    for (int i = 0; i < pts.size() - 1; ++i) {
        // all intersection points on current segment
        vector<P> oncurr;
        // created by other segments
        for (int j = 0; j < pts.size() - 1; ++j) {
            vector<P> ints = segInter(pts[i], pts[i+1], pts[j], pts[j+1]);
            for (auto p : ints) {
                if (!idx.count(p)) {
                    idx[p] = inters.size();
                    inters.push_back(p);
                }
                int u = idx[p];
                for (auto q : vector<P>{pts[i], pts[i+1],pts[j],pts[j+1]}) {
                    ll w = (p - q).man();
                    adj[u].push_back({idx[q], w});
                    adj[idx[q]].push_back({u, w});
                }
            }
            for (auto p : ints)oncurr.push_back(p);
        }
        // created by other endpoints being distance 1 away
        for (auto p : pts) {
            if (onSegment(pts[i], pts[i+1], p)) continue;

            auto q = lineProj(pts[i], pts[i+1], p);
            ll d = (p-q).man();

            if (d == 1 && onSegment(pts[i], pts[i+1], q)) {
                if (!idx.count(q)) {
                    idx[q] = inters.size();
                    inters.push_back(q);
                }
                assert(idx.count(p));
   
                adj[idx[p]].push_back({idx[q], 1});
                adj[idx[q]].push_back({idx[p], 1});
                oncurr.push_back(q);
            }

            if ((p - pts[i]).man() == 1) {
                adj[idx[p]].push_back({idx[pts[i]], 1});
                adj[idx[pts[i]]].push_back({idx[p], 1});
            }
            if ((p - pts[i+1]).man() == 1) {
                adj[idx[p]].push_back({idx[pts[i+1]], 1});
                adj[idx[pts[i+1]]].push_back({idx[p], 1});
            }
        }

        sort(all(oncurr));
        oncurr.erase(unique(all(oncurr)), end(oncurr));

        onseg[i] = oncurr;

    }
    for (int i = 0; i < inters.size(); ++i) {
        auto p = inters[i];
        for (int dir = 0; dir < 4; ++dir) {
            Point q{p.x+dx[dir],p.y+dy[dir]};
            if (idx.count(q)) {
                adj[idx[p]].push_back({idx[q], 1});
                adj[idx[q]].push_back({idx[p], 1});
            }
        }
    }

    for (int i = 0; i < inters.size(); ++i) {
        auto p = inters[i];
        for (int j = 0; j < pts.size() - 1; ++j) {
            if (onSegment(pts[j], pts[j+1], p)) continue;
            auto q = lineProj(pts[j], pts[j+1], p);
            if (!onSegment(pts[j], pts[j+1], q)) continue;
            if ((p-q).man() != 1) continue;
            if (!idx.count(q)) {
                idx[q] = inters.size();
                inters.push_back(q);
            }
            adj[idx[p]].push_back({idx[q], 1});
            adj[idx[q]].push_back({idx[p], 1});
            onseg[j].push_back(q);
        }
    }

    for (int i = 0; i < pts.size(); ++i) {
        auto& oncurr = onseg[i];
        sort(all(oncurr));
        oncurr.erase(unique(all(oncurr)), end(oncurr));
        for (int j = 0; j < (int)oncurr.size() - 1; ++j) {
            adj[idx[oncurr[j]]].push_back({idx[oncurr[j+1]], (oncurr[j+1] - oncurr[j]).man()});
            adj[idx[oncurr[j+1]]].push_back({idx[oncurr[j]], (oncurr[j+1] - oncurr[j]).man()});
        }
    }

    int s = idx[pts.back()];
    int t = idx[pts[0]];
    n = idx.size();

    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
    }
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                p[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    int ptr = t;
    vector<P> path;
    while (ptr != s) {
        path.push_back(inters[ptr]);
        ptr = p[ptr];
    }
    path.push_back(inters[s]);

    reverse(all(path));

    vector<P> npath;
    npath.push_back(path[0]);

    for (int i = 1; i < path.size(); ++i) {
        if (npath.size() >= 2) {
            auto p1 = npath[npath.size() - 2];
            auto p2 = npath[npath.size() - 1];
            auto p3 = path[i];
            // check if they are collinear
            int dx1, dy1, dx2, dy2;

            if (p2.x == p1.x) dx1 = 0;
            else if (p2.x > p1.x) dx1 = 1;
            else dx1 = -1;

            if (p2.y == p1.y) dy1 = 0;
            else if (p2.y > p1.y) dy1 = 1;
            else dy1 = -1;

            if (p3.x == p2.x) dx2 = 0;
            else if (p3.x > p2.x) dx2 = 1;
            else dx2 = -1;

            if (p3.y == p2.y) dy2 = 0;
            else if (p3.y > p2.y) dy2 = 1;
            else dy2 = -1;

            if (dx1 == dx2 && dy1 == dy2) {
                npath.pop_back();
            }
        }
        npath.push_back(path[i]);
    }

    path = npath;

    const ll BIG = 1000000;

    for (int i = 0; i < path.size() - 1; ++i) {
        ll nlen = (path[i+1] - path[i]).man();
        int ndir;
        for (ndir = 0; ndir < 4; ++ndir) {
            if (P{path[i].x + dx[ndir] * nlen, path[i].y + dy[ndir] * nlen} == path[i+1])
                break;
        }
        assert(ndir < 4);
        if (ndir == (dir + 1) % 4) {
            cout << "< ";
        } else if (ndir == (dir + 3) % 4) {
            cout << "> ";
        } else if (ndir == (dir + 2) % 4) {
            cout << "U ";
        }
        cout << nlen << " ";
        dir = ndir;
    }
    cout << "exit" << endl;
}
