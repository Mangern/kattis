#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()
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
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<double> P;
vector<P> convexHull(vector<P> pts) {
	if (sz(pts) <= 1) return pts;
	sort(all(pts));
	vector<P> h(sz(pts)+1);
	int s = 0, t = 0;
	for (int it = 2; it--; s = --t, reverse(all(pts)))
		for (P p : pts) {
			while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	for(int i = 0; i < sz(v)-1; ++i) a += v[i].cross(v[i+1]);
	return a;
}

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        int n;
        cin >> n;

        vector<Point<double>> pts;
        double ar_in = 0.0;
        for (int i = 0; i < n; ++i) {
            double x, y, w, h, v;
            cin >> x >> y >> w >> h >> v;
            v = -v * M_PI / 180.0;

            vector<Point<double>> rect;
            rect.emplace_back(-w/2.0, -h/2.0);
            rect.emplace_back(-w/2.0, h/2.0);
            rect.emplace_back(w/2.0, h/2.0);
            rect.emplace_back(w/2.0, -h/2.0);
            for (auto& p : rect)
                p = p.rotate(v);
            for (auto& p : rect)
                p = p + Point<double>{x,y};

            for (const auto& p: rect)
                pts.push_back(p);

            ar_in += abs(polygonArea2(rect)) / 2.0;
        }

        auto hull = convexHull(pts);
        double ar_out = abs(polygonArea2(hull)) / 2.0;
        double ans = ar_in / ar_out * 100.0;

        printf("%.1f %%\n", ans);
    }
}
