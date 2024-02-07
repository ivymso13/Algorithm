inp = list(map(int, input().split()))

tot = 1
for t in inp:
    tot *= t

for i in range(1, tot+1):
    cnt = 0
    for num in inp:
        cnt += 1 if i%num == 0 else 0

    if cnt >= 3:
        print(i)
        break