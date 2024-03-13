val = [[4.5, 150, 200], [6.0, 300, 500], [5.0, 200, 300]]
name = ["Wide Receiver", "Lineman", "Quarterback"]

while True:
    sp, w, st = input().split()
    if sp == w == st == "0":
        break

    sp = float(sp)
    w, st = int(w), int(st)

    ret = []
    for i in range(3):
        if sp<=val[i][0] and w>=val[i][1] and st>=val[i][2]:
            ret.append(name[i])

    if len(ret) == 0:
        print("No positions")
    else:
        for n in ret:
            print(n, end=" ")
        print()