N = int(input())

inp = []
for _ in range(N):
    t = list(input())
    inp.append(t)

ret = 0
for i in range(N):
    cnt = 0
    for j in range(N):
        if i == j:
            continue
        elif inp[i][j] == "Y":
            cnt += 1
        else:
            for idx in range(N):
                if inp[i][idx] == "N":
                    continue
                elif inp[i][idx] == inp[j][idx]:
                    cnt += 1
                    break


    ret = max(ret, cnt)

print(ret)