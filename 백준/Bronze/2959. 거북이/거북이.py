inp = list(map(int, input().split()))
inp.sort()

print(min(inp[0], inp[1]) * min(inp[2], inp[3]))