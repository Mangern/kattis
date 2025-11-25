n=int(input())
ta,da=map(int,input().split())
tb,db=map(int,input().split())
sa=n*ta+da*n*(n-1)//2
sb=n*tb+db*n*(n-1)//2
if sa == sb:
    print("=")
elif sa>sb:
    print("Bob")
else:
    print("Alice")
