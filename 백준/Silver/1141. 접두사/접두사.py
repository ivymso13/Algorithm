N = int(input())

inp = []
for _ in range(N):
    t = input()
    inp.append(t)

inp.sort()

cnt = N
for i in range(N):
    l = len(inp[i])
    for j in range(i+1, N):
        if inp[i] == inp[j][:l]:
            cnt -= 1
            break

print(cnt)