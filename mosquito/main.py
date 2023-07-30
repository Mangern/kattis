from sys import stdin

for line in stdin:
    m,p,l,e,r,s,n=map(int,line.split())

    for i in range(n):
        m,p,l=p//s,l//r,m*e
    print(m)
