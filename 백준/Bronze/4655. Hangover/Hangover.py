while True:
    inp = float(input())
    if inp == 0:
        break

    idx = 1
    sum = 0
    while sum < inp:
        sum += 1/(idx+1)
        idx += 1

    print(f"{idx-1} card(s)")