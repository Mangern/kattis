input()
a=map(int,input().split())
x=int(input())
print(min(a,key=lambda y:x%y))
