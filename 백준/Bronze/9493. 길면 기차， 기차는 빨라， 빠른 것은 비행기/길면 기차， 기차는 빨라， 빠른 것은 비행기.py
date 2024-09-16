while True:
    m, a, b = map(int, input().split())
    if m == a == b == 0:
        break

    t = (m/a*3600 - m/b*3600)*10
    t = int(t//10 + (1 if t%10 >= 5 else 0))

    print(f"{t//3600}:{t//60%60:02d}:{t%60:02d}")