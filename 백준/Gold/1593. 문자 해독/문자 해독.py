lenW, lenG = map(int, input().split())
W = list(input())
G = list(input())

cnt = 0
findW = [0]*52
findG = [0]*52

alpha = {}
for i in range(26):
    alpha[chr(i+65)] = i
    alpha[chr(i+97)] = i+26


def check():
    for i in range(52):
        if findW[i] != findG[i]:
            return 0
    return 1


for i in range(lenG):
    if i < lenW:
        findW[alpha[W[i]]] += 1
        findG[alpha[G[i]]] += 1

        if i == lenW-1:
            cnt += check()

    else:
        findG[alpha[G[i]]] += 1
        findG[alpha[G[i-lenW]]] -= 1

        cnt += check()

print(cnt)