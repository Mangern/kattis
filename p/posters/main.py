p,h,t=map(int,input().split())

if p < h:
    # Always ready
    print(max(0, (t-p)//h))
    exit()
else:
    num_print = t // p
    if num_print * p + h > t:
        num_print -= 1
    print(max(0, num_print))
