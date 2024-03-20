while True:
    t1, t2 = input().split()
    if t1 == t2 == "00:00":
        break

    h1, m1 = map(int, t1.split(":"))
    h2, m2 = map(int, t2.split(":"))

    M = (m1 + m2)%60
    H = (h1 + h2 + (m1 + m2)//60)

    if H < 24:
        print(f"{'{:02}'.format(H%24)}:{'{:02}'.format(M)}")
    else:
        print(f"{'{:02}'.format(H%24)}:{'{:02}'.format(M)} +{H//24}")