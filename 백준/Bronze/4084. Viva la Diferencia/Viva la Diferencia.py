ed = [0]*4
while True:
    inp = list(map(int, input().split()))
    if inp == ed:
        break

    cnt = 0
    while True:
        if inp[0] == inp[1] and inp[1] == inp[2] and inp[2] == inp[3]:
            break

        tmp = []
        for i in range(4):
            tmp.append(abs(inp[i] - inp[(i+1)%4]))

        inp[:] = tmp[:]
        cnt += 1

    print(cnt)