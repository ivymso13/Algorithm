T = int(input())
for i in range(1, T+1):
    a, b = map(int, input().split())

    idx, cnt = 1, 0
    while idx**3 <= b:
        cnt += 1 if a <= idx**3 else 0
        idx += 1

    print(f"Case #{i}: {cnt}")