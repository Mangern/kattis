b,br,bs,a,As=map(int,input().split())

b = (br-b)*bs

ans = a
a = 0
while a <= b:
    ans += 1
    a += As

print(ans)
