#include <bits/stdc++.h>
using namespace std;
using ii = array<int,2>;

const int W = 31;

int n;

int cnt_ops = 0;
bool grid[W][W];
int xs, ys, xt, yt;

void up() {
    cout << "up" << endl;
    ++cnt_ops;
    ++ys;
}

void down() {
    cout << "down" << endl;
    --ys;
    ++cnt_ops;
}

void right() {
    cout << "right" << endl;
    ++xs;
    ++cnt_ops;
}
void left() {
    cout << "left" << endl;
    --xs;
    ++cnt_ops;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cin >> xs >> ys >> xt >> yt;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        grid[x][y] = 1;
    }

    int y_save = ys;

    // clear out left very far
    while (xs >= -2*W) {
        left();
    }

    // clear out right very far
    while (xs <= 2*W+1)right();

    while (xs > W)left();

    // move to target y-level
    while (ys < yt)up();
    while (ys > yt)down();

    // move these to trash
    while (xs >= 0)left();
    // move around pushed out things
    up();
    for (int i = 0; i < W+2; ++i)left();
    down();
    while (xs < W)right();

    int u = W - yt;
    while (u) {
        for (int i = 0; i < u; ++i)up();
        left();
        while (xs >= 0) {
            down();
            up();
            left();
        }

        for (int i = 0; i < u; ++i)down();

        while (xs < xt)right();
        while (xs >= 0)left();

        for (int i = 0; i < u; ++i)up();
        while (xs < W)right(); 
        for (int i = 0; i < u; ++i)down();
        while (xs > xt)left();
        while (xs < W)right();
        --u;
    }

    assert(ys == yt);

    u = yt+1;
    while (u) {
        for (int i = 0; i < u; ++i)down();
        left();
        while (xs >= 0) {
            up();
            down();
            left();
        }

        for (int i = 0; i < u; ++i)up();
        while (xs < xt)right();
        while (xs >= 0)left();

        for (int i = 0; i < u; ++i)down();
        while (xs < W)right();
        for (int i = 0; i < u; ++i)up();
        while (xs > xt)left();
        while (xs < W)right();
        --u;
    }

    while (ys < y_save)up();
    while (ys > y_save)down();
    up();
    while (xs <= 3*W+4)right();
    down();

    if (ys > yt) {
        int d = ys - yt;
        up();
        while (xs >= -3*W-3) {
            left();
            for (int i = 0; i < d; ++i)down();
            for (int i = 0; i < d; ++i)up();
        }

        while (ys > yt)down();
        while (xs < xt)right();
        up();
        while (xs <= 3*W+4)right();
        down();
        while (xs > xt)left();
    } else if (ys < yt) {
        int d = yt - ys;
        down();
        while (xs >= -3*W-3) {
            left();
            for (int i = 0; i < d; ++i)up();
            for (int i = 0; i < d; ++i)down();
        }
        while (ys < yt)up();
        while (xs < xt)right();
        up();
        while (xs <= 3*W+4)right();
        down();
        while (xs > xt)left();
    } else {
        while (xs > xt)left();
        down();
        while (xs >= -3*W-3)left();
        up();
        while (xs < xt)right();
    }
}
