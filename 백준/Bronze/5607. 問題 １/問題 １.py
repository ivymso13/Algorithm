N = int(input())

retA, retB = 0, 0
for _ in range(N):
    a, b = map(int, input().split())

    if a > b:
        retA += (a+b)
    elif a < b:
        retB += (a+b)
    else:
        retA += a
        retB += b

print(retA, retB)