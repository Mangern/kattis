#include <bits/stdc++.h>
using namespace std;

int code[7];
int n;
int done;

void out() {
    if (++done == n) {
        for (int i = 0; i < 7; ++i)cout << code[6-i];
        cout << endl;
        exit(0);
    }
}

void grey(int idx) {
    for (int i = 0; i < 9; ++i) {
        if (idx > 0) {
            grey(idx - 1);
        }
        code[idx] += 1;
        code[idx] %= 10;
        out();
    }
    if (idx > 0) {
        grey(idx - 1);
    }
}

int main() {
    cin >> n;
    grey(6);
}
