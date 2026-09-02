
def solve(s, i, is_touching, zero_allowed, dp):
    if i >= len(s):
        return (1, 0)
    key = (i, is_touching, zero_allowed)
    if key in dp:
        return dp[key]
    ret_numbers = 0
    ret_zeros = 0
    up = int(s[i]) if is_touching else 9
    for d in range(0, up+1):
        num_numbers, num_zeros = solve(s, i + 1, is_touching and d == up, zero_allowed or d != 0, dp)
        ret_numbers += num_numbers
        ret_zeros += num_zeros
        if d == 0 and zero_allowed:
            ret_zeros += num_numbers
    dp[key] = (ret_numbers, ret_zeros)
    return dp[key]

while True:
    a,b=map(int,input().split())
    if a == -1:
        break

    _, bz = solve(str(b), 0, True, False, {})
    bz += 1

    if a != 0:
        _, az = solve(str(a-1), 0, True, False, {})
        az += 1
    else:
        az = 0

    print(bz-az)
