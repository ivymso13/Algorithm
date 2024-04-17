N, K = map(int, input().split())

inp = []
for _ in range(N):
    t = int(input())
    inp.append(t)

l = 1
r = max(inp)
while l <= r:
    mid = (l + r) // 2

    tmp = 0
    for i in range(N):
        tmp += inp[i]//mid

    if tmp >= K:
        l = mid + 1
    else:
        r = mid - 1

print(r)