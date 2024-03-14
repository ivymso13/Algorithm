idx = 1
while True:
    n = int(input())
    if n == 0:
        break

    n = n*3
    f = n%2

    ret = (((n+f)//2)*3)//9

    print(str(idx) + ".", "odd" if f%2==1 else "even", ret)
    idx += 1