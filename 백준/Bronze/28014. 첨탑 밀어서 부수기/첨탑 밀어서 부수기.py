N = int(input())
inp = list(map(int, input().split()))

ret = 1
for i in range(1, N):
    if inp[i-1] <= inp[i]:
        ret += 1

print(ret)