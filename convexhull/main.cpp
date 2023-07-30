// GOD DAWMMNNN
// std::sort is one hell of a bitch
// strict weak ordering is a THING and your predicate has to be IT
// so compare(X,X) == false
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,2>;
using vii = vector<ii>;
using ld = long double;

#define all(v) begin(v), end(v)

ll sqdst(ii a, ii b) {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

int ccw(ii a, ii b, ii c) {
    if (a == b || a == c || b == c)return 0;
    ll v = (b[1] - a[1]) * (c[0] - a[0]) - (c[1] - a[1]) * (b[0] - a[0]);
    if (v == 0LL)return 0;
    if (v > 0)return 1;
    return 2;
}

bool testCase() {
    int n;
    cin >> n;
    if (n == 0)return false;

    vector<ii> pts;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        pts.push_back({x,y});
    }


    if (pts.size() != n) {
        cout << "WTF" << endl;
        return true;
    }

    int mini = 0;
    ii minp = pts[0];

    for (int i = 0; i < n; ++i) {
        if ((pts[i][1] < minp[1]) || (pts[i][1] == minp[1] && pts[i][0] < minp[0])) {
            mini = i;
            minp = pts[i];
        }
    }

    pts[mini][0] = pts[0][0];
    pts[mini][1] = pts[0][1];
    pts[0][0] = minp[0];
    pts[0][1] = minp[1];

    ii p0 = pts[0];

    //for (auto pp : pts)cout << pp[0] << " " << pp[1] << endl;


    sort(++pts.begin(),pts.end(), [&] (const ii a, const ii b) {

            //cout << "cmp: (" << a[0] << ", " << a[1] << ") and (" << b[0] << ", " << b[1] << ")" << endl;
            int o = ccw(p0,a,b);
            if (o == 0) {
                return sqdst(p0,a) > sqdst(p0,b);
            }
            if (o == 2)return true;
            return false;
    });
    //cout << "Got here" << endl;


    int m = 1;
    int i;
    if (p0 != pts[0]) {
        cout << "WHAT" << endl;
        return true;
    }
    vii npts(1,p0);
    for (i = 1; i < n; ++i) {
        if (pts[i] == npts.back())continue;

        while (i < n && npts.size() >= 2 && ccw(p0,npts.back(), pts[i]) == 0)++i;
        if (i == n)break;

        npts.push_back(pts[i]);
    }
    swap(pts,npts);
    m = pts.size();

    vii hull;
    if (m < 3) {
        hull = pts;
    } else {
        for (int i = 0; i < m; ++i) {
            //cout << pts[i][0] << " " << pts[i][1] << "!" << endl;
            if (i >= n) {
                cout << "I dont know anything" << endl;
                return true;
            }
            while (hull.size() >= 2) {
                ii bck = hull.back();
                hull.pop_back();

                if (ccw(hull.back(), bck, pts[i]) == 2) {
                    hull.push_back(bck);
                    break;
                }
            }
            hull.push_back(pts[i]);
        }
    }

    cout << hull.size() << endl;
    for (auto pp : hull)cout << pp[0] << " " << pp[1] << endl;

    return true;
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

    int solved = 0;
    while (testCase()){
        //cout << "SOLVED:" << ++solved << endl;
    }

    return 0;
}
