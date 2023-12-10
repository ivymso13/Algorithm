T = int(input())

for _ in range(T):
    inp = list(input().split())

    num = float(inp[0])
    for c in range(1, len(inp)):
        if inp[c] == '@':
            num *= 3
        elif inp[c] == '%':
            num += 5
        else:
            num -= 7

    print(f"{num:.2f}")