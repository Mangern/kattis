#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)(v).size()
#define all(v) begin(v), end(v)
#define rep(i,s,t) for (int i = (s); i < (t); ++i)

using P = pair<ll, ll>;

void raster(const vector<P>& poly, vector<vector<bool>>& grid) {
    int nx = sz(grid);
    int ny = sz(grid[0]);
    int n = sz(poly);

    vector<vector<bool>> has_ver(nx, vector<bool>(ny, 0));
    for (int i = 0; i < n; ++i) {
        auto [xi, yi] = poly[i];
        auto [xj, yj] = poly[(i+1)%n];

        if (xi == xj) {
            for (int j = min(yi,yj); j < max(yi,yj); ++j) {
                has_ver[xi][j] = 1;
            }
        }
    }
    for (int y = 0; y < ny; ++y) {
        bool inside = 0;
        for (int x = 0; x < nx; ++x) {
            if (has_ver[x][y]) {
                inside = !inside;
            }
            grid[x][y] = inside;
        }
    }
}

void compress(const vector<P>& poly, const vector<ll>& xs, const vector<ll>& ys, vector<P>& p_out) {
    for (auto [x, y] : poly) {
        ll xi = lower_bound(all(xs), x) - begin(xs);
        ll yi = lower_bound(all(ys), y) - begin(ys);
        p_out.emplace_back(xi,yi);
    }
}

int main() {
    int nxy, nxz, nyz;
    vector<P> xy, xz, yz;
    cin >> nxy;
    xy.resize(nxy);
    vector<ll> xs, ys, zs;
    for (auto &[x, y] : xy) {
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
    }
    cin >> nyz;
    yz.resize(nyz);
    for (auto &[y, z] : yz) {
        cin >> z >> y;
        ys.push_back(y);
        zs.push_back(z);
    }
    cin >> nxz;
    xz.resize(nxz);
    for (auto &[x, z] : xz) {
        cin >> x >> z;
        xs.push_back(x);
        zs.push_back(z);
    }
    sort(all(xs));
    sort(all(ys));
    sort(all(zs));
    xs.erase(unique(all(xs)), end(xs));
    ys.erase(unique(all(ys)), end(ys));
    zs.erase(unique(all(zs)), end(zs));

    vector<P> xyi, xzi, yzi;
    compress(xy,xs,ys,xyi);
    compress(xz,xs,zs,xzi);
    compress(yz,ys,zs,yzi);
    int nx = xs.size(), ny = ys.size(), nz = zs.size();
    vector<vector<bool>> gxy(nx, vector<bool>(ny,0));
    vector<vector<bool>> gxz(nx, vector<bool>(nz,0));
    vector<vector<bool>> gyz(ny, vector<bool>(nz,0));

    raster(xyi, gxy);
    raster(xzi, gxz);
    raster(yzi, gyz);

    ll ans = 0;
    for (int x = 0; x < nx; ++x) {
        for (int y = 0; y < ny; ++y) {
            for (int z = 0; z < nz; ++z) {
                if (gxy[x][y] && gxz[x][z] && gyz[y][z]) {
                    ll dx = xs[x+1]-xs[x];
                    ll dy = ys[y+1]-ys[y];
                    ll dz = zs[z+1]-zs[z];
                    ans += dx * dy * dz;
                }
            }
        }
    }
    cout << ans << endl;
}
