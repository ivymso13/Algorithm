U, N = map(int, input().split())

money = [[] for _ in range(U+1)]
for i in range(N):
    name, m = input().split()
    m = int(m)
    money[m].append([name, i])

cnt, ret = N, "";
for i in range(1, U+1):
    if len(money[i]) == 0:
        continue
    
    if cnt > len(money[i]):
        cnt = len(money[i])
        ret = [money[i][0][0], i]

print(ret[0], ret[1])