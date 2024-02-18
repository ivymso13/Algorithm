N, B = map(int, input().split())

inp = []
for _ in range(N):
    p, s = map(int, input().split())

    inp.append([p+s, p//2+s])

inp.sort()

ret = 0
for i in range(N):
    tot = inp[i][1]
    if tot > B:
        continue
    
    cnt = 1
    for j in range(N):
        if i == j:
            continue
        elif tot + inp[j][0] > B:
            break

        tot += inp[j][0]
        cnt += 1

    ret = max(ret, cnt)

print(ret)