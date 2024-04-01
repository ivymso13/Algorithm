T = int(input())

for _ in range(T):
    n = int(input())

    for i in range(n):
        if i == 0 or i == n-1:
            print("#"*n)
        else:
            print("#" + "J"*(n-2) + "#")

    print()