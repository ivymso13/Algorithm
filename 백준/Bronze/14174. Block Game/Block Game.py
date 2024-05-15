N = int(input())

alpha = [0]*26
for i in range(N):
    inp = list(input().split())

    cnt = [0]*26
    for j in range(2):
        tmp = [0]*26
        for k in inp[j]:
            tmp[ord(k)-97] += 1

        for k in range(26):
            cnt[k] = max(cnt[k], tmp[k])

    for k in range(26):
        alpha[k] += cnt[k]

for val in alpha:
    print(val)