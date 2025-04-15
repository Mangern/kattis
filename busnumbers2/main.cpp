#include <iostream>

using namespace std;

int cnt[400001];

int main() {
    int m;
    cin >> m;

    // Find largest bus num <= m
    for (int i = 1; i < 74; i++) {
        for (int j = i; j < 74; j++) {
            int sum = i * i * i + j * j * j;
            //cout << i << "^3 + " << j << "^3 = " << sum << endl;
            if (sum <= m) {
                cnt[sum]++;
            }
        }
    }
    
    int max = 0;
    for (int i = 0; i <= m; i++) {
        if (cnt[i] >= 2) {
            max = i;
        }
    }
    if (max == 0) {
        cout << "none" << endl;
    }
    else {
        cout << max << endl;
    }
    return 0;
}

