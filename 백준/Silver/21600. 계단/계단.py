N = int(input())
inp = list(map(int, input().split()))

ret = idx = 0
for val in inp:
    idx = min(idx+1, val)
    ret = max(ret, idx)

print(ret)