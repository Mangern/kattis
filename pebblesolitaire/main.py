def popcount(x):
    n = 0
    while x:
        n += (x & 1)
        x >>= 1
    return n


def min_left(x):
    ans = popcount(x)
    for i in range(10):
        if (x & (1<<i)) and (x & (1<<(i+1))) and not (x & (1<<(i+2))):
            ans = min(ans, min_left(x ^ (1<<i) ^ (1<<(i+1)) ^ (1<<(i+2))))
        elif not (x & (1<<i)) and (x & (1<<(i+1))) and (x & (1<<(i+2))):
            ans = min(ans, min_left(x ^ (1<<i) ^ (1<<(i+1)) ^ (1<<(i+2))))
    return ans

for _ in range(int(input())):
    s = input()
    x = 0
    for i in range(len(s)):
        if s[i] == 'o':
            x |= (1<<i)
    print(min_left(x))
