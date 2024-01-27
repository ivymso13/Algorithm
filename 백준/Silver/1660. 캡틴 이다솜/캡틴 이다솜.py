N = int(input())

cnt = [1]
for i in range(2, N):
    cur = cnt[-1] + i*(i+1)//2
    if cur > N:
        break
    else:
        cnt.append(cur)

dp = [N]*(N+1)
dp[0] = 0
for i in range(N+1):
    for c in cnt:
        if i+c > N:
            break

        dp[i+c] = min(dp[i+c], dp[i]+1)

print(dp[N])