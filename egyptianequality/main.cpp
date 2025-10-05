//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using arr = array<ll, 2>;
using arrr = array<ll, 3>;
using vi = vector<int>;
using vll = vector<ll>;
#define FORMASK(i, mask) for (int _x = (mask), i; i = 31-__builtin_clz(_x&(-_x)), _x; _x -= (_x&-_x))

vector<vector<bool>> wall;
vector<vector<bool>> stone;
vector<vector<bool>> a;
vector<vector<bool>> visited;

int num_a = 0;
int num_stones = 0;
int n;

void print_result() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n-1; j++) {
            if (wall[i][j]) {
                cout << "#";
            } else if (a[i][j]) {
                cout << "A";
            } else {
                cout << "B";
            }
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    wall.resize(n, vector<bool>(2*n-1, false));
    stone.resize(n, vector<bool>(2*n-1, false));
    a.resize(n, vector<bool>(2*n-1, false));
    visited.resize(n, vector<bool>(2*n-1, false));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 2*n-1; j++) {
            if (s[j] == '#') {
                wall[i][j] = true;
            } else if (s[j] == 'C') {
                num_stones++;
                stone[i][j] = true;
            }
        }
    }

    if (num_stones % 2 == 1) {
        cout << "impossible\n";
        return 0;
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = n-1; j < 2*n-1; j++) {
            //cout << i << " " << j << endl;
            if (wall[i][j]) {
                continue;
            }
            if (num_a >= num_stones/2) {
                continue;
            }
            a[i][j] = true;
            if (stone[i][j]) {
                num_a++;
            }
        }

        for (int j = n-2; j >= 0; j--) {
            //cout << i << " " << j << endl;
            if (wall[i][j]) {
                continue;
            }
            if (num_a >= num_stones/2) {
                continue;
            }
            a[i][j] = true;
            if (stone[i][j]) {
                num_a++;
            }
        }
    }

    if (num_a == num_stones/2) {
        print_result();
        return 0;
    }

    a = vector<vector<bool>>(n, vector<bool>(2*n-1, false));
    num_a = 0;
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < n+i-2; j++) {
            //cout << i << " " << j << endl;
            if (wall[i][j]) {
                continue;
            }
            if (num_a >= num_stones/2) {
                continue;
            }
            a[i][j] = true;
            if (stone[i][j]) {
                num_a++;
            }
        }
    }
    if (num_a == num_stones/2) {
        print_result();
        return 0;
    }

    a = vector<vector<bool>>(n, vector<bool>(2*n-1, false));
    num_a = 0;
    for (int i = n-1; i > 0; i--) {
        for (int k = 0; k < n+i-2; k++) {
            int j = 2*n-2 - k;
            //cout << i << " " << j << endl;
            if (wall[i][j]) {
                continue;
            }
            if (num_a >= num_stones/2) {
                continue;
            }
            a[i][j] = true;
            if (stone[i][j]) {
                num_a++;
            }
        }
    }
    if (num_a == num_stones/2) {
        print_result();
        return 0;
    }

    cout << "impossible\n";
}
