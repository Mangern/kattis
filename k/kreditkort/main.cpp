#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int,int>> costs = {
        {500, 500},
        {1000,1000},
        {2000,2000},
        {5000,5250},
        {10000,11000},
        {20000,24000}
    };

    int n;
    cin >> n;

    for (auto [cost, val] : costs) {
        if (val >= n) {
            cout << cost << endl;
            break;
        }
    }
}
