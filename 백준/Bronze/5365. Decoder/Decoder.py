N = int(input())
inp = input().split()

ret = inp[0][0]
for i in range(1, N):
    bef = len(inp[i-1])

    if bef > len(inp[i]):
        ret += " "
    else:
        ret += inp[i][bef-1]

print(ret)