T = int(input())

for _ in range(T):
    inp = input()
    
    cnt = 0
    for i in range(0, len(inp), 8):
        tmp = inp[i:i+8]

        one = 0
        for val in tmp:
            one += int(val)

        cnt += one%2
    
    print(cnt)