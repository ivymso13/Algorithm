N = int(input())

for _ in range(N):
    inp = list(input())

    inp[0] = inp[0].upper()
    print("".join(inp))