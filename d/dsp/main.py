n=int(input())
insts=[input().split() for _ in range(n)]
ip = 0
regs=[0]*256

while True:
    inst=insts[ip][0]
    if inst == "CONST":
        x,y=map(int,insts[ip][1:])
        regs[y]=x
        ip += 1
    elif inst == "ADD":
        x,y=map(int,insts[ip][1:])
        regs[y] += regs[x]
        ip += 1
    elif inst == "SUB":
        x,y=map(int,insts[ip][1:])
        regs[y] -= regs[x]
        ip += 1
    elif inst == "JNZ":
        x,y=map(int,insts[ip][1:])
        if regs[x] != 0:
            ip = y
        else:
            ip += 1
    elif inst == "INPUT":
        x = int(insts[ip][1])
        regs[x] = int(input())
        ip += 1
    elif inst == "OUTPUT":
        x = int(insts[ip][1])
        print(regs[x])
        ip += 1
    elif inst == "HALT":
        break
    else:
        assert False
