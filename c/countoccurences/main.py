s=input()
c=input()

idx=0
while True:
    f=s.find(c,idx)
    if f == -1:
        break
    print(f)
    idx = f+1
