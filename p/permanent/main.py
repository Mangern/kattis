def main():
    n=int(input())
    A=[list(map(int,input().split())) for _ in range(n)]
    #n=10
    #A=[[1]*10 for _ in range(10)]

    def perm(row, colset):
        if not colset:
            return 1

        ret=0
        for c in range(n):
            if ((colset >> c) & 1) == 0:
                continue
            cur=A[row][c]
            ret+=cur*perm(row+1,colset ^ (1<<c))
        return ret



    colset=(1<<n)-1
    print(perm(0, colset))
main()
