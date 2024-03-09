T = int(input())

# [R, S, P] = [0, 1, 2]
check = {"R":0, "S":1, "P":2}

for _ in range(T):
    n = int(input())

    winA, winB = 0, 0
    for i in range(n):
        a, b = input().split()

        if check[a] == check[b]:
            continue
        elif (check[a]+1)%3 == check[b]:
            winA += 1
        else:
            winB += 1

    if winA == winB:
        print("TIE")
    elif winA > winB:
        print("Player 1")
    else:
        print("Player 2")

