d=int(input())
a,o=map(int,input().split())
da,do=map(int,input().split())

a = max(0, a - da * d)
o = max(0, o - do * d)

print(a/(a+o) * 100.0)
