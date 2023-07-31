MX = 10**9
n = int(input())

ans = 0
mul = 1
for i in range(n):
    mul *= (n-i)
    ans += mul
    if ans > MX:
        print("JUST RUN!!")
        break
else:
    print(ans)
