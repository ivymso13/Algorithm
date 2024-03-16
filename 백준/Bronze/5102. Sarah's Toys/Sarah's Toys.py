while True:
    n, m = map(int, input().split())
    if n == m == 0:
        break

    if n-m == 1:
        print(0, 0)
    else:
        if (n-m)%2 == 0:
            print((n-m)//2, 0)
        else:
            print((n-m)//2-1, 1)