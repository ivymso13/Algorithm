inp = input()

l = len(inp)
ret = [['.']*(l*4+1) for _ in range(5)]


def draw(idx, val, c):
    global ret

    for i in range(5):
        # 1, 5번째 줄
        if abs(i-2) == 2:
            for j in range(5):
                if j == 2:
                    ret[i][idx+j] = c
        # 2, 4번째 줄
        elif abs(i-2) == 1:
            for j in range(5):
                if j%2 == 1:
                    ret[i][idx+j] = c
        # 3번째 줄
        else:
            if ret[i][idx] in ['.', '#']:
                ret[i][idx] = ret[i][idx+4] = c
            else:
                ret[i][idx+4] = c

            ret[i][idx+2] = val


for j in range(l):
    if j%3==2:
        draw(j*4, inp[j], '*')
    else:
        draw(j*4, inp[j], '#')

for i in range(5):
    for j in range(l*4+1):
        print(ret[i][j], end='')
    print()