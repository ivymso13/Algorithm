N = int(input())
M = int(input())

tot, ret, f = M, M, 0
for _ in range(N):
    a, b = map(int, input().split())

    tot += (a-b)
    if tot >= 0:
        ret = max(ret, tot)
    else:
        ret = 0
        f = 1

print(ret if f == 0 else 0)