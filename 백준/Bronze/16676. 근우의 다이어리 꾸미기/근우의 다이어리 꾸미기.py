N = int(input())

cnt, f = 0, 1

while f <= N:
    cnt += 1
    f = f*10 + 1

if N == 0:
    print(1)
else:
    print(cnt)