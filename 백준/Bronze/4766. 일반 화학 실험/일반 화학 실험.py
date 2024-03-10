INF = 999

bef = INF
while True:
    cur = float(input())
    if cur == INF:
        break

    if bef != INF:
        print(f"{cur-bef:.2f}")

    bef = cur