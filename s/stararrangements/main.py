S = int(input())
print(f"{S}:")
for i in range(2,S):
    if S%(2*i-1)== 0 or (S-i)%(2*i-1)==0:
        print(f"{i},{i-1}")
    if S%i==0:
        print(f"{i},{i}")
