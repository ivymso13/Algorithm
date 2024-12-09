N = int(input())

inp = []
for i in range(N):
    t = list(map(int, input()))
    inp.append(t)

cnt = 0
while True:
    x, y = -1, -1
    for i in range(N):
        for j in range(N):
            if inp[i][j] == 1:
                x, y = i, j

    if [x, y] == [-1, -1]:
        break
    else:
        cnt += 1
        for i in range(x+1):
            for j in range(y+1):
                inp[i][j] = 1-inp[i][j]

print(cnt)