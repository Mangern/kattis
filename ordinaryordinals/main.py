n,m=map(int,input().split())
if(n==0):
    print(2%m)
else:
    print((pow(2,n+1,m)+pow(2,n-1,m)-1)%m)
