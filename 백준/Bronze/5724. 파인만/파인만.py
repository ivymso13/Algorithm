while True:
    n = int(input())
    if n == 0:
        break
    
    ret = 0
    for i in range(1, n+1):
        ret += (n - i + 1)*(n - i + 1)

    print(ret)