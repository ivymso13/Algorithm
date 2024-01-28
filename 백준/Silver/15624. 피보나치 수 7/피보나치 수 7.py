N = int(input())

if N <= 1:
    print(N)
else:
    a = 0
    b = 1
    MOD = 1000000007
    for i in range(2, N+1):
        t = (b+a)%MOD
        a = b%MOD
        b = t

    print(b)