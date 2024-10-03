N, T = map(int, input().split())

tot, vmax = 0, 0
dp = [0]*(T+1)

for i in range(N):
    d, m = map(int, input().split())
    tot += m

    for j in range(T, d-1, -1):
        dp[j] = max(dp[j], dp[j-d] + m)

        vmax = max(vmax, dp[j])

print(tot-vmax)