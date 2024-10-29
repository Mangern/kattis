#include <bits/stdc++.h>
#include <cmath>
/*MMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNXXKK0KXXXXXXNNNWWWMMMMMMMMMMMMMMMMMMMMMMMMMMM*/
using namespace std;/*MMMMMMWKklc:codl:clldxkkxxkkOXNWMMMMMMMMMMMMMMMMMMMMMMMM*/
using ll=long long;/*MMMMWXkl,...',cddc,,,,:oxkxdooox0NMM*/using ld=long double;
const int/*MMMMMMMWNXK0kxd:........,cdxdoc,';lxOkxdoc:oK*/INF=numeric_limits<int
>::max();/*MMMMMW0oc:;,''..........';cdkkxc'',cdkkddoc;dN*/const ll INFLL=/*MM*/
/*MMMMMMMMMMMMMM0;.............  ....,cdxxo,',:oxkxolooxXM*/numeric_limits<ll>::
max();using vi/*x..   ......        ..,codo:,,:dO0xoccco0W*/=vector<int>;/*MMM*/
template</*MMMMWO;.   .. .           ..;:::::;:lxxdolc:cxN*/typename t, /*MMMM*/
size_t N>/*MMMMMNk:. ...             ..';;:cllloooc:::::lONMMMMMMMMMMMMMMMMMMM*/
using ar=/*MMMMMWKko:,..            ...,:clllooodoc;,,,,:o0WMMMMMMMMMMMMMMMMMM*/
array<t,N>;/*MMWXXXKk:..    .     ....':ccllllllllc:,'.',:xN*/using ii=array<ll,
2>;using vii=/*X0X0kd:.     .    ....';ccllllllllllc:,..':OW*/vector<ii>;/*MMM*/
using vll=/*MWKxlc,....     .  ......;:ccllllllcc:;;;,,,ckX*/vector<ll>;/*MMMM*/
template</*MNk;..      ..    .......',;;;::cllcc;,,,,,cldXM*/typename t> istream
& operator/*d'.       .....  ....',;,'',;;:cllc:;'..,:dkxKM*/>>(istream& in,/**/
vector<t>/*0c..        ........';:;,...',,:clllc:;;;:oO0xkW*/&vec){for(t& x:vec)
{in>>x;}/*W0:..         ......';cc:::;::::cllloollccclxOdxW*/return in;}/*MMMM*/
template</*No'. ...      .....,:cllllcccclllllooolllloO0xKM*/typename t>ostream&
operator<</*Kxc'....      ..',;:cllolllllllllllooolllxKKXW*/(ostream& os,vector<
t>& vec){/*MMWN0o,.......:l:l0KkllooooollllllccclllldOXNWMM*/for(int i=0;i< vec.
size();++i){os<<vec[i];/*NNOlOWWOllooooooollc:;;::coxKWM*/if(i<vec.size()-1)os<<
" ";}return os;}/*MMMMMMMMMMMMMMKoclloooolc;,'''';lx0NWWWMMWWWWWWWWWMMMMMMMMMM*/
#define all(v) begin(v), /*MKONWOl:cclllllllc::::lxxdk0KKKKKXXX*/end(v)/*MMMMM*/
mt19937_64 rng(chrono::/*MMW0O0xc::cccccllllllccclk0dloddddxkkk00K*/steady_clock
::now().time_since_epoch/*Xkl::;;:ccccccccccc::::cdOklcoxxxdoooodddxkO*/().count
());ll myRand(ll B){/*WXOxl:;;;;;:ccclcccccc::::::clollodxdolllllllllodk*/return
(uint64_t)rng()%B;}/*Oxolc::::;;;:cccccccccccccc::cloolccooolllllllllllox0NMMM*/
template<typename/*dolllc:;;::;:::::::cccc:ccccclllllcc;:looollllllllclloxKM*/t> 
t min(const/*0kdollllllll:;;::::::;;;:::ccc:::cllllcccc:;cooolccllllccll*/vector
<t>& v){/*kkxoollllclllolcccllccccccccccccc:;:ccllcclllc:cooollccclcclcc*/return
*min_element/*llllcclllllc:cllllllllllllllc::ccccclllllc:cloollcccccccccl*/(all(
v));}/*W0olllllllllclllllc::ccllllllllllllllllllllllllllclloollc:cccccccclkNMM*/
template/*olllllllllllolol::ccllllllllllllllllllllllllllllcldolc::ccccccclOWM*/<
typename/*oollllcllllloooocccllllllllllllllllllllcccllllolclddoc;:ccccccclOW*/t>
t max(/*Kdoolllllllllloooolcclllllloolllllllllcccccclllooolloddl:;:cccccl*/const
vector</*doollllllllllooooolccllloooooollllllcccccclllooooolodddl::cccccldKK*/t>
& v){/*MXxooolllllcccclooooollllooooddoooolccc::cccllooodddoodddoc:ccccc*/return
*max_element(/*lllcc:;cooooooooooddxkOkxddolc:::cclllooooddddddddocccllllx*/all(
v));}/*MW0ooooollllcc;;loodooodxk0KXNNNXKOdl:;;:cclllloooooooddddolcccc:oKWMMMMM
MMMMMMMMMXxllooollllc::looddddk0KXNNWWWNNKxoc,,:cllllllooooooddddolc::::xNMMMMMM
MMMMMMMMMWKdoloollllc:cooodxkO0KXXXNNNNNNKxol;,cllllllllllllodoooolcc::cOWMMMMMM
MMMMMMMMMMWX0xoooollcclooddk0000KKXXXNNXX0xol:,:lloollllccllooooollcc::dXMMMMMMM
MMMMMMMMMMMMMN0dllllcccooodxkkOO00KKKXXKKOdol:,;llooollcclllllllllc:::l0WMMMMMMM
MMMMMMMMMMMMMMWOlcccc:coooooddxxxkOO0000Oxoll:,,clooollllllllllccc::::xNMMMMMMMM
MMMMMMMMMMMMMMMNxccccccooooooooooooddxxddollc;..;clllllloolllccc:::::oXMMMMMMMMM
MMMMMMMMMMMMMMMW0ocllcclodooooooolllllllcccc:,..';:cllooolllcc::::::l0WMMMMMMMMM
MMMMMMMMMMMMMMMMNxccllccloodooooooolllcccc::;'.';:llllllllcc:::::::lOWMMMMMMMMMM
MMMMMMMMMMMMMMMMMKoccllcclodddooooolllllccccc:ccccc::::;;;;;;::ccclOWMMMMMMMMMMM
MMMMMMMMMMMMMMMMMWOlclllc::clooooolllcccccc::::ccc::;,'.',;::cclclOWMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMNxccllcc:;;;::cccccc:::::;;;cccc::;'',;::clllccdNMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMWW0lcccccc:;,'.,;::::cc::::;:ccc::;'';:cclllcc:c0MMMMMMMMMMMMMM
MMMMMMMMMMMMMMMWNKOdcccccc::;;,'',;;:::::::;:ccc::;,,;:cllllcc:cxNMMMMMMMMMMMMMM
MMMMMMMMMMMWNXXK0xlc::ccccc::;;,''',;:::::;;:cc::;'';ccllllcc::dXMMMMMMMMMMMMMMM
MMMMMMMMMMNXKK0kocc:::cclllccc::,'',;;;;;;,,;::;;,';clllllcc::l0WMMMMMMMMMMMMMMM
MMMMMMMWNXK00Oxlc::::::cllllllcc:;,,;;::::;;;::;,';:cllllcc::lkKWMMMMMMMMMMMMMMM
MMMMMMMKkxkOOxlc:::::::cllllllllc:;,,;;:::::::;,',:cllllcc::lkKXNWMMMMMMMMMMMMMM
MMMMMMWKkkOkdcc:::::::::cllllcllcc:,,,;;;;;;;;,'';cllllccc:cxKXNNNWWMMMMMMMMMMMM
MMMMMMXkdoccc::::::c::;:cllllccccc:;,;;;;;;;;;,',:clllcc::lkKKKXXKKNWMMMMMMMMMMM
MMMMMMKo:::::::::cc::;;::clllccccc:;,,,;;;;;;,'';cccccc::cxKXXKKKKKNMMMMMMMMMMMM
MMMMMMWOc:::::::cc:;;;:::ccllcccccc:,,,,,,,'''',:ccccc::;;ckXNXKKXXNMMMMMMMMMMMM
MMMMMMMNx::::cccc:;;;::;::ccccccccc:;,',,,''..';ccccc:::::;:dKXXKKXNWMMMMMMMMMMM
MMMMMMMKoc::cccc:;;;::::;;::ccccccc:;,'''''..';:cccc::::cc:;;lOXXKKXWMMMMMMMMMMM
MMMMMMM0l::ccc:;;;:::::::;,;:ccccccc:;''''''',:cccc:;;:clllc:;ckKXXWMMMMMMMMMMMM
MMMMMMMWOlcc::;,;::::::::;,;::ccccccc:,'.'.',;:ccc:;;;:cllllc::lONMMMMMMMMMMMMMM
MMMMMMMMW0oldkdc::::::::;;;;;::ccccccc;''''';:ccc:;:::;:clllccco0WMMMMMMMMMMMMMM
MMMMMMMMMMNKNMW0l::::::;;;;;;;::cccccc:,''',;ccc::::::;;:llcccoONMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMWk:;:::;;;;;;;;,,:cccccc;,'',;::cccc:;;;;;:ccclkKNMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMXo;;;::::::;;;,,;:ccccc:;,',;;:ccccc::ccccclox0XWMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMW0l;;:::::::;;;,,;:ccccc::,,;,;::cccccccccldO0KXWMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMWOc;::::::::;;;;;::cccccc:,,'',;;:::::cccokKK0XWMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMXo;::::::::;;;;;::cccccc:;''..',,;::::clx0KK0XWMMMMMMMMMMMMM*/
const double EPS = 1e-9;

struct point_i {
    ll x, y;
    point_i() : x(0), y(0) {}
    point_i(ll x, ll y) : x(x), y(y) {}
    bool operator<(const point_i& other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }

};

struct point {
    double x, y;
    point() : x(0.0), y(0.0) {}
    point(double x, double y) : x(x), y(y) {}
    bool operator<(const point& other) const {
        if (fabs(x - other.x) < EPS) return y < other.y;
        return x < other.x;
    }
    bool operator==(const point& other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
};

struct line {
    double a, b, c; // ax + by + c == 0
                    // b always 0 (vertical line) or 1
};

struct vec {
    double x, y;
    vec() : x(0.0), y(0.0) {}
    vec(double x, double y) : x(x), y(y) {}

    vec operator*(const double& scalar) const {
        return vec(x * scalar, y * scalar);
    }

    vec& operator*=(const double& scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    vec operator+(const vec& other) const {
        return vec(x + other.x, y + other.y);
    }

    vec& operator+=(const vec& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    double dot(const vec& other) const {
        return x * other.x + y * other.y;
    }

    double cross(const vec& other) const {
        return x * other.y - y * other.x;
    }

    point as_point() const {
        return {x, y};
    }
};

double d2r(double d) { return d * M_PIf64 / 180.0; }
double r2d(double d) { return d *  180 / M_PIf64; }

double dist(const point& a, const point& b) {
    return hypotl(a.x - b.x, a.y - b.y);
}

point rotate(const point& p, double theta) {
    return point(p.x * cos(theta) - p.y * sin(theta), p.x * sin(theta) + p.y * cos(theta));
}

void points2line(const point& p1, const point& p2, line& l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l = {1.0, 0.0, -p1.x};
    } else {
        l = {-(double)(p1.y - p2.y) / (p1.x - p2.x),
            1.0,
            -(double)(l.a * p1.x) - p1.y};
    }
}

void pslope2line(const point& p, double slope, line& l) {
    l.a = -slope;
    l.b = 1.0;
    l.c = -((l.a * p.x) + (l.b * p.y));
}

bool parallel(const line& l1, const line& l2) {
    return (fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS);
}

bool operator==(const line& l1, const line& l2) {
    return parallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}

// true with populating p or false if parallel
bool intersect(const line& l1, const line& l2, point& p) {
    if (parallel(l1, l2)) return false;

    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: l1 is vertical
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);

    return true;
}

vec p2vec(const point& p1, const point& p2) {
    return vec(p2.x - p1.x, p2.y - p1.y);
}

double norm_sq(const vec& v) {
    return v.x * v.x + v.y * v.y;
}

// Return the angle aob Assumes a != o != b. 
double angle(const point& a, const point& o, const point& b) {
    vec oa = p2vec(o, a), ob = p2vec(o, b);
    return acos(oa.dot(ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

// return true if r is on the left side of directed ray pq
bool ccw(const point& p, const point& q, const point& r) {
    return p2vec(p, q).cross(p2vec(p, r)) > EPS;
}

bool collinear(const point& p, const point& q, const point& r) {
    return fabs(p2vec(p, q).cross(p2vec(p, r))) < EPS;
}

// distance from p to line formed by ab. closest point on line stored in c
double dist_to_line(const point& p, const point& a, const point& b, point& c) {
    vec ap = p2vec(a, p), ab = p2vec(a,b);
    double u = ap.dot(ab) / norm_sq(ab);
    c = (p2vec({0,0}, a) + ab*u).as_point();
    return dist(p, c);
}

// distance from p to line segment between a and b. closest point stored in c.
double dist_to_lineseg(const point& p, const point& a, const point& b, point& c) {
    vec ap = p2vec(a, p), ab = p2vec(a, b);
    double u = ap.dot(ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if (u > 1.0) {
        c = point(b.x, b.y);
        return dist(p, b);
    }
    return dist_to_line(p, a, b, c);
}

// 1: inside, 0: border, -1: outside
int inside_circle(const point_i &p, const point_i &c, ll r) {
    ll dx = p.x - c.x, dy = p.y - c.y;
    ll d = dx * dx + dy * dy, rsq = r * r;
    return d < rsq ? 1 : (d == rsq ? 0 : -1);
}

// 1: inside, 0: border, -1: outside
int inside_circle(const point& p, const point& c, double r) {
    double d = norm_sq(p2vec(p, c));
    double rsq = r * r;
    if (fabs(d - rsq) < EPS) return 0;
    return d < rsq ? 1 : -1;
}

// given two points on circle with radius r, compute a candidate center (or return impossible)
bool circle2pr(const point& p1, const point& p2, const double& r, point& c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < EPS) return false;
    double h = sqrt(det);
    // to get other center, swap p1 and p2 here.
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}

// triangle side lengths ab, bc, ca, compute the perimeter
double perimeter(const double& ab, const double& bc, const double& ca) {
    return ab + bc + ca;
}

// triangle side lengths ab, bc, ca, compute the area
double area(const double& ab, const double& bc, const double& ca) {
    double s = 0.5 * perimeter(ab, bc, ca);
    // herons formula
    return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

// triangle side lengths ab, bc, ca, get the radius of incircle.
double incircle_radius(const double& ab, const double& bc, const double& ca) {
    return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}

double incircle_radius(const point& a, const point& b, const point& c) {
    return incircle_radius(dist(a, b), dist(b, c), dist(c, a));
}

// compute the incircle or return false on failure (collinear)
bool incircle(const point& p1, const point& p2, const point& p3, point& center, double& radius) {
    radius = incircle_radius(p1, p2, p3);
    if (fabs(radius) < EPS) return false;

    line l1, l2;
    double ratio = dist(p1, p2) / dist(p1, p3);
    point p = (p2vec({0, 0}, p2) + p2vec(p2, p3) * (ratio / (1 + ratio))).as_point();

    points2line(p1, p, l1);

    ratio = dist(p2, p1) / dist(p2, p3);
    p = (p2vec({0, 0}, p1) + p2vec(p1, p3) * (ratio / (1 + ratio))).as_point();
    points2line(p2, p, l2);
    intersect(l1, l2, center);
    return true;
}

double circumcircle_radius(const double& ab, const double& bc, const double& ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

double circumcircle_radius(const point& a, const point& b, const point& c) {
    return circumcircle_radius(dist(a,b), dist(b,c), dist(c, a));
}

// check if (a, b) is inside rect (x, y) -> (x+w, y+h)
// 1: inside, 0: perimeter, -1: outside
int inside_rect(ll x, ll y, ll w, ll h, ll a, ll b) {
    if ((x < a) && (a < x + w) && (y < b) && (b < y + h)) {
        return 1;
    } else if ((x <= a) && (a <= x + w) && (y <= b) && (b <= y + h)) {
        return 0;
    } 
    return -1;
}
const int mxN = 2e5+6;
const ll MOD  = 1e9+7;

void testCase() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int m;
    cin >> m;

    vector<string> ans;
    double ad = INFINITY;
    point a(x1,y1), b(x2,y2), c;

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s >> x1 >> y1;
        double d = dist_to_line(point(x1, y1), a, b, c);
        if (d < ad - EPS) {
            ans.clear();
        }
        if (d <= ad + EPS) {
            ad = d;
            ans.push_back(s);
        }
    }
    cout << ans << endl;

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
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
