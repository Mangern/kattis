#include <bits/stdc++.h>
using namespace std;

int reg[10];
int ram[1000];

int main() {
    int inst;
    int ptr = 0;
    int* insts = ram;
    for (;;) {
        if (!(cin >> inst)) break;
        insts[ptr++] = inst;
    }

    int ip = 0;

    int ans = 0;
    for (;;) {
        int inst  = insts[ip];

        int t = inst / 100;
        int a = (inst - t * 100) / 10;
        int b = inst % 10;
        ++ans;
        if (t == 1) {
            break;
        }
        if (t == 2) {
            int d = a;
            int n = b;
            reg[d] = n;
            ++ip;
            continue;
        }
        if (t == 3) {
            int d = a;
            int n = b;
            reg[d] += n;
            reg[d] %= 1000;
            ++ip;
            continue;
        }
        if (t == 4) {
            int d = a;
            int n = b;
            reg[d] *= n;
            reg[d] %= 1000;
            ++ip;
            continue;
        }
        if (t == 5) {
            int d = a;
            int s = b;
            reg[d] = reg[s];
            ++ip;
            continue;
        }
        if (t == 6) {
            int d = a;
            int s = b;
            reg[d] += reg[s];
            reg[d] %= 1000;
            ++ip;
            continue;
        }
        if (t == 7) {
            int d = a;
            int s = b;
            reg[d] *= reg[s];
            reg[d] %= 1000;
            ++ip;
            continue;
        }
        if (t == 8) {
            int d = a;
            int addr = b;
            reg[d] = ram[reg[addr]];
            ++ip;
            continue;
        }
        if (t == 9) {
            int s = a;
            int addr = b;
            ram[reg[addr]] = reg[s];
            ++ip;
            continue;
        }
        if (t == 0) {
            int d = a;
            int s = b;
            if (reg[s] != 0) {
                ip = reg[d];
            } else {
                ++ip;
            }
            continue;
        }
    }
    cout << ans << endl;
}
