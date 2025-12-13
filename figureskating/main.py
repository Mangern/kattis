pred={}
n=int(input())
for i in range(n):
    s=input()
    pred[s] = i
ans="suspicious"
ansd=0
for i in range(n):
    s=input()
    if pred[s] - i > ansd:
        ansd = pred[s] - i
        ans = s
print(ans)


