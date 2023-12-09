M, N = map(int, input().split())
inp = [list(input()) for _ in range(N)]

check = [[0]*M for _ in range(N)]

def dfs(x, y):
    global check, cnt
    for d in [[-1, 0], [0, -1], [1, 0], [0, 1]]:
        xx = x + d[0]
        yy = y + d[1]

        if 0<=xx<N and 0<=yy<M and check[xx][yy] == 0 and inp[x][y] == inp[xx][yy]:
            check[xx][yy] = 1
            cnt += 1
            dfs(xx, yy)


B = W = 0
for i in range(N):
    for j in range(M):
        if check[i][j] > 0:
            continue

        check[i][j] = 1
        cnt = 1
        dfs(i, j)

        if inp[i][j] == 'B':
            B += cnt**2
        else:
            W += cnt**2

print(W, B)