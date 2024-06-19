N, M = map(int, input().split())
inp = []

for i in range(N):
    t = list(input())
    inp.append(t)

r = 0
for i in range(N):
    f = 0
    for j in range(M):
        if inp[i][j] == 'X':
            f = 1
    r += 1 if f == 0 else 0

c = 0
for j in range(M):
    f = 0
    for i in range(N):
        if inp[i][j] == 'X':
            f = 1

    c += 1 if f == 0 else 0

print(max(r, c))