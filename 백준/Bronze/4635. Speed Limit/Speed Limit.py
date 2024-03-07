while True:
    n = int(input())
    if n == -1:
        break

    bef, ret = 0, 0
    for i in range(n):
        sp, h = map(int, input().split())

        ret += sp * (h-bef)
        bef = h

    print(ret, "miles")