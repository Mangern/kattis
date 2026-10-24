for _ in range(int(input())):
    lon,lat=map(float,input().split())
    if -180.0 <= lon <= 180.0 and -90.0 <= lat <= 90.0:
        print("VALID")
    else:
        print("INVALID")
