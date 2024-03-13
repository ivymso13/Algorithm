while True:
    inp = list(map(int, input().split()))
    if inp == [0]*6:
        break

    ret = (sum(inp) - min(inp) - max(inp))/4
    print(f"{ret:g}")