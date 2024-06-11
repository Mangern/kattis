#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll

int W, H;
struct win {
    int x, y, w, h;
};

bool inside(const win& w, int x, int y, bool nice = false) {
    return x >= w.x && x < w.x+w.w && y >= w.y && y < w.y+w.h;
}

bool overlap(const win& a, const win& b) {
    return !(
        b.x+b.w <= a.x ||
        a.x+a.w <= b.x ||
        b.y+b.h <= a.y ||
        a.y+a.h <= b.y
    );
}

int getwin(const vector<win>& windows, int x, int y) {
    int idx = -1;
    for (int i = 0; i < windows.size(); ++i) {
        if (inside(windows[i], x, y, true)) {
            idx = i;
            break;
        }
    }
    return idx;
}

int movewin(vector<win>& windows, int idx, int dx, int dy) {
    if (dx > 0) {
        vector<int> movez;
        movez.push_back(idx);
        int moved = 0;
        int right = windows[idx].x + windows[idx].w;
        while (moved < dx) {
            vector<int> closei;
            vector<int> closej;
            int closed = INT_MAX;

            for (int i = 0; i < windows.size(); ++i) {
                if (find(movez.begin(), movez.end(), i) != movez.end())continue;

                for (int j = 0; j < movez.size(); ++j) {
                    const auto& winj = windows[movez[j]];
                    if (windows[i].x < winj.x)continue;
                    if (windows[i].y >= winj.y + winj.h)continue;
                    if (windows[i].y + windows[i].h <= winj.y)continue;
                    int dist = windows[i].x - (winj.x + winj.w);
                    assert(dist >= 0);
                    if (dist < 0) {
                        cout << winj.x << " " << winj.y << " " << winj.w << " " << winj.h << endl;
                        cout << windows[i].x << " " << windows[i].y << " " << windows[i].w << " " << windows[i].h << endl;
                        exit(1);
                    }
                    if (dist < closed) {
                        closed = dist;
                        closej = {j};
                        closei = {i};
                    } else if (dist == closed) {
                        closej.push_back(j);
                        closei.push_back(i);
                    }
                }
            }

            if (closei.empty()) {
                int mov = min(W - right, dx - moved);
                for (int j : movez) {
                    windows[j].x += mov;
                }
                moved += mov;
                break;
            } else {
                int mov = min(closed, dx - moved);
                mov = min(W - right, mov);
                for (int j : movez) {
                    windows[j].x += mov;
                }
                moved += mov;

                if (mov == W - right)break;

                if (mov == closed) {
                    for (int i : closei) {
                        if (find(movez.begin(), movez.end(), i) != movez.end())continue;
                        movez.push_back(i);
                    }
                }
            }

            for (int j : movez) {
                right = max(right, windows[j].x + windows[j].w);
            }
        }
        return moved;
    } else if (dx < 0) {
        vector<int> movez;
        movez.push_back(idx);
        int moved = 0;
        int left = windows[idx].x;
        while (moved > dx) {
            vector<int> closei;
            vector<int> closej;
            int closed = INT_MAX;

            for (int i = 0; i < windows.size(); ++i) {
                if (find(movez.begin(), movez.end(), i) != movez.end())continue;

                for (int j = 0; j < movez.size(); ++j) {
                    const auto& winj = windows[movez[j]];
                    if (windows[i].x > winj.x)continue;
                    if (windows[i].y >= winj.y + winj.h)continue;
                    if (windows[i].y + windows[i].h <= winj.y)continue;
                    int dist = winj.x - (windows[i].x + windows[i].w);
                    assert(dist >= 0);
                    if (dist < closed) {
                        closed = dist;
                        closej = {j};
                        closei = {i};
                    } else if (dist == closed) {
                        closej.push_back(j);
                        closei.push_back(i);
                    }
                }
            }

            if (closei.empty()) {
                int mov = min(left, moved - dx);
                for (int j : movez) {
                    windows[j].x -= mov;
                }
                moved -= mov;
                break;
            } else {
                int mov = min(closed, moved - dx);
                mov = min(left, mov);
                for (int j : movez) {
                    windows[j].x -= mov;
                }
                moved -= mov;

                if (mov == left)break;

                if (mov == closed) {
                    for (int i : closei) {
                        if (find(movez.begin(), movez.end(), i) != movez.end())continue;
                        movez.push_back(i);
                    }
                }
            }
            for (int j : movez) {
                left = min(left, windows[j].x);
            }
        }
        return moved;
    } else if (dy > 0) {
        vector<int> movez;
        movez.push_back(idx);
        int moved = 0;
        int bot = windows[idx].y + windows[idx].h;
        while (moved < dy) {
            vector<int> closei;
            vector<int> closej;
            int closed = INT_MAX;

            for (int i = 0; i < windows.size(); ++i) {
                if (find(movez.begin(), movez.end(), i) != movez.end())continue;

                for (int j = 0; j < movez.size(); ++j) {
                    const auto& winj = windows[movez[j]];
                    if (windows[i].y < winj.y)continue;
                    if (windows[i].x >= winj.x + winj.w)continue;
                    if (windows[i].x + windows[i].w <= winj.x)continue;
                    int dist = windows[i].y - (winj.y + winj.h);
                    assert(dist >= 0);
                    if (dist < closed) {
                        closed = dist;
                        closej = {j};
                        closei = {i};
                    } else if (dist == closed) {
                        closej.push_back(j);
                        closei.push_back(i);
                    }
                }
            }

            if (closei.empty()) {
                int mov = min(H - bot, dy - moved);
                for (int j : movez) {
                    windows[j].y += mov;
                }
                moved += mov;
                break;
            } else {
                int mov = min(closed, dy - moved);
                mov = min(H - bot, mov);
                for (int j : movez) {
                    windows[j].y += mov;
                }
                moved += mov;

                if (mov == H - bot)break;

                if (mov == closed) {
                    for (int i : closei) {
                        if (find(movez.begin(), movez.end(), i) != movez.end())continue;
                        movez.push_back(i);
                    }
                }
            }
            for (int j : movez) {
                bot = max(bot, windows[j].y + windows[j].h);
            }
        }
        return moved;
    } else if (dy < 0) {
        vector<int> movez;
        movez.push_back(idx);
        int moved = 0;
        int top = windows[idx].y;
        while (moved > dy) {
            vector<int> closei;
            vector<int> closej;
            int closed = INT_MAX;

            for (int i = 0; i < windows.size(); ++i) {
                if (find(movez.begin(), movez.end(), i) != movez.end())continue;

                for (int j = 0; j < movez.size(); ++j) {
                    const auto& winj = windows[movez[j]];
                    if (windows[i].y > winj.y)continue;
                    if (windows[i].x >= winj.x + winj.w)continue;
                    if (windows[i].x + windows[i].w <= winj.x)continue;
                    int dist = winj.y - (windows[i].y + windows[i].h);
                    assert(dist >= 0);
                    if (dist < closed) {
                        closed = dist;
                        closej = {j};
                        closei = {i};
                    } else if (dist == closed) {
                        closej.push_back(j);
                        closei.push_back(i);
                    }
                }
            }

            if (closei.empty()) {
                int mov = min(top, moved - dy);
                for (int j : movez) {
                    windows[j].y -= mov;
                }
                moved -= mov;
                break;
            } else {
                int mov = min(closed, moved - dy);
                mov = min(top, mov);
                for (int j : movez) {
                    windows[j].y -= mov;
                }
                moved -= mov;

                if (mov == top)break;

                if (mov == closed) {
                    for (int i : closei) {
                        if (find(movez.begin(), movez.end(), i) != movez.end())continue;
                        movez.push_back(i);
                    }
                }
            }
            for (int j : movez) {
                top = min(top, windows[j].y);
            }
        }
        return moved;
    } else {
        assert(false);
    }
    return 0;
}

signed main() {
    string line;
    vector<win> windows;
    int cmdcnt = 0;
    while (getline(cin, line)) {
        stringstream ss(line);

        if (cmdcnt == 0) {
            ss >> W >> H;
            ++cmdcnt;
            continue;
        }

        string cmd;
        ss >> cmd;

        if (cmd == "OPEN") {
            win nxt;
            ss >> nxt.x >> nxt.y >> nxt.w >> nxt.h;

            bool fail = false;

            for (const auto& w : windows) {
                if (overlap(w, nxt)) {
                    fail = true;
                    break;
                }
            }

            if (nxt.x < 0 || nxt.y < 0 || nxt.x + nxt.w > W || nxt.y + nxt.h > H) {
                fail = true;
            }
            if (fail) {
                cout << "Command " << cmdcnt << ": " << cmd << " - window does not fit" << endl;
            } else {
                windows.push_back(nxt);
            }
        } else if (cmd == "CLOSE") {
            int x, y;
            ss >> x >> y;

            int idx = getwin(windows, x, y);

            if (idx == -1) {
                cout << "Command " << cmdcnt << ": " << cmd << " - no window at given position" << endl;
            } else {
                windows.erase(windows.begin() + idx);
            }
        } else if (cmd == "MOVE") {
            int x, y, dx, dy;
            ss >> x >> y >> dx >> dy;

            int idx = getwin(windows, x, y);
            if (idx == -1) {
                cout << "Command " << cmdcnt << ": " << cmd << " - no window at given position" << endl;
            } else {
                int res = movewin(windows, idx, dx, dy);
                if (abs(res) != max(abs(dx), abs(dy))) {
                    cout << "Command " << cmdcnt << ": " << cmd << " - moved " << abs(res) << " instead of " << max(abs(dx), abs(dy)) << endl;
                }
            }
        } else if (cmd == "RESIZE") {
            int x, y, w, h;
            ss >> x >> y >> w >> h;
            int idx = getwin(windows, x, y);

            if (idx == -1) {
                cout << "Command " << cmdcnt << ": " << cmd << " - no window at given position" << endl;
            } else {
                win nxt;
                nxt.x = windows[idx].x;
                nxt.y = windows[idx].y;
                nxt.w = w;
                nxt.h = h;

                bool fail = 0;
                for (int i = 0; i < windows.size(); ++i) if (i != idx) {
                    if (overlap(windows[i], nxt)) {
                        fail = 1;
                        break;
                    }
                }
                if (nxt.x < 0 || nxt.y < 0 || nxt.x + nxt.w > W || nxt.y + nxt.h > H) {
                    fail = true;
                }

                if (fail) {
                    cout << "Command " << cmdcnt << ": " << cmd << " - window does not fit" << endl;
                } else {
                    windows[idx].w = w;
                    windows[idx].h = h;
                }
            }
        }
        ++cmdcnt;
    }

    cout << windows.size() << " window(s):" << endl;
    for (const auto& w : windows) {
        cout << w.x << " " << w.y << " " << w.w << " " << w.h << endl;
    }
}
