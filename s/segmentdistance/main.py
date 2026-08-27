from math import acos, degrees, inf

def dist(a,b):
    return ((a[0] - b[0])**2+(a[1]-b[1])**2)**0.5

def norm(v):
    return dist(v[0],v[1])

def dot(u,v):
    u_x = u[1][0] - u[0][0]
    u_y = u[1][1] - u[0][1]

    v_x = v[1][0] - v[0][0]
    v_y = v[1][1] - v[0][1]

    return u_x * v_x + u_y * v_y

def angle(u,v):
    if norm(u) == 0 or norm(v) == 0:
        return -1
    inp = dot(u,v) / (norm(u) * norm(v))
    if abs(inp) > 1:
        return 0.00
    val = round(degrees(acos((dot(u,v) / (norm(u) * norm(v))))), 6)
    if val < 0:
        val += 180
    if val > 180:
        val -= 180

    return val

def vec(p,q):
    return (p,q)

def is_point(v):
    return norm(v) == 0 


def proj(p, u):
    if is_point(u):
        return inf
    a1 = angle(vec(p,u[0]), u)
    a2 = angle(vec(p,u[1]), u)
    if a1 < 0 or a2 < 0:
        return inf 

    if a1 <= 90 <= a2 or a2 <= 90 <= a1:
        x1 = u[0][0] - p[0]
        x2 = u[1][0] - p[0]
        y1 = u[0][1] - p[1]
        y2 = u[1][1] - p[1]

        cross = abs(x1 * y2 - x2 * y1)
        return cross / norm(u)

    else:
        return inf 

def ccw(A,B,C):
    val = (C[1]-A[1]) * (B[0]-A[0]) - (B[1]-A[1]) * (C[0]-A[0])

    if val == 0:
        return 0

    return 1 if val > 0 else 2

def on_seg(p, u):
    return p[0] <= max(u[0][0], u[1][0]) and p[0] >= min(u[0][0], u[1][0]) and p[1] <= max(u[0][1], u[1][1]) and p[1] >= min(u[0][1], u[1][1])

def intersect(A,B,C,D):
    o1 = ccw(A,B,C)
    o2 = ccw(A,B,D)
    o3 = ccw(C,D,A)
    o4 = ccw(C,D,B)
    if o1 != o2 and o3 != o4:
        return True

    if o1 == 0 and on_seg(C, (A,B)):
        return True

    if o2 == 0 and on_seg(D, (A,B)):
        return True

    if o3 == 0 and on_seg(A, (C,D)):
        return True

    if o4 == 0 and on_seg(B, (C,D)):
        return True

    return False

for _ in range(int(input())):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(int,input().split())
    p1 = (x1,y1)
    p2 = (x2,y2)
    q1 = (x3,y3)
    q2 = (x4,y4)

    ans = min(dist(p1,q1),dist(p1,q2),dist(p2,q1),dist(p2,q2))

    # proj p1 to q, 90 deg

    # intersect
    if intersect(p1,p2,q1,q2):
        ans = 0.0
    else:
        ans = min(ans, proj(p1,(q1,q2)), proj(p2,(q1,q2)), proj(q1, (p1,p2)), proj(q2, (p1,p2)))

    ans = round(ans*100)/100

    print(f"{ans:.2f}")
