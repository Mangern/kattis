for _ in range(int(input())):
    nums=list(map(float,input().split()))
    x,y,w,h,r=nums[:5]
    nums = nums[6:]
    for i in range(0, len(nums), 2):
        xm, ym = nums[i:i+2]
        xm -= x
        ym -= y
        if xm < 0 or w < xm or ym < 0 or h < ym:
            print("outside")
            continue

        if xm <= r and ym <= r and (xm-r)**2+(ym-r)**2 > r**2:
            print("outside")
            continue
        if (w-xm) <= r and ym <= r and (w-xm-r)**2+(ym-r)**2 > r**2:
            print("outside")
            continue
        if xm <= r and h - ym <= r and (xm - r)**2+(h-ym-r)**2 > r**2:
            print("outside")
            continue
        if w-xm <= r and h - ym <= r and (w-xm-r)**2+(h-ym-r)**2 > r**2:
            print("outside")
            continue
        print("inside")
