n = int(input())
a = list(map(int,input().split()))

a.sort()

i = n//2;

ans = []
for k in range(n):
    ans.append(a[i])
    if k & 1:
        i += k+1
    else:
        i -= k+1

print(" ".join(map(str,ans)))
