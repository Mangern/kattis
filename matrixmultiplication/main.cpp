#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u8 = unsigned char;

#define all(v) begin(v), end(v)

const int BUF_SZ = 1<<15;

inline namespace Input {
    char buf[BUF_SZ];
    int pos;
    int len;
    char next_char() {
        if (pos == len) {
            pos = 0;
            len = (int)fread(buf, 1, BUF_SZ, stdin);
            if (!len) { return EOF; }
        }
        return buf[pos++];
    }

    int read_int() {
        int x;
        char ch;
        int sgn = 1;
        while (!isdigit(ch = next_char())) {
            if (ch == '-') { sgn *= -1; }
        }
        x = ch - '0';
        while (isdigit(ch = next_char())) { x = x * 10 + (ch - '0'); }
        return x * sgn;
    }
}

int main() {
    int T = read_int();
    random_device rd;
    mt19937 gen(rd());
    auto dist01 = uniform_int_distribution<int>(0,1);
    while (T-->0) {
        int n, x, y, m;
        n = read_int();
        x = read_int();
        y = read_int();
        m = read_int();
        // n*x, y*m, n*m
        vector<int> A(n*x);
        vector<int> B(m*y);
        vector<int> C(n*m);
        for (auto &el : A) el = read_int();
        for (auto &el : B) el = read_int();
        for (auto &el : C) el = read_int();
        if (x != y) {
            printf("Inner matrix dimensions must agree\n");
            continue;
        }
        bool ok=true;
        vector<int> v(m);
        vector<int> w(y);
        vector<int> u(n);
        for (int round = 0; ok && round < 10; ++round) {
            for (auto &el : v)el = dist01(gen);
            for (int i = 0; i < y; ++i) {
                w[i] = 0;
                for (int j = 0; j < m; ++j) {
                    w[i] += v[j] * B[i*m+j];
                }
            }
            for (int i = 0; i < n; ++i) {
                u[i] = 0;
                for (int j = 0; j < x; ++j) {
                    u[i] += w[j] * A[i*x+j];
                }
                for (int j = 0; j < m; ++j) {
                    u[i] -= v[j] * C[i*m+j];
                }
                if (u[i] != 0) {
                    ok = false;
                    break;
                }
            }
        }
        printf("%s\n",ok?"AC":"WA");
    }
}
