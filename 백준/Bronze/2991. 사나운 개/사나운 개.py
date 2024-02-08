a, b, c, d = map(int, input().split())
inp = list(map(int, input().split()))

for i in range(3):
    inp[i] -= 1
    cnt = 0

    if inp[i]%(a+b) < a:
        cnt += 1
    if inp[i]%(c+d) < c:
        cnt += 1

    print(cnt)