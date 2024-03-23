M, N = map(int, input().split())
inp = list(map(int, input().split()))

l, r = 1, max(inp)
ret = 0
while l<=r:
    mid = (l+r)//2

    tmp = 0
    for val in inp:
        tmp += val//mid

    if tmp < M:
        r = mid-1
    else:
        ret = max(ret, mid)
        l = mid+1

print(ret)