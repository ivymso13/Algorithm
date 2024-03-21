N = int(input())

for _ in range(N):
    t = int(input())

    val = []
    for i in range(1, (t+1)//2):
        if i != t-i:
            val.append([i, t-i])

    print(f"Pairs for {t}: ", end="")
    if len(val) > 0:
        for i in range(len(val)-1):
            print(f"{val[i][0]} {val[i][1]}, ", end="")
        print(f"{val[-1][0]} {val[-1][1]}", end="")
    print()