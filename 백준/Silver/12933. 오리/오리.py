inp = input()
check = [0]*len(inp)

quack = "quack"
cnt = 0
word = len(inp)

while True:
    f = qi = 0
    tmp = []
    for idx in range(len(inp)):
        if check[idx] > 0:
            continue

        if quack[qi] == inp[idx]:
            qi += 1
            tmp.append(idx)

            if qi == len(quack):
                for t in tmp:
                    check[t] = 1
                    word -= 1

                tmp = []
                qi = 0
                f = 1

    if f == 0:
        break
    else:
        cnt += 1

print(cnt if word == 0 else -1)