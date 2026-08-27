r,g,b=map(int,input().split())
if r>max(g,b):
    print("raudur")
elif g>max(r,b):
    print("graenn")
elif b>max(r,g):
    print("blar")
elif r==g and b<r:
    print("gulur")
elif r==b and g<r:
    print("fjolubleikur")
elif g==b and r<b:
    print("blagraenn")
elif r==g==b==0:
    print("svartur")
elif r==g==b==255:
    print("hvitur")
elif r==g==b:
    print("grar")
else:
    print("othekkt")
