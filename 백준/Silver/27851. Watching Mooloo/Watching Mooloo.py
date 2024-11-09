N, K = map(int, input().split())
inp = list(map(int, input().split()))

ans, st = 0, inp[0]
for i in range(1, N):
    bef = (inp[i-1]-st + 1) + K
    if (inp[i]-st+1)+K > bef + (K+1):
        ans += bef
        st = inp[i]

ans += (inp[-1]-st + 1) + K

print(ans)