T = int(input())
for i in range(T):
    h, m = map(int, input().split())

    calc = (h*60 + m - 45) + 60*24

    print(f"Case #{i+1}: {calc//60%24} {calc%60}")