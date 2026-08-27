n=int(input())
p=int(input())
s=set(range(p,p+n))
for x in map(int,input().split()):
    s.remove(x)
print(s.pop())
