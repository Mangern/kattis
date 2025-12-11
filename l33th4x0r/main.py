font=input()
r=int(input())
g=int(input())
b=int(input())
rf=int(input())
gf=int(input())
bf=int(input())
a= 1 if font == "monospace" else 0
b= 1 if  r+b+g <= 25 else 0 
c= 1 if  rf+bf+255-gf <= 35 else 0
if a+b+c>=2:
    print("L33T H4X0R")
else:
    print("n00b")
