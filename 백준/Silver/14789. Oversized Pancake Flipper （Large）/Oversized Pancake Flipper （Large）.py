T = int(input())

for idx in range(T):
    inp, K = input().split()
    inp = list(inp)
    K = int(K)

    cnt = 0
    for i in range(0, len(inp)-K+1):
        if inp[i] == '-':
            for j in range(K):
                inp[i+j] = '+' if inp[i+j] == '-' else '-'
            cnt += 1


    print(f"Case #{idx+1}: ", end="")

    if '-' in inp[:]:
        print("IMPOSSIBLE")
    else:
        print(cnt)