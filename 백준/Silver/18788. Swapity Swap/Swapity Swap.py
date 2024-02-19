N, K = map(int, input().split())

rev = []
for i in range(2):
    a, b = map(int, input().split())
    rev.append([a-1, b-1])

num = []
mv = []
for i in range(N):
    num.append(i)
    mv.append(i)

s = []
std = num[:]
while True:
    s.append(num[:])
    for j in range(2):
        l = rev[j][0]
        r = rev[j][1]

        while l<=r:
            num[l], num[r] = num[r], num[l]

            l += 1
            r -= 1

    if std == num:
        break

for i in range(N):
    mv[s[1][i]] = i

def check(idx, p):
    if mv[idx] == p:
        return 1
    else:
        return check(mv[idx], p) + 1


cnt = [0]*N
for i in range(N):
    cnt[i] = check(i, i)

for i in range(N):
    print(s[K%cnt[i]][i] + 1)
