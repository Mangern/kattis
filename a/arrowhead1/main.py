l1, b1 = map(int,input().split())
l2,b2,x2=map(int,input().split())
print(0.5*(l1*b1+l2*b2-b2*(l1-x2)**2/l2))
