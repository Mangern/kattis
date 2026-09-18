#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;

const u64 INV = 881051043651;

u64 decrypt(u64 val) {
    val -= 68431307;
    val *= INV;
    return val;
}

int main() {
    for (int i = 0; i < 100; ++i) {
        u64 x;
        cin >> x;
        cout << decrypt(x) << endl;
    }
}
