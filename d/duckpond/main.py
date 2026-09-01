n,m=map(int,input().split())
nums=list(range(1,n+1))
i = 0
ans=[0]*n
for it in range(n):
    i += m-1
    i %= len(nums)
    ans[nums[i]-1] = it+1
    nums.remove(nums[i])
print(" ".join(map(str,ans)))
