ksx,ksy,osx,osy,kex,key,oex,oey=map(int,input().split())

k_pos = ((ksx,kex-ksx),(ksy,key-ksy))
o_pos = ((osx,oex-osx),(osy,oey-osy))

x_df = (k_pos[0][0]-o_pos[0][0],k_pos[0][1]-o_pos[0][1])
y_df = (k_pos[1][0]-o_pos[1][0],k_pos[1][1]-o_pos[1][1])

A = x_df[1]**2 + y_df[1]**2
B = 2*x_df[0]*x_df[1]+2*y_df[0]*y_df[1]
C = x_df[0]**2 + y_df[0]**2

tests = [0.0,1.0]
if A != 0:
    t = -B/(2*A)
    if 0.0 <= t <= 1.0:
        tests.append(t)

ans = 0.0
for t in tests:
    ans = max(ans,A*t*t+B*t+C)
ans = ans**0.5
print(ans)

