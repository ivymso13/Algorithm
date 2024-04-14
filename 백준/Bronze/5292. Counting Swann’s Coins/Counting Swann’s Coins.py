N = int(input())

idx = 1
while idx <= N:
    ret = ""

    if idx%3 == 0:
        ret += "Dead"
    if idx%5 == 0:
        ret += "Man"

    if ret == "":
        print(idx, end= " ")
    else:
        print(ret)

    idx += 1