
while True:
    inp = list(map(int, input().split()))
    if inp[0] == 0 and inp[1] == 0:
        break
    elif inp[0] < inp[1]:
        inp[0], inp[1] = inp[1], inp[0]

    cnt = c = 0
    while inp[0] > 0:
        a = inp[0]%10
        b = inp[1]%10

        if a+b+c >= 10:
            cnt += 1
            c = 1
        else:
            c = 0

        inp[0] //= 10
        inp[1] //= 10

    print(cnt)