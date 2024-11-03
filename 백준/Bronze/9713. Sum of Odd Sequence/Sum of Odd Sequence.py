T = int(input())
for i in range(T):
    N = int(input())

    ans = 0
    for i in range(1, N+1, 2):
        ans += i

    print(ans)