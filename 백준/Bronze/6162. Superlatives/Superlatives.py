N = int(input())
for i in range(1, N+1):
    a, b = map(int, input().split())

    print(f"Data Set {i}:")
    if a <= b:
        print(f"no drought")
    else:
        ret = "drought"
        a /= b

        while a > 5:
            ret = "mega " + ret
            a /= 5

        print(ret)

    print()

