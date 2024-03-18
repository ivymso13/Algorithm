NMAX = 31
dp = [[0]*NMAX for i in range(NMAX)]

dp[1][1] = 1
for i in range(2, NMAX):
    for j in range(1, i+1):
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]


R, C, W = map(int, input().split())

tot = 0
for i in range(W):
    for j in range(i+1):
        tot += dp[R+i][C+j]

print(tot)