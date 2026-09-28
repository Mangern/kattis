#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

#define sz(v) (int)(v).size()
#define rep(i,s,t) for (int i = (s); i < (t); ++i)

int matInv(vector<vector<double>>& A) {
	int n = sz(A); vi col(n);
	vector<vector<double>> tmp(n, vector<double>(n));
	rep(i,0,n) tmp[i][i] = 1, col[i] = i;

	rep(i,0,n) {
		int r = i, c = i;
		rep(j,i,n) rep(k,i,n)
			if (fabs(A[j][k]) > fabs(A[r][c]))
				r = j, c = k;
		if (fabs(A[r][c]) < 1e-12) return i;
		A[i].swap(A[r]); tmp[i].swap(tmp[r]);
		rep(j,0,n)
			swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
		swap(col[i], col[c]);
		double v = A[i][i];
		rep(j,i+1,n) {
			double f = A[j][i] / v;
			A[j][i] = 0;
			rep(k,i+1,n) A[j][k] -= f*A[i][k];
			rep(k,0,n) tmp[j][k] -= f*tmp[i][k];
		}
		rep(j,i+1,n) A[i][j] /= v;
		rep(j,0,n) tmp[i][j] /= v;
		A[i][i] = 1;
	}

	/// forget A at this point, just eliminate tmp backward
	for (int i = n-1; i > 0; --i) rep(j,0,i) {
		double v = A[j][i];
		rep(k,0,n) tmp[j][k] -= v*tmp[i][k];
	}

	rep(i,0,n) rep(j,0,n) A[col[i]][col[j]] = tmp[i][j];
	return n;
}

int main() {
    int n, q, m;
    cin >> n >> q >> m;

    vector<vector<double>> L(n, vector<double>(n, 1.0 / (double)n));
    int cnt = 0;
    for (;cnt < m;) {
        int u;
        cin >> u, --u;
        int k;
        cin >> k;
        cnt += k;
        for (int i = 0; i < k; ++i) {
            int v;
            cin >> v, --v;

            L[u][u] += 1.0;
            L[v][v] += 1.0;
            L[u][v] -= 1.0;
            L[v][u] -= 1.0;
        }
    }

    assert(matInv(L) == n);
    while (q-->0) {
        int u, v;
        cin >> u >> u >> v, --u, --v;
        double ans = L[u][u] + L[v][v] - L[u][v] - L[v][u];
        cout << setprecision(6) << fixed << ans << endl;
    }
}
