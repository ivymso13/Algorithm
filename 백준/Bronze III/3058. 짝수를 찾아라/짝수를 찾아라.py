T = int(input())
for _ in range(T):
    inp = list(map(int, input().split()))
    tot = 0
    vmin = 100
    for val in inp:
        if val%2 == 0:
            tot += val
            vmin = min(vmin, val)
            
    print(tot, vmin)