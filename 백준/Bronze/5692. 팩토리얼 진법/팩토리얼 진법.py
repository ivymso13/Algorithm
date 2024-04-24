while True:
    n = input()
    if n == "0":
        break

    n = list(map(int, n))
    n.reverse()

    ret, f = 0, 1
    for i in range(len(n)):
        f *= (i+1)
        ret += n[i] * f

    print(ret)