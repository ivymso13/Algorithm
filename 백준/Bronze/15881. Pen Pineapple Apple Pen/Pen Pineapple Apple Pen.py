N = int(input())
inp = list(input())

ppap = list("pPAp")
pi = cnt = 0
for i in range(N):
    if inp[i] == ppap[pi]:
        pi += 1
    else:
        pi = 0
        if inp[i] == ppap[pi]:
            pi += 1

    if pi == 4:
        pi = 0
        cnt += 1

print(cnt)