import random
import subprocess

def gen_cycle(dist):
    nxt = [0 for i in range(dist)]
    nxt[-1] = random.randint(1, len(nxt) - 2)
    #cyc_len = 2
    #nxt[-1] = len(nxt) - cyc_len
    for i in range(dist - 1):
        nxt[i] = i + 1
    return nxt

def correct(nxt, n):
    p_nxt = [
        [0 for _ in range(len(nxt))]
        for _ in range(32)
    ]
    p_nxt[0] = nxt
    for k in range(1, 32):
        for i in range(len(nxt)):
            p_nxt[k][i] = p_nxt[k-1][p_nxt[k-1][i]]
    ptr = 0
    for m in range(32):
        if (n >> m) & 1:
            ptr = p_nxt[m][ptr]
    return ptr

MX = 30000



while True:
    D = 6001
    nxt = gen_cycle(D)
    N = random.randint(1, 10**9)
    N = 10**9
    ans = correct(nxt, N)

    print(f"{N=} {D=} {nxt[-1]=}")

    state = [
        [0, 0], # Spike pos, steps
        [0, 0]  # Gabby pos, steps
    ]
    p = subprocess.Popen("./a.out", bufsize=0, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE)

    def send(x):
        #print("Send: ", x)
        p.stdin.write(f"{x}\n".encode())

    def get():
        ret = p.stdout.readline()
        #print("Read: ", ret.decode())
        return ret

    send(N)

    reqs = 0
    reqs_before_ret = -1
    reqs_to_j = 0
    while True:
        res = get().decode()
        cmd, name = res.split()

        state_id = 0 if name == "SPIKE" else 1

        if cmd == "NEXT":
            reqs += 1
            if state[state_id][1] == N:
                eq = 1 if state[0][0] == state[1][0] else 0
                send(f"0 {eq}")
            else:
                state[state_id][0] = nxt[state[state_id][0]]
                state[state_id][1] += 1
                eq = 1 if state[0][0] == state[1][0] else 0
                if eq > 0 and reqs_before_ret != -1:
                    reqs_to_j = reqs - reqs_before_ret - 1
                send(f"1 {eq}")

        elif cmd == "RETURN":
            reqs_before_ret = reqs
            reqs += 1
            state[state_id][0] = 0
            state[state_id][1] = 0
            eq = 1 if state[0][0] == state[1][0] else 0
            send(f"0 {eq}")
        else:
            if state[state_id][0] == ans:
                print(f"Correct! {reqs_before_ret=} {reqs=}")
            else:
                print("Wrong answer")
                exit(1)
            break

        if reqs > MX:
            print(f"Too many requests! {reqs_before_ret=} {reqs_to_j=}")
            p.kill()
            exit(1)
