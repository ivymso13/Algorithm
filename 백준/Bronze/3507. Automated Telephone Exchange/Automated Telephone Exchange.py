N = int(input())

if N-99 >= 100:
    print(0)
else :
    # max: 99 / min: N-99
    print(99 - (N - 99) + 1)