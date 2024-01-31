N, M, K = map(int, input().split())

ret = N*M+1
reti = -1
for idx in range(K):
    f, d = map(int, input().split())
    tmp = (f-1) + (M+1)-d

    if tmp < ret:
        ret = tmp
        reti = idx+1

print(reti)