#include <bits/stdc++.h>
using namespace std;

void output(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " \n"[i==nums.size()-1];
    }
}

vector<vector<int>> sol;

void gen(int n) {
    if (n == 1) {
        sol.push_back(vector<int>(1, 1));
        return;
    }

    gen(n - 1);
    vector<vector<int>> nsol;

    int start = 1;

    for (int i = 0; i < sol.size(); ++i) {
        if (start == 0) {
            for (int j = 0; j <= n - 1; ++j) {
                vector<int> v = sol[i];
                v.insert(v.begin()+j, n);
                nsol.push_back(v);
            }
            start = 1;
        } else {
            for (int j = n - 1; j >= 0; --j) {
                vector<int> v = sol[i];
                v.insert(v.begin()+j, n);
                nsol.push_back(v);
            }
            start = 0;
        }
    }
    swap(sol, nsol);
}

int main() {
    int n;
    cin >> n;
    gen(n);

    for (auto& v : sol)output(v);
}
