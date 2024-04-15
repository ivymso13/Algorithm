price = [35034, 23090, 19055, 12530, 18090]

n = int(input())
for _ in range(n):
    inp = list(map(int, input().split()))

    tot = 0
    for i in range(5):
        tot += price[i]*inp[i]

    print(f"${tot//100}.{tot%100:02d}")