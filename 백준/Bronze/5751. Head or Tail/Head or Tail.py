while True:
    N = int(input())
    if N == 0:
        break
    inp = list(map(int, input().split()))

    ret = [0, 0]
    for idx in inp:
        ret[idx] += 1

    print(f"Mary won {ret[0]} times and John won {ret[1]} times")