import sys
sys.setrecursionlimit(100000)

N = int(input())

inp = []
for i in range(N):
    t = list(map(int, input().split()))
    inp.append(t)


def sv(x, y):
    global dp

    if dp[x][y] > -1:
        return dp[x][y]
    else:
        if inp[x][y] == -1:
            ret = 1
        elif inp[x][y] == 0:
            ret = 0
        else:
            ret = 0
            if x+inp[x][y] < N:
                ret |= sv(x+inp[x][y], y)
            if y+inp[x][y] < N:
                ret |= sv(x, y+inp[x][y])

        dp[x][y] = ret
        return dp[x][y]


dp = [[-1]*(N+1) for _ in range(N+1)]
print("HaruHaru" if sv(0, 0) else "Hing")