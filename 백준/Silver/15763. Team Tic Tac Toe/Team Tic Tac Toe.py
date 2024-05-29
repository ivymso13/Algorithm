inp = []

for i in range(3):
    t = list(input())
    inp.append(t)

def sv(check):
    ret = ['', []]
    for i in range(26):
        if check[i] == 0:
            continue
        elif check[i] == 3:
            ret[0] = chr(i+ord('A'))
        else:
            ret[1].append(chr(i+ord('A')))

    if len(ret[1]) == 3:
        ret[1] = []
    else:
        ret[1].sort()
        ret[1] = tuple(ret[1])
    
    return ret


ret = [set(), set()]
for i in range(3):
    alpha = [[0] * 26 for i in range(2)]
    for j in range(3):
        alpha[0][ord(inp[i][j]) - ord('A')] += 1
        alpha[1][ord(inp[j][i]) - ord('A')] += 1

    for j in range(2):
        cnt = sv(alpha[j])

        for k in range(2):
            if cnt[k]:
                ret[k].add(cnt[k])


alpha = [[0] * 26 for i in range(2)]
for i in range(3):
    alpha[0][ord(inp[i][i]) - ord('A')] += 1
    alpha[1][ord(inp[2 - i][i]) - ord('A')] += 1

for j in range(2):
    cnt = sv(alpha[j])

    for k in range(2):
        if cnt[k]:
            ret[k].add(cnt[k])

for val in ret:
    print(len(val))