N = int(input())

ret = 1
MOD = 10**9+7

for _ in range(N-1):
    ret = (ret*2)%MOD

print(((ret-1)*8 + 3)%MOD)