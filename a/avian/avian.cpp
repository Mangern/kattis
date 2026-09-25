#include <array>
#include <vector>
#include <cassert>

#include "avian.h"

using namespace std;

char sxor(char c1, char c2) {
    return ((c1-'0')^(c2-'0'))+'0';
}

char sxor(char c1, char c2, char c3) {
    return sxor(c1,sxor(c2,c3));
}
char sxor(char c1, char c2, char c3, char c4) {
    return sxor(sxor(c1,c2),sxor(c3,c4));
}

vector<string> encode(int C, int K, int N, string X) {
    if (C == 2) {
        assert(K == 4);

        vector<string> result(K);
        string x, y;
        for (int i = 0; i < C*N; ++i) {
            if (i&1)y.push_back(X[i]);
            else x.push_back(X[i]);
        }
        for (int i = 0; i < N; ++i) {
            result[0].push_back(x[i]);
            result[1].push_back(sxor(x[i], y[i]));
            result[2].push_back(sxor(x[i], y[i], x[(i+1)%N]));
            if (i < N - 1) {
                result[3].push_back(sxor(x[i], y[i], y[(i+1)%N]));
            } else {
                result[3].push_back(y[0]);
            }
        }
        return result;
    } else if (K == 4) {
        vector<string> result(K);
        string x, y, z;

        for (int i = 0; i < C*N; ++i) {
            if (i % 3 == 0) {
                x.push_back(X[i]);
            } else if (i % 3 == 1) {
                y.push_back(X[i]);
            } else {
                z.push_back(X[i]);
            }
        }
        for (int i = 0; i < N; ++i) {
            result[0].push_back(x[i]);
            result[1].push_back(y[i]);
            result[2].push_back(z[i]);
            result[3].push_back(sxor(x[i], y[i], z[i]));
        }
        return result;
    } else if (K == 5) {
        vector<string> result(K);
        string x, y, z;
        for (int i = 0; i < C*N; ++i) {
            if (i % 3 == 0) {
                x.push_back(X[i]);
            } else if (i % 3 == 1) {
                y.push_back(X[i]);
            } else {
                z.push_back(X[i]);
            }
        }

        for (int i = 0; i < N; ++i) {
            result[0].push_back(x[i]);
            result[1].push_back(y[i]);
            result[2].push_back(sxor(x[i], z[i]));
            if (i < N - 1) {
                result[3].push_back(sxor(x[i], y[i], z[i], z[i+1]));
                result[4].push_back(sxor(x[i], y[i], z[i+1]));
            } else {
                result[3].push_back(sxor(x[N-1], y[N-1], z[0]));
                result[4].push_back(sxor(x[N-1], y[N-1], z[N-1], z[0]));
            }
        }
        return result;
    }
	return vector<string>(K, string(N, '0'));
}

string decode(int C, int K, int N, vector<string> Y, vector<int> I) {
    if (C == 2) {
        array<string, 4> has;
        for (int i = 0; i < C; ++i) {
            has[I[i]] = Y[i];
        }
        string x(N,'0'), y(N,'0');
        string xory(N,'0');

        if (has[0].size()) {
            for (int i = 0; i < N; ++i) {
                x[i] = has[0][i];
            }

            if (has[1].size()) {
                for (int i = 0; i < N; ++i) {
                    y[i] = sxor(x[i], has[1][i]);
                }
            } else if (has[2].size()) {
                for (int i = 0; i < N; ++i) {
                    xory[i] = sxor(x[(i+1)%N], has[2][i]);
                }
                for (int i = 0; i < N; ++i) {
                    y[i] = sxor(x[i], xory[i]);
                }
            } else if (has[3].size()) {
                y[0] = has[3].back();
                xory[0] = sxor(x[0], y[0]);
                for (int i = 0; i < N - 1; ++i) {
                    y[i+1] = sxor(xory[i], has[3][i]);
                    xory[i+1] = sxor(x[i+1], y[i+1]);
                }
            }

        } else if (has[1].size()) {
            for (int i = 0; i < N; ++i) {
                xory[i] = has[1][i];
            }

            if (has[2].size()) {
                for (int i = 0; i < N; ++i) {
                    x[(i+1)%N] = sxor(xory[i], has[2][i]);
                }
                for (int i = 0; i < N; ++i) {
                    y[i] = sxor(x[i], xory[i]);
                }
            } else if (has[3].size()) {
                y[0] = has[3].back();
                for (int i = 0; i < N - 1; ++i) {
                    y[i+1] = sxor(xory[i], has[3][i]);
                }
                for (int i = 0; i < N; ++i) {
                    x[i] = sxor(xory[i], y[i]);
                }
            }
        } else if (has[2].size()) {
            for (int i = 0; i < N - 1; ++i) {
                xory[i+1] = sxor(has[2][i], has[3][i]);
            }
            y[0] = has[3].back();
            xory[0] = sxor(xory[N-1], has[2].back(), y[0]);

            for (int i = 0; i < N; ++i) {
                x[(i+1)%N] = sxor(xory[i], has[2][i]);
            }
            for (int i = 0; i < N; ++i) {
                y[i] = sxor(x[i], xory[i]);
            }
        }

        string result;
        for (int i = 0; i < N; ++i) {
            result.push_back(x[i]);
            result.push_back(y[i]);
        }
        return result;
    } else if (K == 4) {
        array<string, 4> has;
        for (int i = 0; i < C; ++i) {
            has[I[i]] = Y[i];
        }
        vector<string> chunks(C, string(N, '0'));
        string xors(N,'0');

        int missing = 0 ^ 1 ^ 2;

        for (int idx = 0; idx < 3; ++idx) {
            if (has[idx].size()) {
                missing ^= idx;
                for (int i = 0; i < N; ++i) {
                    chunks[idx][i] = has[idx][i];
                    xors[i] = sxor(xors[i], chunks[idx][i]);
                }
            }
        }

        if (has[3].size()) {
            for (int i = 0; i < N; ++i) {
                chunks[missing][i] = sxor(has[3][i], xors[i]);
            }
        }

        string result;
        for (int i = 0; i < N; ++i) {
            result.push_back(chunks[0][i]);
            result.push_back(chunks[1][i]);
            result.push_back(chunks[2][i]);
        }
        return result;
    } else if (K == 5) {
        array<string, 5> has;
        for (int i = 0; i < C; ++i) {
            has[I[i]] = Y[i];
        }
        string x(N, '0'), y(N, '0'), z(N, '0');
        bool hx = 0, hy = 0, hz = 0;

        if (has[0].size()) {
            hx = 1;
            for (int i = 0; i < N; ++i) {
                x[i] = has[0][i];
            }
        }
        if (has[1].size()) {
            hy = 1;
            for (int i = 0; i < N; ++i) {
                y[i] = has[1][i];
            }
        }

        if (has[3].size() || has[4].size()) {
            bool hxz = has[2].size();
            string xz(N, '0');
            if (hxz) {
                for (int i = 0; i < N; ++i) {
                    xz[i] = has[2][i];
                }
            }

            if (hx && hxz) {
                hz = 1;
                for (int i = 0; i < N; ++i) {
                    z[i] = sxor(x[i], xz[i]);
                }
            }

            if (has[3].size() && has[4].size()) {
                hz = 1;
                for (int i = 0; i < N; ++i) {
                    z[i] = sxor(has[3][i], has[4][i]);
                }

                if (hxz) {
                    hx = 1;
                    for (int i = 0; i < N; ++i) {
                        x[i] = sxor(xz[i], z[i]);
                    }
                } else if (hy) {
                    hx = 1;
                    for (int i = 0; i < N; ++i) {
                        if (i < N - 1) {
                            x[i] = sxor(has[3][i], y[i], z[i], z[i+1]);
                        } else {
                            x[i] = sxor(has[3][i], y[i], z[0]);
                        }
                    }
                }
            } else if (has[3].size()) {
                if (hx && hy) {
                    hz = 1;
                    z[0] = sxor(has[3][N-1], x[N-1], y[N-1]);
                    for (int i = 0; i < N - 1; ++i) {
                        z[i+1] = sxor(x[i], y[i], z[i], has[3][i]);
                    }
                } else if (hy && hxz) {
                    for (int i = 0; i < N - 1; ++i) {
                        char xyz = sxor(y[i], xz[i]);
                        z[i+1] = sxor(has[3][i], xyz);
                    }
                    x[N-1] = sxor(z[N-1], xz[N-1]);
                    z[0] = sxor(has[3][N-1], y[N-1], x[N-1]);
                    hz = 1;

                    hx = 1;
                    for (int i = 0; i < N; ++i) {
                        x[i] = sxor(xz[i], z[i]);
                    }
                }
            } else {
                assert(has[4].size());
                if (hx && hy) {
                    hz = 1;
                    for (int i = 0; i < N - 1; ++i) {
                        z[i+1] = sxor(has[4][i], x[i], y[i]);
                    }
                    z[0] = sxor(has[4][N-1], x[N-1], y[N-1], z[N-1]);
                } else if (hy && hxz) {
                    z[0] = sxor(has[4][N-1], xz[N-1], y[N-1]);

                    hz = 1;
                    hx = 1;
                    for (int i = 0; i < N - 1; ++i) {
                        x[i] = sxor(xz[i], z[i]);
                        z[i+1] = sxor(has[4][i], x[i], y[i]);
                    }
                    x[N-1] = sxor(xz[N-1], z[N-1]);
                }
            }

            assert(hx && hz);

            if (!hy) {
                if (has[4].size()) {
                    hy = 1;
                    for (int i = 0; i < N; ++i) {
                        if (i < N - 1) {
                            y[i] = sxor(has[4][i], x[i], z[i+1]);
                        } else {
                            y[i] = sxor(has[4][i], x[i], z[i], z[0]);
                        }
                    }
                } else {
                    assert(has[3].size());

                    hy = 1;
                    for (int i = 0; i < N; ++i) {
                        if (i < N - 1) {
                            y[i] = sxor(has[3][i], x[i], z[i], z[i+1]);
                        } else {
                            y[i] = sxor(has[3][i], x[i], z[0]);
                        }
                    }
                }
            }
        } else {
            assert(hx && hy && has[2].size());

            hz = 1;
            for (int i = 0; i < N; ++i) {
                z[i] = sxor(x[i], has[2][i]);
            }
        }

        assert(hx && hy && hz);

        string result;
        for (int i = 0; i < N; ++i) {
            result.push_back(x[i]);
            result.push_back(y[i]);
            result.push_back(z[i]);
        }
        return result;
    }
	return string(C*N, '0');
}
