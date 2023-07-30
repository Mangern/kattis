n = int(input())

if n == 1:
    print("YES")
    exit(0)

curr_tot = 2
curr_cnt = 0
for i in range(1,n):
    if curr_cnt == 2*curr_tot:
        curr_tot += 1
        curr_cnt = 0
    curr_cnt += 1

print("NO" if curr_cnt <= curr_tot else "YES")
