N, M, K = map(int, input().split())

if K>=3:
    M  += (K-3)%N
    if M > N:
        print(M-N)
    else:
        print(M)
else:
    M -= (3-K)%N
    if M <= 0:
        print(N+M)
    else:
        print(M)