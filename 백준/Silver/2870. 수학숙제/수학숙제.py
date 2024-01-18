N = int(input())

inp = []
for _ in range(N):
    s = input()

    tmp = ""
    for c in s:
        if c in "0123456789":
            tmp += c
        else:
            if tmp == "":
                continue
            else:
                inp.append(int(tmp))
                tmp = ""

    if tmp != "":
        inp.append(int(tmp))

inp.sort()
for val in inp:
    print(val)