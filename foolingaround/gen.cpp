#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int mxN = 1e9+1;

bool isprime[mxN];
vector<int> primes;
bool win[mxN];

void sieve() {
    memset(isprime, 1, sizeof isprime);

    isprime[0] = isprime[1] = 0;

    for (ll i = 2; i < mxN; ++i) {
        if (!isprime[i])continue;
        primes.push_back(i);
        for (ll j = i * i; j < mxN; j += i) {
            isprime[j] = 0;
        }
    }
}

int main() {
    sieve();
    
    int cnt = 0;
    for (int i = 0; i < mxN; ++i) {
        if (win[i])continue;

        for (int p : primes) {
            if (i + p - 1 >= mxN)break;
            win[i+p-1] = 1;
        }
        if (!i)continue;
        cout << i << endl;
        ++cnt;
    }

    cout << cnt << endl;
}
