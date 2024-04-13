N, K = map(int, input().split())
inp = list(map(int, input().split()))

MAX = sum(inp)
l, r = 0, MAX
ret = 0
while l<=r:
    mid = (l+r)//2

    tmp, tcnt, tmin = 0, 0, MAX
    for val in inp:
        tmp += val
        if tmp >= mid:
            tmin = min(tmp, tmin)
            tmp = 0
            tcnt += 1

    if tcnt < K:
        r = mid-1
    elif tcnt > K:
        l = mid+1
    else:
        ret = max(ret, tmin)
        l = mid+1

print(ret)