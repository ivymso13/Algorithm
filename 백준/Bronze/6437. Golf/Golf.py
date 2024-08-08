idx = 1
while True:
    a, b = map(int, input().split())
    if a == b == 0:
        break

    print(f"Hole #{idx}")
    if b == 1:
        print("Hole-in-one.\n")
    elif a-b == 3:
        print("Double eagle.\n")
    elif a-b == 2:
        print("Eagle.\n")
    elif a-b == 1:
        print("Birdie.\n")
    elif a-b == 0:
        print("Par.\n")
    elif a-b == -1:
        print("Bogey.\n")
    elif a-b < -1:
        print("Double Bogey.\n")

    idx += 1