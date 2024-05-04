N, M = map(int, input().split())

inp = []
for i in range(N):
    a, b = map(int, input().split())

    if i == 0:
        inp.append([a, b])
    else:
        inp.append([inp[-1][0] + a, b])

spMax, d = 0, 0
idx = 0
for i in range(M):
    km, sp = map(int, input().split())

    d += km
    while idx<N:
        spMax = max(spMax, sp-inp[idx][1])

        if inp[idx][0] > d:
            break
        elif inp[idx][0] == d:
            idx += 1
            break
        else:
            idx += 1

print(spMax)