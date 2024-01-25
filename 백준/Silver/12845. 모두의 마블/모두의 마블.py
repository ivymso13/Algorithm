N = int(input())
inp = list(map(int, input().split()))

idx = 0
for i in range(1, N):
    if inp[idx] < inp[i]:
        idx = i

ret = 0
for i in range(N):
    if i != idx:
        ret += inp[i] + inp[idx]

print(ret)