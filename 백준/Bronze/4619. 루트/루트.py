while True:
    B, N = map(int, input().split())
    if B == N == 0:
        break

    A, ret = 1, 1
    while A**N <= B:
        if abs(B - A**N) < abs(B - ret**N):
            ret = A
        A += 1

    if abs(B - A**N) < abs(B - ret**N):
        ret = A

    print(ret)