import sys
for line in sys.stdin:
    nums=list(map(int,line.split(",")))
    tot=sum(nums)
    sm=0
    n=len(nums)
    mx=max(nums)
    mode=next(i for i in range(n) if nums[i] == mx)
    mean=sum(i*nums[i] for i in range(n)) / tot
    cum=0
    for i in range(n):
        cum += nums[i]
        if cum * 2 > tot:
            median = i
            break
    print(f"mean = {mean} median = {median} mode = {mode}")
