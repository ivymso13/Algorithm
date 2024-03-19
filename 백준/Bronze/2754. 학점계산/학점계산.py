inp = input()

if inp == "F":
    print("0.0")
else:
    a, b = inp[0], inp[-1]

    score = (ord("D") - ord(a)) + 1

    if b == "+":
        score += 0.3
    elif b == "-":
        score -= 0.3

    print(f"{score:.1f}")