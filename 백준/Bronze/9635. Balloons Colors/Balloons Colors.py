T = int(input())
for i in range(T):
    N, X, Y = input().split()
    num = input().split()

    if num[0] == X and num[-1] == Y:
        print("BOTH")
    elif num[0] == X:
        print("EASY")
    elif num[-1] == Y:
        print("HARD")
    else:
        print("OKAY")