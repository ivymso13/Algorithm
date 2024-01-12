T = int(input())
for _ in range(T):
    J, N = map(int, input().split())

    inp = []
    for __ in range(N):
        r, c = map(int, input().split())
        inp.append(r*c)
    inp.sort()

    cnt = 0
    while J>0:
        cnt += 1
        J -= inp[-cnt]

    print(cnt)