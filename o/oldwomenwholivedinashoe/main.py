def solve(w,h,a,b):
    ans=(w//a)*(h//b)
    if h % b >= a:
        ans += w//b
    return ans
a,b,c=map(int, [input(),input(),input()])
print(max(solve(a,b,c,2*c), solve(a,b,2*c,c)))
