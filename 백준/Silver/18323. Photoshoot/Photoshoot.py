N = int(input())
inp = list(map(int, input().split()))

for i in range(1, inp[0]):
    check = [1] + [0]*N

    num = [i]
    check[i] = 1
    for j in range(N-1):
        t = inp[j]-num[j]

        if t > N or check[t] > 0:
            break
        else:
            check[t] = 1
            num.append(t)

    if len(num) == N:
        break

for val in num:
    print(val, end=" ")