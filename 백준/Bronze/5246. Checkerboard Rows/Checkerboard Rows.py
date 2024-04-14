T = int(input())

for _ in range(T):
    inp = list(map(int, input().split()))

    ret = 0
    check = [0]*9
    for i in range(1, inp[0]*2+1, 2):
        col, row = inp[i], inp[i+1]
        check[row] += 1

        ret = max(ret, check[row])

    print(ret)