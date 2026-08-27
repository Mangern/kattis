k=int(input()) - 1

l=1
while True:
    if 2**l > k:
        break
    k -= 2**l
    l += 1

ans=['4']*l
for i in range(l):
    if k % 2 == 1:
        ans[-1-i] = '7'
    k //= 2
print("".join(ans))
