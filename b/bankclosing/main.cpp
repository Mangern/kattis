#include <bits/stdc++.h>
using namespace std;
using ii = array<int,2>;

int main() {
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        pq.push({t, i});
    }

    while (pq.size()) {
        auto [t, i] = pq.top();
        pq.pop();

        cout << i+1 << endl;

        string resp;
        cin >> resp;

        if (resp == "DONE") continue;

        int nt = stoi(resp);
        pq.push({nt, i});
    }

    cout << "DONE" << endl;
}
