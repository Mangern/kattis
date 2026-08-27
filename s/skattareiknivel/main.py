from math import floor
l=float(input())/100
s=float(input())/100
exe = 0.0
ans = 0
for _ in range(12):
    x=float(input())
    x -= floor(l*x) + floor(s*x)

    in1 = min(409986.0, x)
    in2 = min(1151012.0, x) - in1
    in3 = max(0.0, x - in1 - in2)
    wit = floor(in1 * 0.3145 + in2 * 0.3795 + in3 * 0.4625)
    exe += 59665
    rem = min(exe,wit)
    wit -= rem
    exe -= rem
    x -= wit
    ans += int(x)
print(ans)
