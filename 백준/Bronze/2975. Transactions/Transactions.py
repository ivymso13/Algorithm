while True:
    a, c, d = input().split()
    a, d = int(a), int(d)

    if a == 0 and c == "W" and d == 0:
        break

    if c == "W":
        a -= d
    else:
        a += d

    print(a if a >= -200 else "Not allowed")
