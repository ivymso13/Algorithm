inp = []
while True:
    t = input()
    if t == '=':
        break
    else:
        inp.append(t)

ret = int(inp[0])
for i in range(2, len(inp), 2):
    if inp[i-1] == '+':
        ret += int(inp[i])
    elif inp[i-1] == '-':
        ret -= int(inp[i])
    elif inp[i-1] == '*':
        ret *= int(inp[i])
    else:
        ret //= int(inp[i])

print(ret)