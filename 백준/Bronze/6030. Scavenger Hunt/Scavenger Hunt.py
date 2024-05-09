P, Q = map(int, input().split())

for i in range(1, P+1):
    for j in range(1, Q+1):
        if P%i == 0 and Q%j == 0:
            print(i, j)