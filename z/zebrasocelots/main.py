n=int(input())
ans=0
for i in range(n):
    s=input()
    if s == 'O':
        ans |= (1<<(n-1-i))
print(ans)

