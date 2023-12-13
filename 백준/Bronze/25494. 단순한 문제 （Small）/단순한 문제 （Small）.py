T = int(input())

for _ in range(T):
    a, b, c = map(int, input().split())

    cnt = 0
    for x in range(1, a+1):
        for y in range(1, b+1):
            for z in range(1, c+1):
                if x%y == y%z and y%z == z%x:
                    cnt = cnt+1

    print(cnt)