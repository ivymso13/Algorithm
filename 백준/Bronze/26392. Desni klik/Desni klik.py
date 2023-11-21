N, R, C = map(int, input().split())

for _ in range(N):
    vmax = 0
    vmin = R
    for r in range(R, 0, -1):
        t = list(input())

        f = 0
        for c in t:
            if c == '#':
                f = 1
                break

        if f == 1:
            vmax = max(vmax, r)
            vmin = min(vmin, r)

    print(vmax-vmin)