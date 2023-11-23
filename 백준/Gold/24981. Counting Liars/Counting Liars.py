N = int(input())

inp = []
for i in range(N):
    a, b = input().split()
    inp.append([a, int(b)])

def isIn(num, q):
    if q[0] == "G":
        return num >= q[1]
    else:
        return num <= q[1]

cnt = N
for i in range(N):
    d = inp[i][1]
    tmp = 0

    for j in range(N):
        if not isIn(d, inp[j]):
            tmp += 1

    cnt = min(cnt, tmp)

print(cnt)