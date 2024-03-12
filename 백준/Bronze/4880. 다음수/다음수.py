while True:
    a0, a1, a2 = map(int, input().split())
    if a0==0 and a1==0 and a2==0:
        break

    if a2-a1 == a1-a0:
        print(f"AP {a2 + (a2-a1)}")
    else:
        print(f"GP {a2 * (a2//a1)}")