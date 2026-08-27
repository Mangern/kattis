a,b=map(int,input().split())
c,d=map(int,input().split())
q = int(input())

dst = abs(a-c)+abs(b-d)

print("N" if dst > q or (dst%2!=q%2) else "Y")
