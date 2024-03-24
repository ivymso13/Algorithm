N, M, K = map(int, input().split())

inp = []
for _ in range(N):
    t = list(map(int, input().split()))
    inp.append(t)

def sv(x, y, cnt, tot):
    if cnt == K:
        global ret
        ret = max(ret, tot)
    elif x == N:
        return
    elif y == M:
        sv(x+1, 0, cnt, tot)
    else:
        global check

        f = 1
        for dx, dy in [[-1, 0],[0, -1],[1, 0],[0, 1]]:
            if 0<=x+dx<N and 0<=y+dy<M and check[x+dx][y+dy] != 0:
                f = 0
                break

        if f == 1:
            check[x][y] = 1
            sv(x, y+1, cnt+1, tot+inp[x][y])

        check[x][y] = 0
        sv(x, y+1, cnt, tot)


ret = -1000000
check = [[0]*M for _ in range(N)]
sv(0, 0, 0, 0)

print(ret)