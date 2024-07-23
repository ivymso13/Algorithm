N = int(input())

ed = 0
inp = []
for i in range(N):
    d, cow, m = input().split()
    d, m = int(d), int(m)
    ed = max(ed, d)

    inp.append([d, cow, m])
inp.sort(key=lambda x: x[0])

vmax = []
milk = [7, 7, 7]
cowIdx = {"Bessie":0, "Elsie":1, "Mildred":2}

idx, ret = 0, 0
for day in range(0, ed+1):
    if inp[idx][0] != day:
        continue

    while idx<N and inp[idx][0] == day:
        milk[cowIdx[inp[idx][1]]] += inp[idx][2]
        idx += 1

    cur = [0]
    for j in range(1, 3):
        if milk[cur[-1]] < milk[j]:
            cur = [j]
        elif milk[cur[-1]] == milk[j]:
            cur.append(j)
    
    if vmax != cur:
        vmax[:] = cur[:]
        ret += 1

print(ret)