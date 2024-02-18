N, B = map(int, input().split())

inp = []
for _ in range(N):
    p, s = map(int, input().split())

    inp.append([p+s, p])

inp.sort()

ret = 0
for i in range(N):
    tot = inp[i][0] - (inp[i][1] - inp[i][1]//2)
    if tot > B:
        continue
    
    cnt = 1
    for j in range(N):
        if i == j:
            continue

        elif tot + inp[j][0] > B:
            break

        else:
            tot += inp[j][0]
            cnt += 1

    ret = max(ret, cnt)

print(ret)