N = int(input())

dp = [100010]*(N+1)
coin = [1, 2, 5, 7]

dp[0] = 0
for i in range(N+1):
    for c in coin:
        if i+c > N:
            break

        dp[i+c] = min(dp[i+c], dp[i]+1)

print(dp[N])