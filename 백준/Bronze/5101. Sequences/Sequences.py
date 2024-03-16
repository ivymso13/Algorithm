while True:
    s, d, x = map(int, input().split())
    if s == d == x == 0:
        break

    if d>0 and s>x:
        print("X")
    elif d<0 and s<x:
        print("X")
    else:
        if abs(x-s)%abs(d) > 0:
            print("X")
        else:
            print((x-s)//d + 1)