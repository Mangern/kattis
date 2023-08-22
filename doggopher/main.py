gx, gy, dx, dy = map(float, input().split())

pts = []
while True:
    try:
        x,y = map(float,input().split())
        pts.append((x,y))
    except:
        break

for x, y in pts:
    dg = (gx - x)**2 + (gy-y)**2
    dd = (dx - x)**2 + (dy-y)**2

    if dd >= 4 * dg:
        print(f"The gopher can escape through the hole at ({x:.3f},{y:.3f}).")
        break
else:
    print("The gopher cannot escape.")
