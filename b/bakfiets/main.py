def solve(w,h,a,b):
    ans = float('inf')
    if a < w and b < h:
        ans = min(ans, (w-a)*b + (h-b)*a + (w-a)*(h-b))
    elif a < w and b >= h:
        ans = min(ans, (w-a) * h)
    elif a >= w and b < h:
        ans = min(ans, w * (h - b))
    else:
        ans = 0
    return ans

w,h,a,b=map(int,input().split())

print(min(solve(w,h,a,b), solve(w,h,b,a)))
