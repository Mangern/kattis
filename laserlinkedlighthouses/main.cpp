#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

const double EPS = 1e-6;
#define all(v) begin(v), end(v)

struct UnionFind {
    int num_sets;
    vi p, sz, rnk;
    UnionFind(int n) {
        num_sets = n;
        p = vi(n);
        iota(all(p),0);
        rnk = vi(n,0);
        sz = vi(n,1);
    }

    int find(int i) {
        if (p[i] == i)return i;
        return p[i] = find(p[i]);
    }

    bool check(int i, int j) {
        return find(i)==find(j);
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)return 0;
        if (rnk[i] < rnk[j]) {
            sz[j] += sz[i];
            p[i] = j;
        } else {
            sz[i] += sz[j];
            p[j] = i;
            if (rnk[i] == rnk[j]) {
                ++rnk[i];
            }
        }
        --num_sets;
        return 1;
    }
};

template<class T> struct Point3D {
	typedef Point3D P;
	typedef const P& R;
	T x, y, z;
	explicit Point3D(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}
	bool operator<(R p) const {
		return tie(x, y, z) < tie(p.x, p.y, p.z); }
	bool operator==(R p) const {
		return tie(x, y, z) == tie(p.x, p.y, p.z); }
	P operator+(R p) const { return P(x+p.x, y+p.y, z+p.z); }
	P operator-(R p) const { return P(x-p.x, y-p.y, z-p.z); }
	P operator*(T d) const { return P(x*d, y*d, z*d); }
	P operator/(T d) const { return P(x/d, y/d, z/d); }
	T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
	P cross(R p) const {
		return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
	}
	T dist2() const { return x*x + y*y + z*z; }
	double dist() const { return sqrt((double)dist2()); }
	//Azimuthal angle (longitude) to x-axis in interval [-pi, pi]
	double phi() const { return atan2(y, x); } 
	//Zenith angle (latitude) to the z-axis in interval [0, pi]
	double theta() const { return atan2(sqrt(x*x+y*y),z); }
	P unit() const { return *this/(T)dist(); } //makes dist()=1
	//returns unit vector normal to *this and p
	P normal(P p) const { return cross(p).unit(); }
	//returns point rotated 'angle' radians ccw around axis
	P rotate(double angle, P axis) const {
		double s = sin(angle), c = cos(angle); P u = axis.unit();
		return u*dot(u)*(1-c) + (*this)*c - cross(u)*s;
	}
};

template<class P>
double lineDist(const P& a, const P& b, const P& p) {
	return (double)(b-a).cross(p-a).dist()/(b-a).dist();
}

using P = Point3D<double>;

ostream& operator<<(ostream &os, const P& p) {
    return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> angles;
    for (int i = 0; i < n; ++i) {
        double lat, lon;
        cin >> lat >> lon;
        angles.push_back({lon * acos(-1.0) / 180.0, lat * acos(-1.0) / 180.0});
    }

    P origin(0.0,0.0,0.0);
    vector<double> candidates;
    vector<P> surface;
    for (auto [lon, lat] : angles) {
        P pt(cos(lon) * cos(lat), sin(lon) * cos(lat), sin(lat));
        surface.push_back(pt);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            P between = (surface[i] + surface[j]);
            if (between.dist() < EPS) continue;
            between = between.unit();
            candidates.push_back(1.0 / between.dot(surface[i]));
            candidates.push_back(1.0 / between.dot(surface[j]));
        }
    }
    sort(all(candidates));
    int lo = 0;
    int hi = (int)candidates.size() - 1;

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        double h = candidates[mid];
        UnionFind uf(n);

        vector<P> pts;
        
        for (int i = 0; i < n; ++i) {
            pts.push_back(surface[i] * h);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double d = lineDist(pts[i], pts[j],origin);
                if (d >= 1.0 - 1e-10) {
                    uf.join(i, j);
                }
            }
        }

        if (uf.num_sets == 1) {
            hi = mid;
        } else lo = mid + 1;
    }
    cout << setprecision(18) << fixed << candidates[lo] - 1.0 << endl;
}
