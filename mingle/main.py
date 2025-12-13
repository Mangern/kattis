M=998244353
n,k=map(int,input().split())
num=n*pow(2*k, 2*k, M)%M
den=pow(2*k+1,2*k,M)
print(num*pow(den,M-2,M)%M)
