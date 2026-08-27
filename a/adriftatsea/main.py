ref={
"N": 0,
"NE": 45,
"E": 90,
"SE": 135,
"S": 180,
"SW": 225,
"W": 270,
"NW": 315
}
start=input()
end=input()

dif = (ref[end] - ref[start]) % 360
if dif>180:
    dif -= 360

if dif==0:
    print("Keep going straight")
elif dif ==180:
    print("U-turn")
elif dif>0:
    print(f"Turn {dif} degrees starboard")
else:
    print(f"Turn {-dif} degrees port")

