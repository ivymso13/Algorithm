N = int(input())

cnt = 0
for _ in range(N):
    inp = list(input())

    cnt += 1
    for j in range(len(inp)-1):
        if inp[j]+inp[j+1] == "CD":
            cnt -= 1
            break

print(cnt)