T = int(input())
for i in range(T):
    id = input()
    tot = sum(map(int, list(id)))

    ans = (tot + int(id)%1000*10)

    if ans < 1000:
        ans += 1000
    elif ans > 9999:
        ans %= 10000

    print(f"{ans:04d}")