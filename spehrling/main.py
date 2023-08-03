a,b=input(),input()

ans = 0
while not b.startswith(a):
    ans += 1
    a = a[:-1]

ans += len(b)-len(a)
print(ans)
