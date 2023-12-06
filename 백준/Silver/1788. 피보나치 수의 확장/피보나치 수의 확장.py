n = int(input())
MOD = 1000000000

if n > 0:
    a = 0
    b = 1
    for i in range(1, n):
        a, b = b, (a+b)%MOD

    print(f"{1}\n{b}")

elif n == 0:
    print(f"0\n0");

else:
    a = [0, 0]
    b = [1, 1]
    for i in range(abs(n)):
        if a[1] > 0:
            if b[1] > 0:
                ret = b[0]-a[0]
            else:
                ret = -b[0]-a[0]
        else:
            if b[1] > 0:
                ret = b[0]+a[0]
            else:
                ret = -b[0]+a[0]

        b = a
        if ret > 0:
            a = [ret%MOD, 1]
        elif ret < 0:
            a = [abs(ret)%MOD, -1]
        else:
            a = [0, 0]

    print(f"{a[1]}\n{a[0]}")