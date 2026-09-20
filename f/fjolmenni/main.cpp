#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ns, nb;
ll sdivs[100000];
ll bdivs[100000];

const int BUF_SZ = 1 << 15;
char buf[BUF_SZ];
int pos;

void flush_out() {
	fwrite(buf, 1, pos, stdout);
	pos = 0;
}

void write_char(char c) {
	if (pos == BUF_SZ) { flush_out(); }
	buf[pos++] = c;
}

void write_int(ll x) {
	static char num_buf[100];
	int len = 0;
	for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
	write_char((char)('0' + x));
	while (len) { write_char(num_buf[--len]); }
	write_char(' ');
}

// auto-flush output when program exits
void init_output() { assert(atexit(flush_out) == 0); }

int main() {
    init_output();
    ll n;
    scanf("%lld", &n);

    for (ll d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            sdivs[ns++] = d;
            if (d * d < n)bdivs[nb++] = n/d;
        }
    }
    for (int i = 0; i < ns; ++i) {
        write_int(sdivs[i]);
    }
    while (nb) {
        write_int(bdivs[--nb]);
    }
    write_char('\n');
}
