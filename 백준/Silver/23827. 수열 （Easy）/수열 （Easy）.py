N = int(input())
inp = list(map(int, input().split()))

pSum = [0]*N
for i in range(N-1, -1, -1):
    if i == N-1:
        pSum[i] = 0
    else:
        pSum[i] = pSum[i+1] + inp[i+1]

ret = 0
MOD = 1000000007
for i in range(N):
    ret = (ret + inp[i]*pSum[i])%MOD

print(ret)